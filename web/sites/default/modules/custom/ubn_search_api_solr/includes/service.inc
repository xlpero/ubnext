<?php
/**
 * Search service class using Solr server.
 */
class UBNSearchApiSolrService extends SearchApiSolrService  {
  /**
   * Implements SearchApiServiceInterface::__construct().
   *
   * The default implementation sets $this->server and $this->options.
   */
  public function __construct(SearchApiServer $server) {
    parent::__construct($server);
    $this->connection_class = 'UBNSearchApiSolrConnection';
  }

  /**
   * Extract results from a Solr response.
   *
   * @param object $response
   *   A HTTP response object.
   *
   * @return array
   *   An array with two keys:
   *   - result count: The number of total results.
   *   - results: An array of search results, as specified by
   *     SearchApiQueryInterface::execute().
   */
  protected function extractResults(SearchApiQueryInterface $query, $response) {
    //TODO: set query option
    //
    $spellcheck = FALSE;
    if($query->getOption('search_api_spellcheck')) {
      $query->setOption('search_api_spellcheck', FALSE);
      $spellcheck = TRUE;
    }
    $results = parent::extractResults($query, $response);

    if($spellcheck && module_exists('search_api_spellcheck')) {
      // Check for spellcheck suggestions.
      $results['search_api_spellcheck'] = new UBNSearchApiSpellcheckSolr($response);
    }
    return $results;
  }
}
