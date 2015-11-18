<?php
/**
 * @file
 * ubn_general.context_config.inc
 */

/**
 * Implements hook_default_scald_context_config().
 */
function ubn_general_default_scald_context_config() {
  $export = array();

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'hero_area';
  $context_config->transcoder = array(
    'file' => array(
      '*' => 'passthrough',
    ),
    'image' => array(
      '*' => 'style-library_hero',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'file' => array(
      '*' => 'default',
    ),
    'image' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'video' => array(
      '*' => 'default',
    ),
  );
  $context_config->data = array(
    'width' => '',
    'height' => '',
  );
  $export['hero_area'] = $context_config;

  return $export;
}
