<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Guide: Table of Contents'),
  'description' => t('Table of contents for a Guide.'),
  'category' => 'UBNext',
  'required context' => new ctools_context_required(t('Guide'), 'entity:node'),
  'edit form' => 'ubn_guide_guide_toc_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_guide_guide_toc_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_guide_guide_toc_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context->data)) {
    return;
  }

  $node = entity_metadata_wrapper('node', $context->data);

  $block = new stdClass();
  $block->title = t('Table of Contents');

  $root = ubn_guide_get_root($node);
  $children = ubg_guide_get_children($root->getIdentifier());

  $links = _ubn_guide_generate_toc($children, $node);

  $block->content = theme('item_list', array('items' => $links));

  return $block;
}

/**
 *
 */
function _ubn_guide_generate_toc($children, EntityDrupalWrapper $current) {
  $items = array();

  foreach ($children as $child_info) {
    $child = entity_load_single('node', $child_info['id']);

    $item = array(
      'data' => l($child->title, "node/$child->nid"),
    );

    if (!empty($child_info['children'])) {
      $item['children'] = _ubn_guide_generate_toc($child_info['children'], $current);
    }

    $items[] = $item;
  }

  return $items;
}