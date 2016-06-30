<?php
/**
 * @file
 * ubn_feeds.feeds_source_default.inc
 */

/**
 * Implements hook_feeds_source_default().
 */
function ubn_feeds_feeds_source_default() {
  $export = array();

  $feeds_source = new stdClass();
  $feeds_source->disabled = FALSE; /* Edit this to true to make a default feeds_source disabled initially */
  $feeds_source->api_version = 1;
  $feeds_source->id = 'database_urls_field_collection';
  $feeds_source->feed_nid = 0;
  $feeds_source->config = array(
    'UBNDatabasesUrlsFeedsFetcher' => array(
      'source' => 'pgsql:host=130.241.16.44;port=5432;dbname=librisdb;user=xgudav',
    ),
  );
  $feeds_source->source = 'pgsql:host=130.241.16.44;port=5432;dbname=librisdb;user=xgudav';
  $export['database_urls_field_collection'] = $feeds_source;

  $feeds_source = new stdClass();
  $feeds_source->disabled = FALSE; /* Edit this to true to make a default feeds_source disabled initially */
  $feeds_source->api_version = 1;
  $feeds_source->id = 'databases';
  $feeds_source->feed_nid = 0;
  $feeds_source->config = array(
    'UBNDatabasesFeedsFetcher' => array(
      'source' => 'pgsql:host=130.241.16.44;port=5432;dbname=librisdb;user=xgudav',
    ),
  );
  $feeds_source->source = 'pgsql:host=130.241.16.44;port=5432;dbname=librisdb;user=xgudav';
  $export['databases'] = $feeds_source;

  $feeds_source = new stdClass();
  $feeds_source->disabled = FALSE; /* Edit this to true to make a default feeds_source disabled initially */
  $feeds_source->api_version = 1;
  $feeds_source->id = 'databases_categories';
  $feeds_source->feed_nid = 0;
  $feeds_source->config = array(
    'UBNDatabasesCategoriesFeedsFetcher' => array(
      'source' => 'pgsql:host=130.241.16.44;port=5432;dbname=librisdb;user=xgudav',
    ),
  );
  $feeds_source->source = 'pgsql:host=130.241.16.44;port=5432;dbname=librisdb;user=xgudav';
  $export['databases_categories'] = $feeds_source;

  $feeds_source = new stdClass();
  $feeds_source->disabled = FALSE; /* Edit this to true to make a default feeds_source disabled initially */
  $feeds_source->api_version = 1;
  $feeds_source->id = 'databases_topics';
  $feeds_source->feed_nid = 0;
  $feeds_source->config = array(
    'UBNDatabasesKeywordsFeedsFetcher' => array(
      'source' => 'pgsql:host=130.241.16.44;port=5432;dbname=librisdb;user=xgudav',
    ),
  );
  $feeds_source->source = 'pgsql:host=130.241.16.44;port=5432;dbname=librisdb;user=xgudav';
  $export['databases_topics'] = $feeds_source;

  return $export;
}
