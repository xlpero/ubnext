<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Library: Map'),
  'description' => t('A map with all Libraries.'),
  'category' => 'UBNext',
  'edit form' => 'ubn_library_library_map_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_library_library_map_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_library_library_map_content_type_render($subtype, $conf, $panel_args, $context) {
  global $language_content;

  $block = new stdClass();
  $block->title = t('Library Map');

  $query = new EntityFieldQuery();

  $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'library')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->addTag('ENTITY_TRANSLATION');

  $result = $query->execute();

  if (empty($result['node'])) {
    return $block;
  }

  $libraries = entity_load('node', array_keys($result['node']));

  $libraries_info = array();

  foreach ($libraries as $_library) {
    $library = entity_metadata_wrapper('node', $_library);
    $library->language($language_content->language);

    $uri = entity_uri('node', $_library);

    $libraries_info[] = array(
      'label' => $library->label(),
      'url' => url($uri['path']),
    );
  }

  $block->content = slate_render('library-library_map', array(
    'libraries' => $libraries_info,
    'map' => ubn_general_generate_map($libraries),
  ));

  return $block;
}
