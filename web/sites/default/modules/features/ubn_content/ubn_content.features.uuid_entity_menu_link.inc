<?php
/**
 * @file
 * ubn_content.features.uuid_entity_menu_link.inc
 */

/**
 * Implements hook_uuid_entity_default_menu_link().
 */
function ubn_content_uuid_entity_default_menu_link() {
  $items = array();
  $items['21c050e2-5ef9-4347-af28-192f53a34c05'] = entity_create('menu_link', array(
    'menu_name' => 'main-menu',
    'plid' => '9f38d427-1547-42fb-b878-c35ff0014922',
    'link_path' => 'search/databases/search',
    'router_path' => 'search/databases/search',
    'link_title' => 'Search databases',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'depth' => 2,
    'customized' => 1,
    'p1' => '9f38d427-1547-42fb-b878-c35ff0014922',
    'p2' => '21c050e2-5ef9-4347-af28-192f53a34c05',
    'p3' => 0,
    'p4' => 0,
    'p5' => 0,
    'p6' => 0,
    'p7' => 0,
    'p8' => 0,
    'p9' => 0,
    'updated' => 0,
    'language' => 'und',
    'vuuid' => '13d6400b-355f-481b-b095-2b378e03560d',
    'uuid' => '21c050e2-5ef9-4347-af28-192f53a34c05',
    'default_revision' => 1,
    'access' => TRUE,
    'i18n_menu' => TRUE,
  ));
  $items['9f38d427-1547-42fb-b878-c35ff0014922'] = entity_create('menu_link', array(
    'menu_name' => 'main-menu',
    'plid' => 0,
    'link_path' => 'node/84551f72-f8f7-43fc-b4f0-020e0ed5af2a',
    'router_path' => 'node/%',
    'link_title' => 'Search',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'depth' => 1,
    'customized' => 1,
    'p1' => '9f38d427-1547-42fb-b878-c35ff0014922',
    'p2' => 0,
    'p3' => 0,
    'p4' => 0,
    'p5' => 0,
    'p6' => 0,
    'p7' => 0,
    'p8' => 0,
    'p9' => 0,
    'updated' => 0,
    'language' => 'und',
    'vuuid' => '2fec1b55-0d81-4d3d-9284-8b30599f8cdb',
    'uuid' => '9f38d427-1547-42fb-b878-c35ff0014922',
    'default_revision' => 1,
    'access' => TRUE,
    'i18n_menu' => TRUE,
  ));
  return $items;
}
