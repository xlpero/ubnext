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
  'required context' => new ctools_context_required(t('Document List'), 'entity:node'),
  'edit form' => 'ubn_nuxeo_nuxeo_search_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_nuxeo_nuxeo_search_content_type_settings($form, &$form_state) {
  return $form;
}

function _ubn_nuxeo_search($document_list) {
  $query_params = _ubn_nuxeo_get_query_params();

  //var_dump($document_list);
  $search_term_key_value = '';

  if (!empty($search_params['query'])) {
    $search_term_key_value = '&queryParams='.$search_params['query'];
  }

  // Headers to send to Nuxeo server
  $headers = array(
    'X-NXDocumentProperties' => '*',
  );

  // Options used in http request
  $options = array(
    'headers' => $headers,
  );

  $username = (isset($_SERVER['DMS_API_USERNAME']) ?$_SERVER['DMS_API_USERNAME']  : 'TheUsername' );
  $password = (isset($_SERVER['DMS_API_PASSWORD']) ?$_SERVER['DMS_API_PASSWORD']  : 'ThePassword' );
  $protocol = (isset($_SERVER['DMS_API_PROTOCOL']) ?$_SERVER['DMS_API_PROTOCOL']  : 'https' );
  $base_url = (isset($_SERVER['DMS_API_BASE_URL']) ?$_SERVER['DMS_API_BASE_URL']  : 'doku.ub.gu.se/nuxeo/api/v1/' );
  $end_point = (isset($_SERVER['DMS_API_EP_QUERY']) ?$_SERVER['DMS_API_EP_QUERY']  : 'query/' );

  // Take these from Content type.
  $page_size = $document_list->field_doclist_page_size->value();
  $page_size_key_value = '&pageSize='.$page_size;

  //var_dump($query_params['page']);
  if (!empty($query_params['page'])) {
    $current_page = '&currentPageIndex=' . $query_params['page'];
  }
  else {
    $current_page = '';
  }



  // Take ub_doctypes and ub_orgs from Taxonomy terms in Content type.
  $ub_doctypes = array();

  var_dump($document_list->field_doclist_doctypes->value());
  foreach ($document_list->field_doclist_doctypes->value() as $value) {
    $ub_doctypes[] = $value;
  }

  //var_dump($ub_doctypes);

  $ub_orgs = array();

  #var_dump($document_list->field_doclist_orgs->value());
  foreach ($document_list->field_doclist_orgs->value() as $value) {
    $ub_orgs[] = $value;
  }
  //var_dump($ub_orgs);

  if (!empty($ub_doctypes)) {
    $ub_doctype_str = " AND ub:doctypes IN " . _ubn_nuxeo_make_string_from_array($ub_doctypes);
  }
  else {
    $ub_doctype_str = "";
  }

  if (!empty($ub_orgs)) {
    $ub_organisation_str = " AND ub:orgs IN " . _ubn_nuxeo_make_string_from_array($ub_orgs);
  }
  else {
    $ub_organisation_str = '';
  }

  $nxql_string = urlencode("SELECT * FROM Document WHERE ecm:currentLifeCycleState <> 'deleted'  AND ecm:primaryType <> 'Folder'"  . $ub_doctype_str . $ub_organisation_str . " AND dc:title NOT LIKE '._%'");

  $url = $protocol."://".$username.":".$password."@".$base_url.$end_point."?query=" . $nxql_string . $page_size_key_value . $current_page;

  #var_dump($url);
  $response = drupal_http_request($url, $options);

  if (!empty($response->error)) {
    return "";
  }
  $json = $response->data;
  //var_dump($json);
  return json_decode($json, true);
}

function _ubn_nuxeo_make_string_from_array($arr) {

  $tempstr = "(";

  foreach ($arr as $item) {
    $tempstr .= "'" . $item . "',";
  }
  $tempstr = trim($tempstr, ",");
  $tempstr .= ")";

  return $tempstr;
}



function _ubn_nuxeo_get_query_params() {

  $params = drupal_get_query_parameters();
  return $params;

};


/**
 * Render callback.
 */
function ubn_nuxeo_nuxeo_search_content_type_render($subtype, $conf, $panel_args, $context) {

  if (empty($context->data)) {
    return;
  }

  $wrapper = entity_metadata_wrapper('node', $context->data);
  $resultlist = _ubn_nuxeo_search($wrapper);
  #var_dump($resultlist);

  $block = new stdClass();
  $block->title = t('Nuxeo search');
  $block->content = slate_render('nuxeo_search', array('resultlist' => $resultlist));

  return $block;
}
