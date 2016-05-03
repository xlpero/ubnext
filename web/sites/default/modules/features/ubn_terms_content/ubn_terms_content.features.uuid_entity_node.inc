<?php
/**
 * @file
 * ubn_terms_content.features.uuid_entity_node.inc
 */

/**
 * Implements hook_uuid_entity_default_node().
 */
function ubn_terms_content_uuid_entity_default_node() {
  $items = array();
  $items['9f7228f5-44f9-47f2-8794-2e067eabb2fa'] = entity_create('node', array(
    'uid' => 1,
    'title' => 'Så hittar du',
    'comment' => 0,
    'promote' => 0,
    'sticky' => 0,
    'vuuid' => '067cbe1a-a9bd-460f-9b43-307e333efe7b',
    'type' => 'page',
    'language' => 'sv',
    'tnid' => 0,
    'translate' => 0,
    'uuid' => '9f7228f5-44f9-47f2-8794-2e067eabb2fa',
    'revision_uid' => 1,
    'title_field' => array(
      'en' => array(
        0 => array(
          'value' => 'How to find',
          'format' => NULL,
          'safe_value' => 'How to find',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Så hittar du',
          'format' => NULL,
          'safe_value' => 'Så hittar du',
        ),
      ),
    ),
    'field_lead' => array(),
    'field_template' => array(),
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
