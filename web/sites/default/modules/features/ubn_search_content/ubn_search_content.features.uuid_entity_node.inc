<?php
/**
 * @file
 * ubn_search_content.features.uuid_entity_node.inc
 */

/**
 * Implements hook_uuid_entity_default_node().
 */
function ubn_search_content_uuid_entity_default_node() {
  $items = array();
  $items['b1961886-660a-4c82-a142-518506df8a05'] = entity_create('node', array(
    'uid' => 1,
    'title' => 'Databaser',
    'comment' => 0,
    'promote' => 1,
    'sticky' => 0,
    'vuuid' => '47e11c22-b26e-448b-91f0-d8cc12a4d6bf',
    'type' => 'embedded_page',
    'language' => 'sv',
    'tnid' => 0,
    'translate' => 0,
    'uuid' => 'b1961886-660a-4c82-a142-518506df8a05',
    'revision_uid' => 1,
    'title_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Databases',
          'format' => NULL,
          'safe_value' => 'Databases',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Databaser',
          'format' => NULL,
          'safe_value' => 'Databaser',
        ),
      ),
    ),
    'field_lead' => array(),
    'field_content_sections' => array(),
    'translations' => array(
      'original' => 'sv',
      'data' => array(
        'en' => array(
          'language' => 'en',
          'source' => 'sv',
          'status' => 1,
          'translate' => 0,
        ),
        'sv' => array(
          'language' => 'sv',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'name' => 'admin',
    'picture' => 0,
    'data' => 'b:0;',
  ));
  return $items;
}
