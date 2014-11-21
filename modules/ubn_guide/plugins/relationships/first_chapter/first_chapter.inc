<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t("First chapter from Guide"),
  'keyword' => 'first_chapter',
  'description' => t('Adds a context to the first chapter from existing Guide.'),
  'required context' => new ctools_context_required(t('Guide'), 'entity:node'),
  'settings form' => 'ubn_guide_first_chapter_settings_form',
  'context' => 'ubn_guide_first_chapter_context',
);


/**
 * Settings form for the relationship.
 */
function ubn_guide_first_chapter_settings_form($conf) {
  return array();
}

/**
 * Return a new context based on an existing context.
 */
function ubn_guide_first_chapter_context($context = NULL, $conf) {
  if (empty($context->data)) {
    return ctools_context_create_empty('entity:node', NULL);
  }

  $guide = entity_metadata_wrapper('node', $context->data);
  $children = ubn_guide_get_children($guide->getIdentifier(), 1);

  if (empty($children)) {
    return ctools_context_create_empty('entity:node', NULL);
  }

  $child = entity_load_single('node', key($children));

  return ctools_context_create('entity:node', $child);
}
