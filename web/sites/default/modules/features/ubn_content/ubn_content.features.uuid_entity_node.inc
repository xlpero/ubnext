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
    'title' => 'Öppettider och bibliotek',
    'comment' => 1,
    'promote' => 0,
    'sticky' => 0,
    'vuuid' => '29f9a8e5-9c6f-46b1-ad1c-7de578e44d6b',
    'type' => 'page',
    'language' => 'en',
    'tnid' => 0,
    'translate' => 0,
    'uuid' => 'f8bcf20f-d066-41fc-9e41-c1b3d97dccee',
    'revision_uid' => 'de1595b5-ab7c-435e-b64b-6c863453b2de',
    'title_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Opening hours and libraries',
          'format' => NULL,
          'safe_value' => 'Opening hours and libraries',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Öppettider och bibliotek',
          'format' => NULL,
          'safe_value' => 'Öppettider och bibliotek',
        ),
      ),
    ),
    'field_lead' => array(
      'en' => array(
        0 => array(
          'value' => 'There are seven libraries and one learning centre which together constitute Gothenburg University Library.',
          'format' => NULL,
          'safe_value' => 'There are seven libraries and one learning centre which together constitute Gothenburg University Library.',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Göteborgs universitetsbibliotek består av sju bibliotek och ett studietorg.',
          'format' => NULL,
          'safe_value' => 'Göteborgs universitetsbibliotek består av sju bibliotek och ett studietorg.',
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
        'sv' => array(
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    '_drafty_revision_requested' => 'FIELD_LOAD_CURRENT',
    'name' => 'admin',
    'picture' => 0,
    'data' => 'b:0;',
    'published_at' => 1461055778,
  ));
  return $items;
}
