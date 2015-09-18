<?php
/**
 * @file
 * ubn_feeds.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ubn_feeds_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'libraries_opening_hours';
  $feeds_importer->config = array(
    'name' => 'Libraries opening hours',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'UBNOpeningHoursFeedsFetcher',
      'config' => array(
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsJSONPathParser',
      'config' => array(
        'context' => '$.locations.*',
        'sources' => array(
          'jsonpath_parser:0' => 'id',
          'jsonpath_parser:1' => 'name',
          'jsonpath_parser:2' => 'openhours[*].id',
          'jsonpath_parser:3' => 'openhours[*].timestamps.open',
          'jsonpath_parser:4' => 'openhours[*].timestamps.close',
          'jsonpath_parser:5' => 'openhours[*].is_exception',
          'jsonpath_parser:6' => 'openhours[*].is_open',
          'jsonpath_parser:7' => 'openhours[*].date',
        ),
        'debug' => array(
          'options' => array(
            'context' => 0,
            'jsonpath_parser:0' => 0,
            'jsonpath_parser:1' => 0,
            'jsonpath_parser:2' => 0,
            'jsonpath_parser:3' => 0,
            'jsonpath_parser:4' => 0,
            'jsonpath_parser:5' => 0,
            'jsonpath_parser:6' => 0,
            'jsonpath_parser:7' => 0,
          ),
        ),
        'allow_override' => 0,
        'convert_four_byte' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'jsonpath_parser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'jsonpath_parser:1',
            'target' => 'title_field',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'jsonpath_parser:2',
            'target' => 'field_referenced_opening_hours:opening_hours:entityreference_feeds:guid',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'field_referenced_opening_hours:opening_hours:date_feeds_set_target:field_opening_hours:start',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'jsonpath_parser:4',
            'target' => 'field_referenced_opening_hours:opening_hours:date_feeds_set_target:field_opening_hours:end',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'jsonpath_parser:5',
            'target' => 'field_referenced_opening_hours:opening_hours:list_feeds_set_boolean_target:field_opening_hours_is_exception',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'jsonpath_parser:6',
            'target' => 'field_referenced_opening_hours:opening_hours:list_feeds_set_boolean_target:field_opening_hours_is_open',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'jsonpath_parser:7',
            'target' => 'field_referenced_opening_hours:opening_hours:text_feeds_set_target:title_field',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'library',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '3600',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['libraries_opening_hours'] = $feeds_importer;

  return $export;
}
