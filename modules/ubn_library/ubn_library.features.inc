<?php
/**
 * @file
 * ubn_library.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ubn_library_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ubn_library_image_default_styles() {
  $styles = array();

  // Exported image style: library_hero.
  $styles['library_hero'] = array(
    'name' => 'library_hero',
    'label' => 'Library: Hero',
    'effects' => array(
      1 => array(
        'label' => 'Skala',
        'help' => 'Skalning kommer att bibehålla proportionerna i den ursprungliga bilden. Om enbart ett mått anges kommer det andra måttet att räknas ut.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function ubn_library_node_info() {
  $items = array(
    'library' => array(
      'name' => t('Library'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
