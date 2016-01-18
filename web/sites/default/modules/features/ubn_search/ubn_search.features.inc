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
 * Implements hook_default_search_api_autocomplete_search().
 */
function ubn_search_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_page_databases'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_page_databases",
    "name" : "Databases",
    "index_id" : "databases",
    "suggester_id" : "",
    "type" : "search_api_page",
    "enabled" : "1",
    "options" : {
      "custom" : { "page_id" : "databases" },
      "results" : true,
      "fields" : []
    },
    "rdf_mapping" : []
  }');
  $items['search_api_page_site'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_page_site",
    "name" : "Site search",
    "index_id" : "default_node_index",
    "suggester_id" : "server",
    "type" : "search_api_page",
    "enabled" : "1",
    "options" : {
      "suggester_configuration" : { "fields" : [] },
      "min_length" : "1",
      "results" : 1,
      "submit_button_selector" : ":submit",
      "autosubmit" : 1,
      "custom" : { "page_id" : "site" }
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function ubn_search_default_search_api_index() {
  $items = array();
  $items['databases'] = entity_import('search_api_index', '{
    "name" : "Databases",
    "machine_name" : "databases",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "database" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_alternate_titles" : { "type" : "list\\u003Ctext\\u003E" },
        "field_description_paragraphs" : { "type" : "list\\u003Ctext\\u003E" },
        "field_media_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_public_access" : { "type" : "boolean" },
        "field_publishers" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_topics_depth_0" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_topics_depth_1" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "search_api_aggregation_1" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "title_field" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "A-Z",
                "type" : "first_char",
                "fields" : [ "title_field" ],
                "description" : "A First letter aggregation of the following fields: Title."
              }
            }
          }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title_field" : true,
              "field_description_paragraphs" : true,
              "field_alternate_titles" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title_field" : true,
              "field_description_paragraphs" : true,
              "field_alternate_titles" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "title_field" : true,
              "field_description_paragraphs" : true,
              "field_alternate_titles" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title_field" : true,
              "field_description_paragraphs" : true,
              "field_alternate_titles" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title_field" : true,
              "field_description_paragraphs" : true,
              "field_alternate_titles" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
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
        "field_topics_depth_0" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_topics_depth_1" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "search_api_aggregation_1" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "title_field" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "taxonomy_test",
                "type" : "list",
                "fields" : [ "field_topics" ],
                "description" : "A List aggregation of the following fields: Topics."
              }
            }
          }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title_field" : true,
              "field_description_paragraphs" : true,
              "field_alternate_titles" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title_field" : true,
              "field_description_paragraphs" : true,
              "field_alternate_titles" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "title_field" : true,
              "field_description_paragraphs" : true,
              "field_alternate_titles" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title_field" : true,
              "field_description_paragraphs" : true,
              "field_alternate_titles" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title_field" : true,
              "field_description_paragraphs" : true,
              "field_alternate_titles" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
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
  $items['databases'] = entity_import('search_api_page', '{
    "index_id" : "databases",
    "path" : "search\\/databases",
    "name" : "Databases",
    "machine_name" : "databases",
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : [],
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
  $items['site'] = entity_import('search_api_page', '{
    "index_id" : "default_node_index",
    "path" : "search\\/site",
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
