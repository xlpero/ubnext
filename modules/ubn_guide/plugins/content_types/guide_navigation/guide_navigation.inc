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
  if (empty($context->data)) {
    return;
  }

  $node = entity_metadata_wrapper('node', $context->data);

  $block = new stdClass();
  $block->title = t('Guide Navigation');

  $args = array(
    'next' => FALSE,
    'prev' => FALSE,
  );

  if (($nid = ubn_guide_find_next_chapter($node)) !== FALSE) {
    $next = entity_metadata_wrapper('node', $nid);

    $args['next'] = array(
      'label' => $next->label(),
      'url' => url("node/{$nid}"),
    );
  }

  if (($nid = ubn_guide_find_prev_chapter($node)) !== FALSE) {
    $prev = entity_metadata_wrapper('node', $nid);

    $args['prev'] = array(
      'label' => $prev->label(),
      'url' => url("node/{$nid}"),
    );
  }

  $block->content = slate_render('guide-navigation', $args);

  return $block;
}
