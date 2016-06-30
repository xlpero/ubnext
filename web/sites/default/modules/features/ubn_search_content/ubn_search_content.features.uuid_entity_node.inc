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
  $items['734a67d4-1f57-4517-8ce7-17344f5d4f3e'] = entity_create('node', array(
    'uid' => 1,
    'title' => 'Databaser',
    'comment' => 0,
    'promote' => 0,
    'sticky' => 0,
    'vuuid' => 'e480c08d-2617-4c88-a855-04b535d2ae67',
    'type' => 'page',
    'language' => 'sv',
    'tnid' => 0,
    'translate' => 0,
    'uuid' => '734a67d4-1f57-4517-8ce7-17344f5d4f3e',
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
    'field_referenced_app' => array(),
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
  $items['84551f72-f8f7-43fc-b4f0-020e0ed5af2a'] = entity_create('node', array(
    'uid' => 1,
    'title' => 'Hitta',
    'comment' => 1,
    'promote' => 0,
    'sticky' => 0,
    'vuuid' => 'b8aede86-125c-4de4-92ea-58ce805a8206',
    'type' => 'navigation_landing',
    'language' => 'sv',
    'tnid' => 0,
    'translate' => 0,
    'uuid' => '84551f72-f8f7-43fc-b4f0-020e0ed5af2a',
    'revision_uid' => 1,
    'field_lead' => array(),
    'title_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Find',
          'format' => NULL,
          'safe_value' => 'Find',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Hitta',
          'format' => NULL,
          'safe_value' => 'Hitta',
        ),
      ),
    ),
    'field_number_of_primary' => array(),
    'field_shortcut_heading' => array(),
    'field_shortcut_links' => array(),
    'field_theme_link' => array(),
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
