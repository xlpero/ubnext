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
  // no submit
  return $form;
}


/**
 * 
 *
 * Render callback.
 */
function ubn_general_search_widget_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $number = 111111;
  $search_slogan = t('Search among @number books, articles, magazines and more...', array('@number' => $number));
  //$block->title = "detta är titel";
  $block->content = slate_render('search-widget', array('list' => $search_slogan));//drupal_get_form('ubn_general_super_search_form');

  return $block;
}


