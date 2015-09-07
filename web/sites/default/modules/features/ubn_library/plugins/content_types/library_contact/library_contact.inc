<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Library: Contact'),
  'description' => t('A map with all Libraries.'),
  'category' => 'UBNext',
  'required context' => new ctools_context_required(t('Library'), 'entity:node'),
  'edit form' => 'ubn_library_library_contact_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_library_library_contact_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_library_library_contact_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context->data)) {
    return;
  }

  global $language_content;

  $library = entity_metadata_wrapper('node', $context->data);
  $library->language($language_content->language);

  $block = new stdClass();
  $block->title = t('Library Contact');
  $block->content = slate_render('library_contact', array('library' => $library));

  return $block;
}
