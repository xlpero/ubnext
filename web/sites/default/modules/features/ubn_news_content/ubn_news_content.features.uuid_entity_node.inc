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
    'vuuid' => 'a64b50dd-2528-4afe-a0a8-684123da415b',
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
    'path' => array(
      'pathauto' => 1,
      'pathauto_i18n_status' => 1,
    ),
    'cid' => 0,
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'comment_count' => 0,
    'name' => 'admin',
    'picture' => 0,
    'data' => 'b:0;',
  ));
  return $items;
}
