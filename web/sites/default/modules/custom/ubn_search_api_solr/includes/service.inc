<?php

/**
 * Search service class using Solr server.
 */
class UBNSearchApiSolrService extends SearchApiSolrService {

  public function getAutocompleteSuggestions(SearchApiQueryInterface $query, SearchApiAutocompleteSearch $search, $incomplete_key, $user_input, $suggester_configuration = NULL) {
    $suggestions = array();
    // Reset request handler
    $this->request_handler = NULL;
    // Turn inputs to lower case, otherwise we get case sensivity problems.
    //TODO: no!?
    $incomp = drupal_strtolower($incomplete_key);

    $index = $query->getIndex();

    // Set searched fields
    $options = $query->getOptions();
    // overriding this
    //$index_id = $this->getIndexId($index->machine_name);
    //TODO: try??
    //TODO: properer parsing
    $suggester_dictionaries = array_filter(
      array_map(
        'trim',
        explode(
          "\n",
          $suggester_configuration['suggester_dictionaries']
        )
      )
    );
    //TODO: fix bold when fuzzy
    //$suggester_dictionaries = array('databases_fuzzy');
    $params = array(
      'suggest.q' => $user_input,
      'suggest.dictionary' => $suggester_dictionaries,
    );
    $this->connect();
    $response = $this->solr->makeServletRequest(
      $suggester_configuration['suggester_path'],
      $params
    );

    foreach($suggester_dictionaries as $dictionary) {
      if(isset($response->suggest->{$dictionary}->{$user_input})) {
        $dictionary_suggestions = $response->suggest->{$dictionary}->{$user_input};
        if(!empty($dictionary_suggestions->suggestions)) {
          foreach($dictionary_suggestions->suggestions as $suggestion) {
            $suggestions[] = array(
              'keys' => strip_tags($suggestion->term),
              'render' => $suggestion->term,
            );
          }
        }
      }
    }
    //TODO: getIndexId and not machine_name, refactor in other places? Or change
    //here?
    //Include search_api_solr_site_hash() in autocomplete fields names? nahh..
    drupal_alter('search_api_solr_autocomplete_suggestions', $suggestions, $alter_data);
    return $suggestions;
  }
}
