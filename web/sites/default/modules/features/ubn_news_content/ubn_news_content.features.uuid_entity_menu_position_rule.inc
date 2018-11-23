<?php
/**
 * @file
 * ubn_news_content.features.uuid_entity_menu_position_rule.inc
 */

/**
 * Implements hook_uuid_entity_default_menu_position_rule().
 */
function ubn_news_content_uuid_entity_default_menu_position_rule() {
  $items = array();
  $items['a3d0978f-d7ba-40e6-8a73-b21b5a9f4b6d'] = entity_create('menu_position_rule', array(
    'admin_title' => 'News',
    'enabled' => 1,
    'conditions' => array(
      'content_type' => array(
        'content_type' => array(
          'story' => 'story',
        ),
      ),
    ),
    'menu_name' => 'menu-shortcut-menu',
    'plid' => '73c11ce0-750b-4a56-99da-45cdb0a593c3',
    'weight' => 0,
    'uuid' => 'a3d0978f-d7ba-40e6-8a73-b21b5a9f4b6d',
  ));
  return $items;
}
