<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('General: Search widget'),
  'description' => t('This is the search widget that will forward search to Summon'),
  'category' => 'UBNext',
  'edit form' => 'ubn_general_search_widget_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_general_search_widget_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_general_search_widget_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = t('Super Search');

  $block->content = slate_render('search-widget');//drupal_get_form('ubn_general_super_search_form');

  return $block;
}

/**
 *
 */
function ubn_general_search_widget_form($form, $form_state) {
  $form['search'] = array(
    '#type' => 'textfield',
  );

  return $form;
}
