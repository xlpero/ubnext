<?php
/**
 * @file
 * ubn_search_content.features.uuid_entity_menu_link.inc
 */

/**
 * Implements hook_uuid_entity_default_menu_link().
 */
function ubn_search_content_uuid_entity_default_menu_link() {
  $items = array();
  $items['21c050e2-5ef9-4347-af28-192f53a34c05'] = entity_create('menu_link', array(
    'menu_name' => 'main-menu',
    'plid' => '50d606aa-c647-4716-a885-fa850afdad42',
    'link_path' => 'find/databases/search',
    'router_path' => 'find/databases/search',
    'link_title' => 'Search databases',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'depth' => 3,
    'customized' => 1,
    'p1' => '9f38d427-1547-42fb-b878-c35ff0014922',
    'p2' => '50d606aa-c647-4716-a885-fa850afdad42',
    'p3' => '21c050e2-5ef9-4347-af28-192f53a34c05',
    'p4' => 0,
    'p5' => 0,
    'p6' => 0,
    'p7' => 0,
    'p8' => 0,
    'p9' => 0,
    'updated' => 0,
    'language' => 'und',
    'vuuid' => '424df4e8-44eb-4514-a527-4356db124005',
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
    'link_title' => 'Find',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
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
    'vuuid' => 'ec8ded93-7881-4bad-9dc3-89f056d3fa0a',
    'uuid' => '9f38d427-1547-42fb-b878-c35ff0014922',
    'default_revision' => 1,
    'access' => TRUE,
    'i18n_menu' => TRUE,
  ));
  $items['50d606aa-c647-4716-a885-fa850afdad42'] = entity_create('menu_link', array(
    'menu_name' => 'main-menu',
    'plid' => '9f38d427-1547-42fb-b878-c35ff0014922',
    'link_path' => 'node/734a67d4-1f57-4517-8ce7-17344f5d4f3e',
    'router_path' => 'node/%',
    'link_title' => 'Databases',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'depth' => 2,
    'customized' => 1,
    'p1' => '9f38d427-1547-42fb-b878-c35ff0014922',
    'p2' => '50d606aa-c647-4716-a885-fa850afdad42',
    'p3' => 0,
    'p4' => 0,
    'p5' => 0,
    'p6' => 0,
    'p7' => 0,
    'p8' => 0,
    'p9' => 0,
    'updated' => 0,
    'language' => 'und',
    'vuuid' => '578bb15c-ceb2-4f98-b70a-1a0f5985097e',
    'uuid' => '50d606aa-c647-4716-a885-fa850afdad42',
    'default_revision' => 1,
    'access' => TRUE,
    'i18n_menu' => TRUE,
  ));
  return $items;
}
