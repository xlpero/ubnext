<?php
/**
 * @file
 * ubn_alert.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ubn_alert_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_alert-and-info-message:node/add/alert-and-info-message.
  $menu_links['navigation_alert-and-info-message:node/add/alert-and-info-message'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/alert-and-info-message',
    'router_path' => 'node/add/alert-and-info-message',
    'link_title' => 'Alert and info message',
    'options' => array(
      'identifier' => 'navigation_alert-and-info-message:node/add/alert-and-info-message',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Alert and info message');

  return $menu_links;
}
