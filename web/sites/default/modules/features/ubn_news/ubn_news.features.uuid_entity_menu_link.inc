<?php
/**
 * @file
 * ubn_news.features.uuid_entity_menu_link.inc
 */

/**
 * Implements hook_uuid_entity_default_menu_link().
 */
function ubn_news_uuid_entity_default_menu_link() {
  $items = array();
  $items['91931532-ff81-4a88-8c0a-6bfd5e0d1009'] = entity_create('menu_link', array(
    'menu_name' => 'main-menu',
    'plid' => 0,
    'link_path' => 'news',
    'router_path' => 'news',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'depth' => 1,
    'customized' => 1,
    'p1' => '91931532-ff81-4a88-8c0a-6bfd5e0d1009',
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
    'vuuid' => '2189e300-40ad-45bb-8967-2aac9770ca84',
    'uuid' => '91931532-ff81-4a88-8c0a-6bfd5e0d1009',
    'default_revision' => 1,
    'access' => TRUE,
  ));
  return $items;
}
