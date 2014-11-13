<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Guide: Navigation'),
  'description' => t('Guide navigation links.'),
  'category' => 'UBNext',
  'required context' => new ctools_context_required(t('Guide'), 'entity:node'),
  'edit form' => 'ubn_guide_guide_navigation_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_guide_guide_navigation_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_guide_guide_navigation_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->title = t('Guide Navigation');
  $block->content = 'foobar';

  return $block;
}
