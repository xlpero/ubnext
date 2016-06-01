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
    'plid' => '6e4d0044-7fef-4ba9-9a15-3ce11737e34e',
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
    'p1' => '6e4d0044-7fef-4ba9-9a15-3ce11737e34e',
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
    'vuuid' => '98fb1643-914e-4620-a528-f850a109aa8b',
    'uuid' => '21c050e2-5ef9-4347-af28-192f53a34c05',
    'default_revision' => 1,
    'access' => TRUE,
    'i18n_menu' => TRUE,
  ));
  $items['6e4d0044-7fef-4ba9-9a15-3ce11737e34e'] = entity_create('menu_link', array(
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
    'p1' => '6e4d0044-7fef-4ba9-9a15-3ce11737e34e',
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
    'vuuid' => 'f5ab8a50-7967-45a7-a643-39a37abf6c5a',
    'uuid' => '6e4d0044-7fef-4ba9-9a15-3ce11737e34e',
    'default_revision' => 1,
    'access' => TRUE,
    'i18n_menu' => TRUE,
  ));
  return $items;
}
