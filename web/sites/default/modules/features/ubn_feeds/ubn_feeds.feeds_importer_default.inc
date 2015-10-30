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
  $feeds_importer->id = 'database_urls_field_collection';
  $feeds_importer->config = array(
    'name' => 'Database urls field-collection',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'UBNDatabasesUrlsFeedsFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsJSONPathParser',
      'config' => array(
        'context' => '$.*',
        'sources' => array(
          'jsonpath_parser:0' => 'guid',
          'jsonpath_parser:1' => 'database_id',
          'jsonpath_parser:2' => 'id',
          'jsonpath_parser:3' => 'access_description.description.und',
          'jsonpath_parser:4' => 'url',
          'jsonpath_parser:5' => 'description',
          'jsonpath_parser:6' => 'public_access',
          'jsonpath_parser:7' => 'id',
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
      'plugin_key' => 'FeedsFieldCollectionProcessor',
      'config' => array(
        'field_name' => 'field_database_urls',
        'host_entity_type' => 'node',
        'is_field' => 1,
        'guid_field_name' => 'field_remote_id',
        'mappings' => array(
          0 => array(
            'source' => 'jsonpath_parser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'jsonpath_parser:1',
            'target' => 'host_entity_guid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'jsonpath_parser:2',
            'target' => 'identifier_field',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'field_description_short',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'jsonpath_parser:4',
            'target' => 'field_url:url',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'jsonpath_parser:5',
            'target' => 'field_url:title',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'jsonpath_parser:6',
            'target' => 'field_public_access',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'jsonpath_parser:7',
            'target' => 'field_remote_id',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'field_database_urls',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['database_urls_field_collection'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'databases';
  $feeds_importer->config = array(
    'name' => 'Databases',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'UBNDatabasesFeedsFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsJSONPathParser',
      'config' => array(
        'context' => '$.*',
        'sources' => array(
          'jsonpath_parser:0' => 'publishers',
          'jsonpath_parser:1' => 'guid',
          'jsonpath_parser:2' => 'title',
          'jsonpath_parser:3' => 'descriptions',
          'jsonpath_parser:4' => 'alternate_titles',
          'jsonpath_parser:5' => 'keywords[*].guid',
          'jsonpath_parser:6' => 'categories[*].guid',
          'jsonpath_parser:8' => 'public_access',
          'jsonpath_parser:9' => 'id',
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
            'jsonpath_parser:8' => 0,
            'jsonpath_parser:9' => 0,
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
            'target' => 'field_publishers',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          1 => array(
            'source' => 'jsonpath_parser:1',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'jsonpath_parser:2',
            'target' => 'title_field',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'field_description_paragraphs',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'jsonpath_parser:4',
            'target' => 'field_alternate_titles',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'jsonpath_parser:5',
            'target' => 'field_topics',
            'term_search' => '2',
            'autocreate' => 0,
          ),
          6 => array(
            'source' => 'jsonpath_parser:6',
            'target' => 'field_media_types',
            'term_search' => '2',
            'autocreate' => 0,
          ),
          7 => array(
            'source' => 'jsonpath_parser:8',
            'target' => 'field_public_access',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'jsonpath_parser:9',
            'target' => 'field_remote_id',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'database',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['databases'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'databases_categories';
  $feeds_importer->config = array(
    'name' => 'Databases categories',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'UBNDatabasesCategoriesFeedsFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsJSONPathParser',
      'config' => array(
        'context' => '$.*',
        'sources' => array(
          'jsonpath_parser:0' => 'guid',
          'jsonpath_parser:2' => 'name.en',
          'jsonpath_parser:3' => 'name.en',
        ),
        'debug' => array(
          'options' => array(
            'context' => 0,
            'jsonpath_parser:0' => 0,
            'jsonpath_parser:2' => 0,
            'jsonpath_parser:3' => 0,
          ),
        ),
        'allow_override' => 0,
        'convert_four_byte' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'jsonpath_parser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'jsonpath_parser:2',
            'target' => 'name_field',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'name',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'media_types',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '21600',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['databases_categories'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'databases_topics';
  $feeds_importer->config = array(
    'name' => 'Databases topics',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'UBNDatabasesKeywordsFeedsFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsJSONPathParser',
      'config' => array(
        'context' => '$.*',
        'sources' => array(
          'jsonpath_parser:0' => 'guid',
          'jsonpath_parser:1' => 'parent_guid',
          'jsonpath_parser:3' => 'name.en',
          'jsonpath_parser:4' => 'name.en',
        ),
        'debug' => array(
          'options' => array(
            'context' => 0,
            'jsonpath_parser:0' => 0,
            'jsonpath_parser:1' => 0,
            'jsonpath_parser:3' => 0,
            'jsonpath_parser:4' => 0,
          ),
        ),
        'allow_override' => 0,
        'convert_four_byte' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'jsonpath_parser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'jsonpath_parser:1',
            'target' => 'parentguid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'name_field',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'jsonpath_parser:4',
            'target' => 'name',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'topics',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['databases_topics'] = $feeds_importer;

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
          'jsonpath_parser:2' => 'openhours[*].id',
          'jsonpath_parser:3' => 'openhours[*].timestamps.open',
          'jsonpath_parser:4' => 'openhours[*].timestamps.close',
          'jsonpath_parser:5' => 'openhours[*].is_exception',
          'jsonpath_parser:6' => 'openhours[*].is_open',
          'jsonpath_parser:7' => 'openhours[*].date',
          'jsonpath_parser:8' => 'openhours[*].date',
          'jsonpath_parser:9' => 'lang',
        ),
        'debug' => array(
          'options' => array(
            'context' => 0,
            'jsonpath_parser:0' => 0,
            'jsonpath_parser:2' => 0,
            'jsonpath_parser:3' => 0,
            'jsonpath_parser:4' => 0,
            'jsonpath_parser:5' => 0,
            'jsonpath_parser:6' => 0,
            'jsonpath_parser:7' => 0,
            'jsonpath_parser:8' => 0,
            'jsonpath_parser:9' => 0,
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
            'source' => 'jsonpath_parser:2',
            'target' => 'field_referenced_opening_hours:opening_hours:entityreference_feeds:guid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'field_referenced_opening_hours:opening_hours:date_feeds_set_target:field_opening_hours:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'jsonpath_parser:4',
            'target' => 'field_referenced_opening_hours:opening_hours:date_feeds_set_target:field_opening_hours:end',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'jsonpath_parser:5',
            'target' => 'field_referenced_opening_hours:opening_hours:list_feeds_set_boolean_target:field_opening_hours_is_exception',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'jsonpath_parser:6',
            'target' => 'field_referenced_opening_hours:opening_hours:list_feeds_set_boolean_target:field_opening_hours_is_open',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'jsonpath_parser:7',
            'target' => 'field_referenced_opening_hours:opening_hours:text_feeds_set_target:title_field',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'jsonpath_parser:8',
            'target' => 'field_referenced_opening_hours:opening_hours:date_feeds_set_target:field_opening_hours_date:start',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'jsonpath_parser:9',
            'target' => 'language',
            'unique' => FALSE,
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

  return $export;
}
