<?php
/**
 * @file
 * ubn_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ubn_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function ubn_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "page", "database", "library" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_alternate_titles" : { "type" : "list\\u003Ctext\\u003E" },
        "field_description_paragraphs" : { "type" : "list\\u003Ctext\\u003E" },
        "field_media_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_public_access" : { "type" : "boolean" },
        "field_publishers" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_topics" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "title_field" : { "type" : "text" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_page().
 */
function ubn_search_default_search_api_page() {
  $items = array();
  $items['site'] = entity_import('search_api_page', '{
    "index_id" : "default_node_index",
    "path" : "search",
    "name" : "Site search",
    "machine_name" : "site",
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : {
        "field_alternate_titles" : "field_alternate_titles",
        "field_description_paragraphs" : "field_description_paragraphs",
        "title_field" : "title_field"
      },
      "per_page" : "30",
      "result_page_search_form" : 1,
      "get_per_page" : 0,
      "view_mode" : "search_api_page_result",
      "language_filter" : { "current" : "current", "und" : "und" },
      "empty_behavior" : "results"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function ubn_search_default_search_api_server() {
  $items = array();
  $items['solr'] = entity_import('search_api_server', '{
    "name" : "Solr",
    "machine_name" : "solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "130.241.35.208",
      "port" : "8080",
      "path" : "\\/solr\\/drupal7_ubnext_xgudav",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 1,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "4",
      "http_method" : "AUTO"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
