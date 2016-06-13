<?php
/**
 * @file
 * ubn_styles.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ubn_styles_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dnd_context_default';
  $strongarm->value = 'page_content_inline_large';
  $export['dnd_context_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'picture_ckeditor_mappings';
  $strongarm->value = array(
    'page_content' => array(
      'enabled' => 0,
      'weight' => '1',
      'fallback' => 'library_hero',
      'lazyload' => 0,
      'lazyload_aspect_ratio' => 0,
    ),
    'library_hero' => array(
      'enabled' => 0,
      'weight' => '1',
      'fallback' => 'page_content',
      'lazyload' => 0,
      'lazyload_aspect_ratio' => 0,
    ),
  );
  $export['picture_ckeditor_mappings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'picture_fallback_method';
  $strongarm->value = 'srcset';
  $export['picture_fallback_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'picture_img_sizes_output_method';
  $strongarm->value = 'picture_element';
  $export['picture_img_sizes_output_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'picture_js_scope';
  $strongarm->value = 'footer';
  $export['picture_js_scope'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'picture_polyfill_version';
  $strongarm->value = 'min';
  $export['picture_polyfill_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'picture_updated_to_file_entity_2';
  $strongarm->value = FALSE;
  $export['picture_updated_to_file_entity_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_switch_feature_export';
  $strongarm->value = 0;
  $export['scald_switch_feature_export'] = $strongarm;

  return $export;
}
