<?php
/**
 * @file
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Front page blurbs'),
  'description' => t('Front page blurbs.'),
  'category' => 'UBNext',
  'edit form' => 'ubn_startpage_front_page_blurbs_content_type_settings',
);

/**
 * Settings callback.
 */
function ubn_startpage_front_page_blurbs_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_startpage_front_page_blurbs_content_type_render($subtype, $conf, $panel_args, $context) {
  drupal_add_js(drupal_get_path('module', 'ubn_startpage') . '/ubn_startpage.js');

  $queue = entityqueue_subqueue_load('front_page_blurbs');
  $wrapper = entity_metadata_wrapper('entityqueue_subqueue', $queue);

  //TODO: Hardcoded for now, or load queue and check entity type?
  $blurbs = array();
  foreach($wrapper->eq_node as $delta => $blurb) {
    $blurb_node = $blurb->value();
    if ($blurb_node->status == NODE_PUBLISHED) {
      $blurbs[] = $blurb_node;
    }
  }

  $block = new stdClass();
  $block->title = '';
  $block->content  = '';
  if (!empty($blurbs)) {
    $renderable = entity_view('node', $blurbs, 'ubn_blurb');
    $blurbs = drupal_render($renderable);
    $block->content = slate_render('front-page-blurbs', array('blurbs' => $blurbs));
  }

  return $block;
}
