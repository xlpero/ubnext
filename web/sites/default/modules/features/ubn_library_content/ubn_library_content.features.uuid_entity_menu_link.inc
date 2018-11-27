<?php
/**
 * @file
 * ubn_library_content.features.uuid_entity_menu_link.inc
 */

/**
 * Implements hook_uuid_entity_default_menu_link().
 */
function ubn_library_content_uuid_entity_default_menu_link() {
  $items = array();
  $items['e85c6a8a-e005-4b74-9c29-e1e714d80b85'] = entity_create('menu_link', array(
    'menu_name' => 'menu-shortcut-menu',
    'plid' => 0,
    'link_path' => 'node/f8bcf20f-d066-41fc-9e41-c1b3d97dccee',
    'router_path' => 'node/%',
    'link_title' => 'Opening hours & libraries',
    'options' => array(
      'attributes' => array(
        'title' => 'Opening hours & libraries',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-shortcut-menu_opening-hours--libraries:node/101183',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'depth' => 1,
    'customized' => 1,
    'p1' => 'e85c6a8a-e005-4b74-9c29-e1e714d80b85',
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
    'vuuid' => 'e3c851f7-fe33-40fc-bf0c-d1eba320b3f7',
    'uuid' => 'e85c6a8a-e005-4b74-9c29-e1e714d80b85',
    'default_revision' => 1,
    'access' => TRUE,
    'i18n_menu' => TRUE,
  ));
  return $items;
}
