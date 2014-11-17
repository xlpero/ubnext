<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Dictionary: List of Terms'),
  'description' => t('A List of Terms for a Dictionary.'),
  'category' => 'UBNext',
  'edit form' => 'ubn_dictionary_term_list_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_dictionary_term_list_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_dictionary_term_list_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->title = t('List of Terms');

  $block->content = "foobar!";

  return $block;
}
