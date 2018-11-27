<?php
/**
 * @file
 * ubn_news_content.features.uuid_entity_node.inc
 */

/**
 * Implements hook_uuid_entity_default_node().
 */
function ubn_news_content_uuid_entity_default_node() {
  $items = array();
  $items['8271cd94-aa97-450f-acd3-2956cf1bb5bc'] = entity_create('node', array(
    'uid' => 1,
    'title' => 'News',
    'comment' => 2,
    'promote' => 1,
    'sticky' => 0,
    'vuuid' => '4581cac7-27f5-4698-bb21-673ea1bda5f9',
    'type' => 'embedded_page',
    'language' => 'sv',
    'tnid' => 0,
    'translate' => 0,
    'uuid' => '8271cd94-aa97-450f-acd3-2956cf1bb5bc',
    'revision_uid' => 1,
    'field_content_sections' => array(),
    'field_lead' => array(
      'sv' => array(
        0 => array(
          'value' => 'This is news lead',
          'format' => NULL,
          'safe_value' => 'This is news lead',
        ),
      ),
    ),
    'title_field' => array(
      'sv' => array(
        0 => array(
          'value' => 'News',
          'format' => NULL,
          'safe_value' => 'News',
        ),
      ),
    ),
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
    '_drafty_revision_requested' => 'FIELD_LOAD_CURRENT',
    'name' => 'admin',
    'picture' => 0,
    'data' => 'b:0;',
    'published_at' => 0,
  ));
  return $items;
}
