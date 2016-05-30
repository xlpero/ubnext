<?php
/**
 * @file
 * ubn_startpage.features.uuid_entity_node.inc
 */

/**
 * Implements hook_uuid_entity_default_node().
 */
function ubn_startpage_uuid_entity_default_node() {
  $items = array();
  $items['4292e4cb-a82f-4ba3-a468-41c7ac7b70f5'] = entity_create('node', array(
    'uid' => 1,
    'title' => 'Senaste nyheter länkar',
    'comment' => 0,
    'promote' => 0,
    'sticky' => 0,
    'vuuid' => '895b6505-73b0-4317-9931-3ad29eda0285',
    'type' => 'link_list',
    'language' => 'sv',
    'tnid' => 0,
    'translate' => 0,
    'uuid' => '4292e4cb-a82f-4ba3-a468-41c7ac7b70f5',
    'revision_uid' => 1,
    'title_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Senaste nyheter länkar',
          'format' => NULL,
          'safe_value' => 'Senaste nyheter länkar',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Senaste nyheter länkar',
          'format' => NULL,
          'safe_value' => 'Senaste nyheter länkar',
        ),
      ),
    ),
    'field_shortcut_links' => array(
      'en' => array(
        0 => array(
          'value' => 10503,
          'revision_id' => 10503,
        ),
        1 => array(
          'value' => 10504,
          'revision_id' => 10504,
        ),
      ),
    ),
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
