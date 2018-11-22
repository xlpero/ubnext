<?php
/**
 * @file
 * ubn_search_content.features.uuid_entity_menu_position_rule.inc
 */

/**
 * Implements hook_uuid_entity_default_menu_position_rule().
 */
function ubn_search_content_uuid_entity_default_menu_position_rule() {
  $items = array();
  $items['bac8c57e-2086-45f1-9cb9-9a46a0b7a22c'] = entity_create('menu_position_rule', array(
    'admin_title' => 'Databases',
    'enabled' => 1,
    'conditions' => array(
      'content_type' => array(
        'content_type' => array(
          'database' => 'database',
        ),
      ),
    ),
    'menu_name' => 'main-menu',
    'plid' => '74e6bc5b-5d90-41d4-bd22-50ab89cead16',
    'weight' => 0,
    'uuid' => 'bac8c57e-2086-45f1-9cb9-9a46a0b7a22c',
  ));
  return $items;
}
