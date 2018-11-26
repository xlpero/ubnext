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
  $items['0d675f63-cf7b-4350-ac82-a5f216886c03'] = entity_create('menu_link', array(
    'menu_name' => 'menu-shortcut-menu',
    'plid' => 0,
    'link_path' => 'node/e5180327-a052-4a35-882b-2f0852935fe3',
    'router_path' => 'node/%',
    'link_title' => 'Contact us',
    'options' => array(
      'attributes' => array(
        'title' => 'Contact us',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-shortcut-menu_contact-us:node/101876',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'depth' => 1,
    'customized' => 1,
    'p1' => '0d675f63-cf7b-4350-ac82-a5f216886c03',
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
    'vuuid' => 'fa119d65-73af-45c9-8ac5-db6771d0222c',
    'uuid' => '0d675f63-cf7b-4350-ac82-a5f216886c03',
    'default_revision' => 1,
    'access' => TRUE,
    'i18n_menu' => TRUE,
  ));
  return $items;
}
