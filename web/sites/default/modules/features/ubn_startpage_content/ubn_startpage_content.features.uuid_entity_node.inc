<?php
/**
 * @file
 * ubn_startpage_content.features.uuid_entity_node.inc
 */

/**
 * Implements hook_uuid_entity_default_node().
 */
function ubn_startpage_content_uuid_entity_default_node() {
  $items = array();
  $items['56371bfa-65af-430d-8675-cc28b6d78c71'] = entity_create('node', array(
    'uid' => 1,
    'title' => 'Search-widget links',
    'comment' => 0,
    'promote' => 0,
    'sticky' => 0,
    'vuuid' => '912bce02-16a3-4ba6-9d48-c062a68c3982',
    'type' => 'link_list',
    'language' => 'sv',
    'tnid' => 0,
    'translate' => 0,
    'uuid' => '56371bfa-65af-430d-8675-cc28b6d78c71',
    'revision_uid' => 1,
    'field_shortcut_links' => array(
      'sv' => array(
        0 => array(
          'value' => 99218,
          'revision_id' => 103551,
        ),
        1 => array(
          'value' => 99219,
          'revision_id' => 103552,
        ),
        2 => array(
          'value' => 99220,
          'revision_id' => 103553,
        ),
      ),
    ),
    'title_field' => array(
      'sv' => array(
        0 => array(
          'value' => 'Search-widget links',
          'format' => NULL,
          'safe_value' => 'Search-widget links',
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
  ));
  return $items;
}
