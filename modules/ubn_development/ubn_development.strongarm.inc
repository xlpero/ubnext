<?php
/**
 * @file
 * ubn_development.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ubn_development_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_language_pages';
  $strongarm->value = 'admin_menu/*
file/ajax/*
system/ajax
panels/ajax/*';
  $export['admin_language_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_language_translate_admin_menu';
  $strongarm->value = '1';
  $export['admin_language_translate_admin_menu'] = $strongarm;

  return $export;
}
