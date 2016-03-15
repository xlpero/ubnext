<?php
/**
 * @file
 * ubn_contact.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ubn_contact_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'skip CAPTCHA'.
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'captcha',
  );

  return $permissions;
}
