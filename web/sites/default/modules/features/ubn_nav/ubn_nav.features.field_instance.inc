<?php
/**
 * @file
 * ubn_nav.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ubn_nav_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-navigation_landing-field_layout'.
  $field_instances['node-navigation_landing-field_layout'] = array(
    'bundle' => 'navigation_landing',
    'default_value' => array(
      0 => array(
        'value' => '3-column',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'ubn_search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_layout',
    'label' => 'Layout',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'ubn_property_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');

  return $field_instances;
}
