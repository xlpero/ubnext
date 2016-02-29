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
  $items['d869e9b9-2268-4ad0-9fc7-4547e311dac1'] = entity_create('node', array(
   'uid' => 1,
   'title' => 'Search the Library',
   'comment' => 1,
   'promote' => 0,
   'sticky' => 0,
   'vuuid' => '419204ad-30b1-4916-ae29-b5d58ab8b0d9',
   'type' => 'page',
   'language' => 'en',
   'tnid' => 0,
   'translate' => 0,
   'uuid' => 'd869e9b9-2268-4ad0-9fc7-4547e311dac1',
   'revision_uid' => 1,
   'field_lead' => array(),
   'title_field' => array(
     'en' => array(
       0 => array(
         'value' => 'Search the Library',
         'format' => NULL,
         'safe_value' => 'Search the Library',
       ),
     ),
   ),
   'field_content_sections' => array(),
   'field_template' => array(),
   'field_referenced_app' => array(),
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
