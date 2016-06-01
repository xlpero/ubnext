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
    'field_lead' => array(
      'en' => array(
        0 => array(
          'value' => 'This is a list of our libraries',
          'format' => NULL,
          'safe_value' => 'This is a list of our libraries',
        ),
      ),
    ),
    'title_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Libraries',
          'format' => NULL,
          'safe_value' => 'Libraries',
        ),
      ),
    ),
    'field_content_sections' => array(
      'en' => array(
        0 => array(
          'value' => 10360,
          'revision_id' => 10360,
        ),
        1 => array(
          'value' => 10361,
          'revision_id' => 10361,
        ),
      ),
    ),
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
    '_drafty_revision_requested' => 'FIELD_LOAD_CURRENT',
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
