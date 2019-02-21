<?php
/**
 * @file
 * ubn_nav.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ubn_nav_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_layout'.
  $field_bases['field_layout'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_layout',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        '3-column' => '3-column',
        '1-column' => '1-column',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
