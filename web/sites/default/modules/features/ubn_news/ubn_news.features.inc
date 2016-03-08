<?php
/**
 * @file
 * ubn_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ubn_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "scald" && $api == "context_config") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ubn_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ubn_news_image_default_styles() {
  $styles = array();

  // Exported image style: blurb_small.
  $styles['blurb_small'] = array(
    'label' => 'Blurb small',
    'effects' => array(
      1 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 320,
          'height' => 200,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'blurb_small',
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function ubn_news_node_info() {
  $items = array(
    'story' => array(
      'name' => t('Story'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function ubn_news_default_search_api_index() {
  $items = array();
  $items['stories'] = entity_import('search_api_index', '{
    "name" : "Stories",
    "machine_name" : "stories",
    "description" : null,
    "server" : "solr",
    "item_type" : "search_api_et_node",
    "options" : {
      "datasource" : { "bundles" : [ "story" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "created" : { "type" : "date" },
        "search_api_language" : { "type" : "string" }
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
function ubn_news_default_search_api_page() {
  $items = array();
  $items['stories'] = entity_import('search_api_page', '{
    "index_id" : "stories",
    "path" : "news",
    "name" : "Stories",
    "machine_name" : "stories",
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : [],
      "per_page" : "5",
      "result_page_search_form" : 0,
      "get_per_page" : 0,
      "view_mode" : "ubn_search_result",
      "language_filter" : { "current" : "current" },
      "empty_behavior" : "results"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
