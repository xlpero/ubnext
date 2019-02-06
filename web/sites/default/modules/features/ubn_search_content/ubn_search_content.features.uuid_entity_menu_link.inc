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
  $items['74e6bc5b-5d90-41d4-bd22-50ab89cead16'] = entity_create('menu_link', array(
    'menu_name' => 'main-menu',
    'plid' => 0,
    'link_path' => 'databases/search',
    'router_path' => 'databases/search',
    'link_title' => 'Databases',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'depth' => 1,
    'customized' => 1,
    'p1' => '74e6bc5b-5d90-41d4-bd22-50ab89cead16',
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
    'vuuid' => '9d038384-b7e4-45e3-bef5-8933e7abe0a6',
    'uuid' => '74e6bc5b-5d90-41d4-bd22-50ab89cead16',
    'default_revision' => 1,
    'access' => TRUE,
    'ubn_menu_hidden' => TRUE,
    'i18n_menu' => TRUE,
  ));
  return $items;
}
