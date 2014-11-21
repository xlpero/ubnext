<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t("Root node from Guide Chapter"),
  'keyword' => 'root_node',
  'description' => t('Adds a context to the root node from existing Guide Chapter.'),
  'required context' => new ctools_context_required(t('Guide Chapter'), 'entity:node'),
  'settings form' => 'ubn_guide_root_node_settings_form',
  'context' => 'ubn_guide_root_node_context',
);


/**
 * Settings form for the relationship.
 */
function ubn_guide_root_node_settings_form($conf) {
  return array();
}

/**
 * Return a new context based on an existing context.
 */
function ubn_guide_root_node_context($context = NULL, $conf) {
  if (empty($context->data)) {
    return ctools_context_create_empty('entity:node', NULL);
  }

  $guide_chapter = entity_metadata_wrapper('node', $context->data);
  $root = ubn_guide_get_root($guide_chapter);

  return ctools_context_create('entity:node', $root->value());
}
