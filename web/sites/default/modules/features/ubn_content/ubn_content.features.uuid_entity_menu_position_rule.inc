<?php
/**
 * @file
 * ubn_content.features.uuid_entity_menu_position_rule.inc
 */

/**
 * Implements hook_uuid_entity_default_menu_position_rule().
 */
function ubn_content_uuid_entity_default_menu_position_rule() {
  $items = array();
  $items['fb0e614d-5b06-4623-b3b8-d2206914d8b6'] = entity_create('menu_position_rule', array(
   'admin_title' => 'Database',
   'enabled' => 1,
   'conditions' => array(
     'content_type' => array(
       'content_type' => array(
         'database' => 'database',
       ),
     ),
   ),
   'menu_name' => 'main-menu',
   'plid' => NULL,
   'weight' => 0,
   'uuid' => 'fb0e614d-5b06-4623-b3b8-d2206914d8b6',
   'rdf_mapping' => array(),
 ));
  return $items;
}
