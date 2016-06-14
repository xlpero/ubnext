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
  $queue = entityqueue_subqueue_load('front_page_blurbs');
  $wrapper = entity_metadata_wrapper('entityqueue_subqueue', $queue);

  //TODO: Hardcoded for now, or load queue and check entity type?
  $blurbs = array();
  foreach($wrapper->eq_node as $delta => $blurb) {
    if ($delta > 0) {
      $blurbs[] = $blurb->value();
    }
  }

  if (!empty($blurbs)) {
    $renderable = entity_view('node', $blurbs, 'ubn_blurb');
  }

  $blurbs = drupal_render($renderable);
  $content = slate_render('front-page-blurbs', array('blurbs' => $blurbs));

  $block = new stdClass();
  $block->title = '';
  $block->content = $content;
  return $block;
}
