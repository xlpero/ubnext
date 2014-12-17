<?php
/**
 * @file
 * ubn_nuxeo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ubn_nuxeo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ubn_nuxeo_node_info() {
  $items = array(
    'document_list' => array(
      'name' => t('Document List'),
      'base' => 'node_content',
      'description' => t('This is a list of documents hosted in Nuxeo. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Connects to the Document Management System and retrieves the given
 * vocabularies. The vocabularies are returned as an array with the
 * vocabulary ID as a key and the label as value.
 *
 * @param string $vocabulary
 * @return mixed|string
 */
function _ubn_nuxeo_vocabulary($vocabulary = 'l10n_ub_orgs') {

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
  $end_point = (isset($_SERVER['DMS_API_EP_DIRECTORY']) ?$_SERVER['DMS_API_EP_DIRECTORY']  : 'directory/' );

  $url = $protocol."://".$username.":".$password."@".$base_url . $end_point . $vocabulary;

  #var_dump($url);
  $response = drupal_http_request($url, $options);
  #var_dump($response);

  $vocabulary = array();

  if (!empty($response->error)) {
    return $vocabulary;
  }

  $json = $response->data;
  $data = json_decode($json, true);

  $top_levels = array();

  foreach ($data['entries'] as $entry) {
    $id = "";

    if (empty($entry['properties']['parent'])) {

      $id = $entry['properties']['id'];

      # If the _top string is within the id, skip it from our vocabulary
      # and put it in a separate array for later use.
      if (strpos($id, '_top') !== FALSE) {
        $top_levels[$id] = $entry['properties']['label_sv'];
        var_dump("OOOOOOOOAHAHAHAHAHAHAHAHA HA HA HA HA!!!!!!!");
      }
    }
  }

  foreach ($data['entries'] as $entry) {
    $id = "";

    if (empty($entry['properties']['parent'])) {

      $id = $entry['properties']['id'];

      # If the _top string is absent in the id, use it in our vocabulary
      if (strpos($id, '_top') === false) {
        $vocabulary[$id] = $entry['properties']['label_sv'];
      }
    }
    else {
      $parent = $entry['properties']['parent'];
      $id .= $parent . '/' . $entry['properties']['id'];
      $vocabulary[$id] = "(" . $top_levels[$parent] . ") " . $entry['properties']['label_sv'];
    }
    var_dump($id);
  }
  var_dump($top_levels);
  var_dump($vocabulary);
  return $vocabulary;
}
