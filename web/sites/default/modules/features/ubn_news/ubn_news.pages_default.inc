<?php
/**
 * @file
 * ubn_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ubn_news_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'search_api_page_stories__panel_context_0eb0f05a-df43-4283-b1ea-7e7bc4f5bade';
  $handler->task = 'search_api_page';
  $handler->subtask = 'stories';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Search',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a0e72b8b-9862-40cf-a574-a424253ccee2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-122b7a81-0da1-4a89-9f24-10646fa7c723';
    $pane->panel = 'main';
    $pane->type = 'search_api_page_result';
    $pane->subtype = 'search_api_page_result';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'page' => 'stories',
      'per_page' => '30',
      'result_page_search_form' => 0,
      'get_per_page' => 0,
      'view_mode' => 'ubn_search_result',
      'context' => 'argument_string_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '122b7a81-0da1-4a89-9f24-10646fa7c723';
    $display->content['new-122b7a81-0da1-4a89-9f24-10646fa7c723'] = $pane;
    $display->panels['main'][0] = 'new-122b7a81-0da1-4a89-9f24-10646fa7c723';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_api_page_stories__panel_context_0eb0f05a-df43-4283-b1ea-7e7bc4f5bade'] = $handler;

  return $export;
}
