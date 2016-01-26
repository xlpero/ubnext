<?php
/**
 * @file
 * ubn_search.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ubn_search_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@databases';
  $strongarm->value = '-1';
  $export['facetapi:block_cache:search_api@databases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@default_node_index';
  $strongarm->value = -1;
  $export['facetapi:block_cache:search_api@default_node_index'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_facets_search_ids';
  $strongarm->value = array(
    'default_node_index' => array(
      'search_api_page:site' => 'search_api_page:site',
      'search_api_page:search' => 'search_api_page:search',
      'search_api_autocomplete:search_api_page_site' => 'search_api_autocomplete:search_api_page_site',
      'search_api_page:search/site' => 'search_api_page:search/site',
    ),
    'databases' => array(
      'search_api_page:search/databases' => 'search_api_page:search/databases',
      'search_api_autocomplete:search_api_page_databases' => 'search_api_autocomplete:search_api_page_databases',
    ),
  );
  $export['search_api_facets_search_ids'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_page_search_api_page_disabled_databases';
  $strongarm->value = FALSE;
  $export['search_api_page_search_api_page_disabled_databases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_page_search_api_page_disabled_site';
  $strongarm->value = FALSE;
  $export['search_api_page_search_api_page_disabled_site'] = $strongarm;

  return $export;
}
