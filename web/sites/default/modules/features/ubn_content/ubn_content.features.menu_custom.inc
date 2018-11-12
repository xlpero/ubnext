<?php
/**
 * @file
 * ubn_content.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ubn_content_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-shortcut-menu.
  $menus['menu-shortcut-menu'] = array(
    'menu_name' => 'menu-shortcut-menu',
    'title' => 'Shortcut menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Shortcut menu');

  return $menus;
}
