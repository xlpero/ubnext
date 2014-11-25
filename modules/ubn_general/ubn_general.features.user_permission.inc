<?php
/**
 * @file
 * ubn_general.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ubn_general_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format markdown'.
  $permissions['use text format markdown'] = array(
    'name' => 'use text format markdown',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
