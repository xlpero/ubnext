<?php
/**
 * @file
 * ubn_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ubn_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
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
function ubn_content_types_image_default_styles() {
  $styles = array();

  // Exported image style: content_admin.
  $styles['content_admin'] = array(
    'label' => 'Content admin',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 266,
          'height' => 150,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: library_hero.
  $styles['library_hero'] = array(
    'label' => 'Library hero',
    'effects' => array(
      12 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 930,
          'height' => 300,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'library_hero',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: library_hero_extra_small.
  $styles['library_hero_extra_small'] = array(
    'label' => 'Library hero extra small',
    'effects' => array(
      2 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 750,
          'height' => 242,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'library_hero_extra_small',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: page_content.
  $styles['page_content'] = array(
    'label' => 'Page content',
    'effects' => array(
      8 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1024,
          'height' => 576,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'page_content',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: page_content_extra_small.
  $styles['page_content_extra_small'] = array(
    'label' => 'Page content extra small',
    'effects' => array(
      10 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 750,
          'height' => 422,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'page_content_extra_small',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: page_content_inline_extra_small.
  $styles['page_content_inline_extra_small'] = array(
    'label' => 'Page content inline extra small',
    'effects' => array(
      17 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 325,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: page_content_inline_large.
  $styles['page_content_inline_large'] = array(
    'label' => 'Page content inline large',
    'effects' => array(
      14 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1024,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: page_content_inline_medium.
  $styles['page_content_inline_medium'] = array(
    'label' => 'Page content inline medium',
    'effects' => array(
      15 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 768,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: page_content_inline_small.
  $styles['page_content_inline_small'] = array(
    'label' => 'Page content inline small',
    'effects' => array(
      16 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 512,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: page_content_portrait.
  $styles['page_content_portrait'] = array(
    'label' => 'Page content portrait',
    'effects' => array(
      13 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 465,
          'height' => 576,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'page_content_portrait',
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
function ubn_content_types_node_info() {
  $items = array(
    'database' => array(
      'name' => t('Database'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'embedded_page' => array(
      'name' => t('Embedded page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'library' => array(
      'name' => t('Library'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'navigation_landing' => array(
      'name' => t('Navigation Landing'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'opening_hours' => array(
      'name' => t('Opening hours'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
