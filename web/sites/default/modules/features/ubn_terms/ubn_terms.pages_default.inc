<?php
/**
 * @file
 * ubn_terms.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ubn_terms_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_d53dd498-e5ce-4850-bc6f-d8db313ef48a';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Terms',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'page' => 'page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_uuid:node',
          'settings' => array(
            'uuid' => '9f7228f5-44f9-47f2-8794-2e067eabb2fa',
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol_full';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'promoted_top' => NULL,
      'main_top' => NULL,
      'promoted' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9e165905-a2f6-4db3-8ce7-f335abe9bab6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8770862d-f3e2-4a58-b749-eebaae2c00d5';
    $pane->panel = 'main_top';
    $pane->type = 'terms_search_result';
    $pane->subtype = 'terms_search_result';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '8770862d-f3e2-4a58-b749-eebaae2c00d5';
    $display->content['new-8770862d-f3e2-4a58-b749-eebaae2c00d5'] = $pane;
    $display->panels['main_top'][0] = 'new-8770862d-f3e2-4a58-b749-eebaae2c00d5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_d53dd498-e5ce-4850-bc6f-d8db313ef48a'] = $handler;

  return $export;
}
