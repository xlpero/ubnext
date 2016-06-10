<?php
/**
 * @file
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Front page blurbs: primary'),
  'description' => t('Front page primary blurbs.'),
  'category' => 'UBNext',
  'edit form' => 'ubn_startpage_front_page_blurbs_primary_content_type_settings',
);

/**
 * Settings callback.
 */
function ubn_startpage_front_page_blurbs_primary_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_startpage_front_page_blurbs_primary_content_type_render($subtype, $conf, $panel_args, $context) {
  $queue = entityqueue_subqueue_load('front_page_blurbs');
  $wrapper = entity_metadata_wrapper('entityqueue_subqueue', $queue);

  //TODO: Hardcoded for now, or load queue and check entity type?
  if(!empty($wrapper->eq_node)) {
    $first_blurb = $wrapper->eq_node[0]->value();
    $renderable = entity_view('node', array($first_blurb), 'ubn_blurb_primary');
  }

  $block = new stdClass();
  $block->title = '';
  $block->content = drupal_render($renderable);
  return $block;
}
