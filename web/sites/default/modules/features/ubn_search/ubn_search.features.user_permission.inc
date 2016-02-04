<?php
/**
 * @file
 * ubn_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ubn_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access databases search_api_page'.
  $permissions['access databases search_api_page'] = array(
    'name' => 'access databases search_api_page',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'search_api_page',
  );

  // Exported permission: 'access search_api_page'.
  $permissions['access search_api_page'] = array(
    'name' => 'access search_api_page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api_page',
  );

  // Exported permission: 'access site search_api_page'.
  $permissions['access site search_api_page'] = array(
    'name' => 'access site search_api_page',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'search_api_page',
  );

  // Exported permission: 'use search_api_sorts'.
  $permissions['use search_api_sorts'] = array(
    'name' => 'use search_api_sorts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api_sorts',
  );

  return $permissions;
}
