<?php
/**
 * @file
 * ubn_content.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ubn_content_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-shortcut-menu_contact-us:node/101876.
  $menu_links['menu-shortcut-menu_contact-us:node/101876'] = array(
    'menu_name' => 'menu-shortcut-menu',
    'link_path' => 'node/101876',
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
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-shortcut-menu_news:news.
  $menu_links['menu-shortcut-menu_news:news'] = array(
    'menu_name' => 'menu-shortcut-menu',
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
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-shortcut-menu_opening-hours--libraries:node/101183.
  $menu_links['menu-shortcut-menu_opening-hours--libraries:node/101183'] = array(
    'menu_name' => 'menu-shortcut-menu',
    'link_path' => 'node/101183',
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
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact us');
  t('News');
  t('Opening hours & libraries');

  return $menu_links;
}
