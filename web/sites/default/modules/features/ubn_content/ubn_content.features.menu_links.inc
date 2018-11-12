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
    'weight' => -48,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-shortcut-menu_kontakta-oss:node/101876.
  $menu_links['menu-shortcut-menu_kontakta-oss:node/101876'] = array(
    'menu_name' => 'menu-shortcut-menu',
    'link_path' => 'node/101876',
    'router_path' => 'node/%',
    'link_title' => 'Kontakta oss',
    'options' => array(
      'attributes' => array(
        'title' => 'Kontakta oss',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-shortcut-menu_kontakta-oss:node/101876',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'sv',
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
    'weight' => -49,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-shortcut-menu_nyheter:news.
  $menu_links['menu-shortcut-menu_nyheter:news'] = array(
    'menu_name' => 'menu-shortcut-menu',
    'link_path' => 'news',
    'router_path' => 'news',
    'link_title' => 'Nyheter',
    'options' => array(
      'attributes' => array(
        'title' => 'Nyheter',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-shortcut-menu_nyheter:news',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'sv',
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
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-shortcut-menu_ppetider--bibliotek:node/101183.
  $menu_links['menu-shortcut-menu_ppetider--bibliotek:node/101183'] = array(
    'menu_name' => 'menu-shortcut-menu',
    'link_path' => 'node/101183',
    'router_path' => 'node/%',
    'link_title' => 'Öppetider & bibliotek',
    'options' => array(
      'attributes' => array(
        'title' => 'Öppetider & bibliotek',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-shortcut-menu_ppetider--bibliotek:node/101183',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'sv',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact us');
  t('Kontakta oss');
  t('News');
  t('Nyheter');
  t('Opening hours & libraries');
  t('Öppetider & bibliotek');

  return $menu_links;
}
