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
  $items['2e9f59f7-b291-49c9-9726-e61d85e5c0ee'] = entity_create('menu_link', array(
    'menu_name' => 'main-menu',
    'plid' => 0,
    'link_path' => 'node/f8bcf20f-d066-41fc-9e41-c1b3d97dccee',
    'router_path' => 'node/%',
    'link_title' => 'Libraries',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'depth' => 1,
    'customized' => 1,
    'p1' => '2e9f59f7-b291-49c9-9726-e61d85e5c0ee',
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
    'vuuid' => 'f587d693-c89d-4140-af26-c7e3ae301651',
    'uuid' => '2e9f59f7-b291-49c9-9726-e61d85e5c0ee',
    'default_revision' => 1,
    'access' => TRUE,
    'i18n_menu' => TRUE,
  ));
  return $items;
}
