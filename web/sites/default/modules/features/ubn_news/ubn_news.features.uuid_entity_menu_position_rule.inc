<?php
/**
 * @file
 * ubn_news.features.uuid_entity_menu_position_rule.inc
 */

/**
 * Implements hook_uuid_entity_default_menu_position_rule().
 */
function ubn_news_uuid_entity_default_menu_position_rule() {
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
    'menu_name' => 'main-menu',
    'plid' => '91931532-ff81-4a88-8c0a-6bfd5e0d1009',
    'weight' => 0,
    'uuid' => 'a3d0978f-d7ba-40e6-8a73-b21b5a9f4b6d',
    'rdf_mapping' => array(),
  ));
  return $items;
}
