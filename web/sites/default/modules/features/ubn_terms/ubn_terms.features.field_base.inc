<?php
/**
 * @file
 * ubn_terms.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ubn_terms_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_term_synonyms'.
  $field_bases['field_term_synonyms'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_term_synonyms',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'term_synonym',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'title_taxonomy_allowed_values',
    ),
    'translatable' => 1,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
