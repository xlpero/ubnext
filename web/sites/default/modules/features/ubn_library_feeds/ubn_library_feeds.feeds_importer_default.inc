<?php
/**
 * @file
 * ubn_library_feeds.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ubn_library_feeds_feeds_importer_default() {
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
        'request_timeout' => '120',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsJSONPathParser',
      'config' => array(
        'context' => '$.locations.*',
        'sources' => array(
          'jsonpath_parser:0' => 'id',
        ),
        'debug' => array(
          'options' => array(
            'context' => 0,
            'jsonpath_parser:0' => 0,
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
        ),
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'library',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['libraries_opening_hours'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'libraries_opening_hours_field_collection';
  $feeds_importer->config = array(
    'name' => 'Libraries opening hours field-collection',
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
        'context' => '$.locations[*].openhours[*].',
        'sources' => array(
          'jsonpath_parser:1' => 'id',
          'jsonpath_parser:0' => 'location_id',
          'jsonpath_parser:2' => 'timestamps.open',
          'jsonpath_parser:3' => 'timestamps.close',
          'jsonpath_parser:4' => 'date',
          'jsonpath_parser:6' => 'is_open',
          'jsonpath_parser:7' => 'is_exception',
        ),
        'debug' => array(
          'options' => array(
            'context' => 0,
            'jsonpath_parser:1' => 0,
            'jsonpath_parser:0' => 0,
            'jsonpath_parser:2' => 0,
            'jsonpath_parser:3' => 0,
            'jsonpath_parser:4' => 0,
            'jsonpath_parser:6' => 0,
            'jsonpath_parser:7' => 0,
          ),
        ),
        'allow_override' => 0,
        'convert_four_byte' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFieldCollectionProcessor',
      'config' => array(
        'field_name' => 'field_opening_hours',
        'host_entity_type' => 'node',
        'is_field' => 0,
        'guid_field_name' => '',
        'mappings' => array(
          0 => array(
            'source' => 'jsonpath_parser:1',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'jsonpath_parser:0',
            'target' => 'host_entity_guid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'jsonpath_parser:2',
            'target' => 'field_opening_hours_datetime:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'field_opening_hours_datetime:end',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'jsonpath_parser:4',
            'target' => 'field_opening_hours_date:start',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'jsonpath_parser:6',
            'target' => 'field_opening_hours_is_open',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'jsonpath_parser:7',
            'target' => 'field_opening_hours_is_exception',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'field_opening_hours',
        'host_entity_importer_id' => 'libraries_opening_hours',
        'host_entity_importer_nid' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['libraries_opening_hours_field_collection'] = $feeds_importer;

  return $export;
}
