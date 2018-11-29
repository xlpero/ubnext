<?php
/**
 * Represents a Solr server resource.
 *
 * Contains methods for pinging, adding, deleting, committing, optimizing and
 * searching.
 */
class UBNSearchApiSolrConnection extends SearchApiSolrConnection  {
  /**
   * {@inheritdoc}
   */
  public function search($query = NULL, array $params = array(), $method = 'GET') {
    $response = parent::search($query, $params, $method);
    /*
    if(!empty($response->response->numFound)) {
      unset($response->spellcheck);
    }
    else if(isset($response->spellcheck->suggestions)) {
      foreach (get_object_vars($response->spellcheck->suggestions) as $keyword => $suggestion) {
        if(isset($suggestion->suggestion[0])) {
          $query = str_replace($keyword, $suggestion->suggestion[0], $query);
        }
        //TODO: unset all other suggestions? Yes probably
      }
      $first_response_suggestions = $response->spellcheck;
      $response = parent::search($query, $params, $method);
      $response->spellcheck = $first_response_suggestions;
    }
    */
    return $response;
  }
}
