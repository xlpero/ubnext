<?php
/**
 * @file
 * ubn_content.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ubn_content_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_entity_features_entities';
  $strongarm->value = array(
    'node' => array(
      'enabled' => 1,
      'bundles' => array(
        'page' => 'page',
      ),
      'rebuild_behavior' => '1',
    ),
    'taxonomy_term' => array(
      'enabled' => 0,
      'bundles' => array(),
      'rebuild_behavior' => '0',
    ),
    'comment' => array(
      'enabled' => 0,
      'bundles' => array(),
      'rebuild_behavior' => '0',
    ),
    'field_collection_item' => array(
      'enabled' => 0,
      'bundles' => array(),
      'rebuild_behavior' => '0',
    ),
    'menu_position_rule' => array(
      'enabled' => 1,
      'rebuild_behavior' => '2',
      'bundles' => array(),
    ),
    'file' => array(
      'enabled' => 0,
      'rebuild_behavior' => '0',
      'bundles' => array(),
    ),
    'user' => array(
      'enabled' => 0,
      'rebuild_behavior' => '0',
      'bundles' => array(),
    ),
    'menu_link' => array(
      'enabled' => 1,
      'bundles' => array(
        'main-menu' => 'main-menu',
      ),
      'rebuild_behavior' => '2',
    ),
  );
  $export['uuid_entity_features_entities'] = $strongarm;

  return $export;
}
