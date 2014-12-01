<?php
/**
 * @file
 * ubn_library.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ubn_library_taxonomy_default_vocabularies() {
  return array(
    'library_properties' => array(
      'name' => 'library_properties',
      'machine_name' => 'library_properties',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
