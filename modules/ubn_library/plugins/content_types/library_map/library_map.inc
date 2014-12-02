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

  if (!empty($result['node'])) {
    $libraries = entity_load('node', array_keys($result['node']));
  }

  //var_dump($libraries);
  $block->content = ubn_general_generate_map($libraries);

  return $block;
}
