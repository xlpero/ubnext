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

function _ubn_nuxeo_search($search_params = array()) {

  $search_term_key_value = '';

  if (!empty($search_params['query'])) {
    $search_term_key_value = '&queryParams='.$search_params['query'];
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

  $user_name = 'Administrator';
  $password = 'Administrator';
  $base_url = "https://".$user_name.":".$password."@doku.ub.gu.se/nuxeo/api/v1/query/CoreQueryDocumentPageProvider?query=";
  // to be set on content type instance... 
  $ub_doctype = array("minnesanteckning");
  $ub_organisation = array('digit_top/digit_team_utveckling', 'digit');

  if (!empty($ub_doctype)) {
    $ub_doctype_str = " AND ub:doctypes IN " . _ubn_nuxeo_make_string_from_array($ub_doctype);
  }
  else {
    $ub_doctype_str = "";
  }

  if (!empty($ub_organisation)) {
    $ub_organisation_str = " AND ub:orgs IN " . _ubn_nuxeo_make_string_from_array($ub_organisation);
  }
  else {
    $ub_organisation_str = '';
  }
  var_dump($ub_doctype_str);

  $nxql_string = urlencode("SELECT * FROM Document WHERE ecm:currentLifeCycleState <> 'deleted'  AND ecm:primaryType <> 'Folder'"  . $ub_doctype_str . $ub_organisation_str);

  $url = $base_url . $nxql_string . "&pageSize=10";

  //var_dump($url);
  $response = drupal_http_request($url, $options);

  //var_dump($response);

  if (!empty($response->error)) {
    return "";
  }
  $json = $response->data;
  return json_decode($json, true);
}

function _ubn_nuxeo_make_string_from_array($arr) {
    $tempstr = "(";
    foreach ($arr as $item) {
      $tempstr .= "'" . $item . "',";
    }
    $tempstr = trim($tempstr, ",");
    $tempstr .= ")";
    //var_dump($tempstr);
    return $tempstr;
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

    //var_dump($entry['properties']);
    
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

  if (empty($context->data)) {
    return;
  }

  $doclist = entity_metadata_wrapper('node', $context->data);
  //$doclist->language($language_content->language);
  //var_dump($doclist);

  $label = $doclist->label();
  var_dump($label);

  //$base_url = $doclist->field_doclist_baseurl;
  //$username = $doclist->field_doclist_username;
  var_dump($doclist);
  var_dump($doclist->data);

    //$uri = entity_uri('node', $_library);

  //$libraries_info[] = array(
  //  'label' => $doclist->label(),
      //'url' => url($uri['path']),
    //);


  $search_params = _ubn_nuxeo_get_query_params();

  $resultlist = _ubn_nuxeo_get_resultlist(_ubn_nuxeo_search($search_params));
  //var_dump($resultlist);
  
  $block = new stdClass();
  $block->title = t('Nuxeo search');
  $block->content = slate_render('nuxeo_search', array('resultlist' => $resultlist));

  return $block;
}
