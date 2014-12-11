<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Nuxeo: Search'),
  'description' => t('Search filesystem on Nuxeo server.'),
  'category' => 'UBNext',
  /*'required context' => new ctools_context_required(t('Library'), 'entity:node'),*/
  'edit form' => 'ubn_nuxeo_nuxeo_search_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_nuxeo_nuxeo_search_content_type_settings($form, &$form_state) {
  return $form;
}

function _ubn_nuxeo_search($search_params = array()) {

  $search_term_key_value = '';

  if (!empty($search_params['search_term'])) {
    $search_term_key_value = '&queryParams='.$search_params['search_term'];
  }

  $page_size_key_value = '';

  if (!empty($search_params['page_size'])) {
    $page_size_key_value = '&pageSize='.$search_params['page_size'];
  }

  // Headers to send to Nuxeo server
  $headers = array(
    'X-NXDocumentProperties' => '*',
  );

  // Options used in http request
  $options = array(
    'headers' => $headers,
  );

  $options[] =

  $response = drupal_http_request('https://jupp:jupp@doku.ub.gu.se/nuxeo/api/v1/query/CoreQueryDocumentPageProvider?query=SELECT+*+FROM+Document+WHERE+ecm%3Afulltext+%3D+%3F+AND+ecm%3AprimaryType+%3D+%27File%27+AND+ecm%3AcurrentLifeCycleState+%3C%3E+%27deleted%27+AND+ecm%3AisLatestVersion+%3D+1'.$search_term_key_value.$page_size_key_value, $options);
  //var_dump($response);

  if (!empty($response->error)) {
    return "";
  }

  $json = $response->data;
  return json_decode($json, true);
}

/**
 * @param $results
 * @return array
 */
function _ubn_nuxeo_get_resultlist($results) {
  //var_dump($results);
  //var_dump($results['entries']);

  $data = array();

  foreach ($results['entries'] as $entry) {
    $data[] = $entry;
    var_dump($entry['properties']);
    //$data[] = array(
    //  'filename' => $entry['title'],
    //  'url' => $entry['contextParameters']['documentURL'],
    //  'author' => $entry['uid'],
    //  'size' => $entry['entity-type'],
    //);
  }
  return $data;
}

function _ubn_nuxeo_get_query_params() {
  $params = drupal_get_query_parameters();
  //var_dump($params);
  return $params;
};

/**
 * Render callback.
 */
function ubn_nuxeo_nuxeo_search_content_type_render($subtype, $conf, $panel_args, $context) {
  $search_params = _ubn_nuxeo_get_query_params();

  $resultlist = _ubn_nuxeo_get_resultlist(_ubn_nuxeo_search($search_params));
  //var_dump($resultlist);
  
  $block = new stdClass();
  $block->title = t('Nuxeo search');
  $block->content = slate_render('nuxeo_search', array('resultlist' => $resultlist));

  return $block;
}
