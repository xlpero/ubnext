<?php
/**
 * @file
 * ubn_library_content.features.uuid_entity_menu_position_rule.inc
 */

/**
 * Implements hook_uuid_entity_default_menu_position_rule().
 */
function ubn_library_content_uuid_entity_default_menu_position_rule() {
  $items = array();
  $items['4151802e-d30f-4358-b860-9f64a8271611'] = entity_create('menu_position_rule', array(
    'admin_title' => 'Libraries',
    'enabled' => 1,
    'conditions' => array(
      'content_type' => array(
        'content_type' => array(
          'library' => 'library',
        ),
      ),
    ),
    'menu_name' => 'menu-shortcut-menu',
    'plid' => 'e85c6a8a-e005-4b74-9c29-e1e714d80b85',
    'weight' => 0,
    'uuid' => '4151802e-d30f-4358-b860-9f64a8271611',
  ));
  return $items;
}
