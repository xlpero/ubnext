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
  $items['e5180327-a052-4a35-882b-2f0852935fe3'] = entity_create('node', array(
    'uid' => '12fd9141-f2d1-4774-8caf-d9d721b8fc92',
    'title' => 'Kontakta oss',
    'comment' => 0,
    'promote' => 0,
    'sticky' => 0,
    'vuuid' => '235dd6b4-d2a8-4a55-b887-4019a821e32a',
    'type' => 'page',
    'language' => 'sv',
    'tnid' => 0,
    'translate' => 0,
    'uuid' => 'e5180327-a052-4a35-882b-2f0852935fe3',
    'revision_uid' => 1,
    'title_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Contact us',
          'format' => NULL,
          'safe_value' => 'Contact us',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Kontakta oss',
          'format' => NULL,
          'safe_value' => 'Kontakta oss',
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
    '_drafty_revision_requested' => 'FIELD_LOAD_CURRENT',
    'name' => 'xkumag',
    'picture' => 0,
    'data' => 'b:0;',
    'published_at' => 1466672556,
  ));
  return $items;
}
