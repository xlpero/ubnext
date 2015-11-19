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
    'library' => array(
      'name' => t('Library'),
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

/**
 * Implements hook_scald_default_context_types().
 */
function ubn_content_types_scald_default_context_types() {
  $contexts = array();
  $contexts['deleted-file'] = array(
    'player' => array(
      'file' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'file' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['deleted-image'] = array(
    'player' => array(
      'image' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'image' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['deleted-video'] = array(
    'player' => array(
      'video' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'video' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['file_representation-file'] = array(
    'player' => array(
      'file' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'file' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['file_representation-image'] = array(
    'player' => array(
      'image' => array(
        '*' => 'default',
        'settings' => array(),
      ),
    ),
    'transcoder' => array(
      'image' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['file_representation-video'] = array(
    'player' => array(
      'video' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'video' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['full-file'] = array(
    'player' => array(
      'file' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'file' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['full-image'] = array(
    'player' => array(
      'image' => array(
        '*' => 'default',
        'settings' => array(),
      ),
    ),
    'transcoder' => array(
      'image' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['full-video'] = array(
    'player' => array(
      'video' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'video' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['hero_area_banner-file'] = array(
    'player' => array(
      'file' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'file' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['hero_area_banner-image'] = array(
    'player' => array(
      'image' => array(
        '*' => 'default',
        'settings' => array(),
      ),
    ),
    'transcoder' => array(
      'image' => array(
        '*' => 'style-library_hero',
      ),
    ),
  );
  $contexts['hero_area_banner-video'] = array(
    'player' => array(
      'video' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'video' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['invalid-id-file'] = array(
    'player' => array(
      'file' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'file' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['invalid-id-image'] = array(
    'player' => array(
      'image' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'image' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['invalid-id-video'] = array(
    'player' => array(
      'video' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'video' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['no-access-file'] = array(
    'player' => array(
      'file' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'file' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['no-access-image'] = array(
    'player' => array(
      'image' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'image' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['no-access-video'] = array(
    'player' => array(
      'video' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'video' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['page_content-file'] = array(
    'player' => array(
      'file' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'file' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['page_content-image'] = array(
    'player' => array(
      'image' => array(
        '*' => 'default',
        'settings' => array(),
      ),
    ),
    'transcoder' => array(
      'image' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['page_content-video'] = array(
    'player' => array(
      'video' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'video' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['page_content_attachments-file'] = array(
    'player' => array(
      'file' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'file' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['page_content_attachments-image'] = array(
    'player' => array(
      'image' => array(
        '*' => 'default',
        'settings' => array(),
      ),
    ),
    'transcoder' => array(
      'image' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['page_content_attachments-video'] = array(
    'player' => array(
      'video' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'video' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['sdl_editor_representation-file'] = array(
    'player' => array(
      'file' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'file' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['sdl_editor_representation-image'] = array(
    'player' => array(
      'image' => array(
        '*' => 'default',
        'settings' => array(),
      ),
    ),
    'transcoder' => array(
      'image' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['sdl_editor_representation-video'] = array(
    'player' => array(
      'video' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'video' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['sdl_library_item-file'] = array(
    'player' => array(
      'file' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'file' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['sdl_library_item-image'] = array(
    'player' => array(
      'image' => array(
        '*' => 'default',
        'settings' => array(),
      ),
    ),
    'transcoder' => array(
      'image' => array(
        '*' => 'style-Library',
      ),
    ),
  );
  $contexts['sdl_library_item-video'] = array(
    'player' => array(
      'video' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'video' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['sdl_preview-file'] = array(
    'player' => array(
      'file' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'file' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['sdl_preview-image'] = array(
    'player' => array(
      'image' => array(
        '*' => 'default',
        'settings' => array(),
      ),
    ),
    'transcoder' => array(
      'image' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['sdl_preview-video'] = array(
    'player' => array(
      'video' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'video' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['title-file'] = array(
    'player' => array(
      'file' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'file' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['title-image'] = array(
    'player' => array(
      'image' => array(
        '*' => 'default',
        'settings' => array(),
      ),
    ),
    'transcoder' => array(
      'image' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  $contexts['title-video'] = array(
    'player' => array(
      'video' => array(
        '*' => 'default',
      ),
    ),
    'transcoder' => array(
      'video' => array(
        '*' => 'passthrough',
      ),
    ),
  );
  return $contexts;
}
