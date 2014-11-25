<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('App'),
  'description' => t('App'),
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

  global $language;

  $node = entity_metadata_wrapper('node', $context->data);

  $block = new stdClass();
  $block->title = t('App');

  $app_name = $node->field_app_name->value();
  drupal_add_js('http://130.241.35.100:4001/assets/vendor.js', 'external');
  drupal_add_js('http://130.241.35.100:4001/assets/'.$app_name.'.js', 'external');
  drupal_add_css('http://130.241.35.100:4001/assets/vendor.css', array('type'=>'external'));
  drupal_add_css('http://130.241.35.100:4001/assets/'.$app_name.'.css', array('type'=>'external'));

  $block->content = '<div id="ember-app-'.$app_name.'" data-lang="'.$language->language.'"></div>';

  return $block;
}
