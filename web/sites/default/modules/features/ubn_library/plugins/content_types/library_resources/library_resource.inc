<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Library: Resource'),
  'description' => t('A list of resources at the library.'),
  'category' => 'UBNext',
  'required context' => new ctools_context_required(t('Library'), 'entity:node'),
  'edit form' => 'ubn_library_library_contact_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_library_library_resource_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_library_library_resource_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context->data)) {
    return;
  }

  global $language_content;

  $library = entity_metadata_wrapper('node', $context->data);
  $library->language($language_content->language);

  $block = new stdClass();
  $block->title = t('Library Resources');
  $block->content = slate_render('library_resource', array('library' => $library));

  return $block;
}
