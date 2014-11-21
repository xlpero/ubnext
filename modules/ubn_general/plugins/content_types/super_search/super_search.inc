<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('General: Super search'),
  'description' => t('Super-duper-mega-search!'),
  'category' => 'UBNext',
  'edit form' => 'ubn_general_super_search_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_general_super_search_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_general_super_search_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = t('List of Terms');

  $block->content = drupal_get_form('ubn_general_super_search_form');

  return $block;
}
