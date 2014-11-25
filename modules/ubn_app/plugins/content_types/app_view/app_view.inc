<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('App: View'),
  'description' => t('View an app.'),
  'category' => 'UBNext',
  'required context' => new ctools_context_required(t('App'), 'entity:node'),
  'edit form' => 'ubn_app_app_view_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_app_app_view_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_app_app_view_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context->data)) {
    return;
  }

  $app = entity_metadata_wrapper('node', $context->data);

  $block = new stdClass();
  $block->title = $app->label();
  $block->content = ubn_app_include_app($app);

  return $block;
}
