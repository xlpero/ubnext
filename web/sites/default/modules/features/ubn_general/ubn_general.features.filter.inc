<?php
/**
 * @file
 * ubn_general.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function ubn_general_filter_default_formats() {
  $formats = array();

  // Exported format: Markdown.
  $formats['markdown'] = array(
    'format' => 'markdown',
    'name' => 'Markdown',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'ubn_markdown' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_markdown' => array(
        'weight' => -43,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -42,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => -41,
        'status' => 1,
        'settings' => array(
          'local_paths' => '',
          'protocol_style' => 'path',
        ),
      ),
    ),
  );

  return $formats;
}
