<?php
/**
 * @file
 * ubn_dictionary.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ubn_dictionary_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ubn_dictionary_node_info() {
  $items = array(
    'dictionary_term' => array(
      'name' => t('Dictionary Term'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
