<?php
/**
 * @file
 * ubn_content.features.uuid_entity_node.inc
 */

/**
 * Implements hook_uuid_entity_default_node().
 */
function ubn_content_uuid_entity_default_node() {
  $items = array();
  $items['84551f72-f8f7-43fc-b4f0-020e0ed5af2a'] = entity_create('node', array(
    'uid' => 1,
    'title' => 'Search',
    'comment' => 1,
    'promote' => 0,
    'sticky' => 0,
    'vuuid' => 'f0e4972d-3091-46e0-b232-4f470446bdbb',
    'type' => 'navigation_landing',
    'language' => 'sv',
    'tnid' => 0,
    'translate' => 0,
    'uuid' => '84551f72-f8f7-43fc-b4f0-020e0ed5af2a',
    'revision_uid' => 1,
    'field_lead' => array(),
    'title_field' => array(
      'sv' => array(
        0 => array(
          'value' => 'Search',
          'format' => NULL,
          'safe_value' => 'Search',
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
        'sv' => array(
          'language' => 'sv',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'path' => array(
      'pathauto' => 1,
      'pathauto_i18n_status' => 1,
    ),
    'name' => 'admin',
    'picture' => 0,
    'data' => 'b:0;',
  ));
  $items['b1961886-660a-4c82-a142-518506df8a05'] = entity_create('node', array(
    'uid' => 1,
    'title' => 'Databases',
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
        'sv' => array(
          'language' => 'sv',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
        'en' => array(
          'language' => 'en',
          'source' => 'sv',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'path' => array(
      'pathauto' => 1,
      'pathauto_i18n_status' => 1,
    ),
    'name' => 'admin',
    'picture' => 0,
    'data' => 'b:0;',
  ));
  $items['f8bcf20f-d066-41fc-9e41-c1b3d97dccee'] = entity_create('node', array(
    'uid' => 1,
    'title' => 'Libraries',
    'comment' => 1,
    'promote' => 0,
    'sticky' => 0,
    'vuuid' => 'a7f7b1c9-a2d5-4616-894b-1b15a4e4ea60',
    'type' => 'page',
    'language' => 'en',
    'tnid' => 0,
    'translate' => 0,
    'uuid' => 'f8bcf20f-d066-41fc-9e41-c1b3d97dccee',
    'revision_uid' => 1,
    'title_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Libraries',
          'format' => NULL,
          'safe_value' => 'Libraries',
        ),
      ),
    ),
    'field_lead' => array(
      'en' => array(
        0 => array(
          'value' => 'This is a list of our libraries',
          'format' => NULL,
          'safe_value' => 'This is a list of our libraries',
        ),
      ),
    ),
    'field_content_sections' => array(),
    'field_referenced_app' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'path' => array(
      'pathauto' => 1,
      'pathauto_i18n_status' => 1,
    ),
    'name' => 'admin',
    'picture' => 0,
    'data' => 'b:0;',
  ));
  return $items;
}
