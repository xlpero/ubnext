<?php
/**
 * @file
 * ubn_general.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ubn_general_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ubn_general_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ubn_general_image_default_styles() {
  $styles = array();

  // Exported image style: library_hero.
  $styles['library_hero'] = array(
    'label' => 'library_hero',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1000,
          'height' => 300,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
