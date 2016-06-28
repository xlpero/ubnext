<?php
/**
 * @file
 * ubn_nav.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ubn_nav_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ubn_nav_node_info() {
  $items = array(
    'navigation_landing' => array(
      'name' => t('Navigation Landing'),
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
