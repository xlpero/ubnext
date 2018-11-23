<?php
/**
 * @file
 * ubn_news_content.features.uuid_entity_menu_link.inc
 */

/**
 * Implements hook_uuid_entity_default_menu_link().
 */
function ubn_news_content_uuid_entity_default_menu_link() {
  $items = array();
  $items['73c11ce0-750b-4a56-99da-45cdb0a593c3'] = entity_create('menu_link', array(
    'menu_name' => 'menu-shortcut-menu',
    'plid' => 0,
    'link_path' => 'news',
    'router_path' => 'news',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(
        'title' => 'News',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-shortcut-menu_news:news',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'depth' => 1,
    'customized' => 1,
    'p1' => '73c11ce0-750b-4a56-99da-45cdb0a593c3',
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
    'vuuid' => 'b08a4f0c-7092-4b47-91aa-f73bc7e626de',
    'uuid' => '73c11ce0-750b-4a56-99da-45cdb0a593c3',
    'default_revision' => 1,
    'access' => TRUE,
    'i18n_menu' => TRUE,
  ));
  return $items;
}
