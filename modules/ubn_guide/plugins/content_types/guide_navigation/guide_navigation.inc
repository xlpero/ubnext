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

  $links = array();

  $prev = ubn_guide_find_prev_chapter($node);

  if ($prev !== FALSE) {
    $links[] = array(
      'title' => t('Prev'),
      'href' => "node/$prev",
    );
  }

  $next = ubn_guide_find_next_chapter($node);

  if ($next !== FALSE) {
    $links[] = array(
      'title' => t('Next'),
      'href' => "node/$next",
    );
  }

  $block->content = theme('links', array('links' => $links));

  return $block;
}
