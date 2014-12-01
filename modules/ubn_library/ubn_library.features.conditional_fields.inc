<?php
/**
 * @file
 * ubn_library.features.conditional_fields.inc
 */

/**
 * Implements hook_conditional_fields_default_fields().
 */
function ubn_library_conditional_fields_default_fields() {
  $items = array();

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_library_properties',
    'dependent' => 'field_library_properties_text',
    'dependee' => 'field_library_properties_type',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 1,
      'value_form' => 'text',
      'value' => array(
        0 => array(
          'value' => 'text',
        ),
      ),
      'values' => array(),
    ),
  );

  return $items;
}
