<?php
/**
 * @file
 * ubn_app.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ubn_app_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'App',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'app' => 'app',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol_app';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
    'main' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6214738b-6a88-4ca3-87b2-258e50655014';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f5d40f65-b077-4d27-8d65-899b1e9554e6';
    $pane->panel = 'main';
    $pane->type = 'app_view';
    $pane->subtype = 'app_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f5d40f65-b077-4d27-8d65-899b1e9554e6';
    $display->content['new-f5d40f65-b077-4d27-8d65-899b1e9554e6'] = $pane;
    $display->panels['main'][0] = 'new-f5d40f65-b077-4d27-8d65-899b1e9554e6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  return $export;
}
