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

  $tree = _ubn_guide_generate_toc_tree($node);

  $block->content = theme('item_list', array('items' => $tree));

  return $block;
}

/**
 * Generate ToC tree.
 */
function _ubn_guide_generate_toc_tree(EntityDrupalWrapper $current, &$flat = array(), EntityDrupalWrapper $child = NULL, $data = array()) {
  $items = array();

  $children = ubg_guide_get_children($current->getIdentifier(), 1);
  foreach (array_keys($children) as $id) {
    $flat[] = $id;
    $items[$id] = array();
  }

  if (!empty($data)) {
    $items[$child->getIdentifier()] = $data;
  }

  // If current is of type guide, we have reached the root node.
  if ($current->getBundle() === 'guide') {
    $nodes = entity_load('node', array_values($flat));

    return _ubn_guide_populate_toc_tree($items, $nodes);
  }

  return _ubn_guide_generate_toc_tree($current->field_guide_chapter_parent, $flat, $current, $items);
}

/**
 * Populate ToC tree.
 */
function _ubn_guide_populate_toc_tree($tree, $nodes) {
  $items = array();

  foreach ($tree as $nid => $children) {
    $node = entity_metadata_wrapper('node', $nodes[$nid]);

    $item = array(
      'data' => l($node->label(), "node/{$node->getIdentifier()}"),
    );

    if (!empty($children)) {
      $item['children'] = _ubn_guide_populate_toc_tree($children, $nodes);
    }

    $items[] = $item;
  }

  return $items;
}
