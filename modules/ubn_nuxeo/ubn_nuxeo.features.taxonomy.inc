<?php
/**
 * @file
 * ubn_nuxeo.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ubn_nuxeo_taxonomy_default_vocabularies() {
  return array(
    'document_list_doc_types' => array(
      'name' => 'document_list_doc_types',
      'machine_name' => 'document_list_doc_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'document_list_organizations' => array(
      'name' => 'document_list_organizations',
      'machine_name' => 'document_list_organizations',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
