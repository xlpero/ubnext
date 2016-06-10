<?php
/**
 * @file
 * ubn_blurbs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ubn_blurbs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  if ($module == "scald" && $api == "context_config") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ubn_blurbs_image_default_styles() {
  $styles = array();

  // Exported image style: blurb_extra_small.
  $styles['blurb_extra_small'] = array(
    'label' => 'Blurb extra small',
    'effects' => array(
      2 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 720,
          'height' => 450,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'blurb_extra_small',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: blurb_small.
  $styles['blurb_small'] = array(
    'label' => 'Blurb small',
    'effects' => array(
      1 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 345,
          'height' => 216,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'blurb_small',
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function ubn_blurbs_node_info() {
  $items = array(
    'blurb' => array(
      'name' => t('Blurb'),
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
