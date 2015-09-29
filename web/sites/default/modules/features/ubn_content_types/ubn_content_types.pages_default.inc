<?php
/**
 * @file
 * ubn_content_types.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ubn_content_types_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_82ceb8b0-698d-46b3-be21-84443486cc68';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Library',
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
              'library' => 'library',
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
  $display->layout = 'onecol_full';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'adfea7ec-d162-4654-924b-c8f3de79e664';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8e9b4850-b148-48e1-972b-0f5c45533bb6';
    $pane->panel = 'main';
    $pane->type = 'slate_render';
    $pane->subtype = 'slate_render:page-head';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
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
    $pane->uuid = '8e9b4850-b148-48e1-972b-0f5c45533bb6';
    $display->content['new-8e9b4850-b148-48e1-972b-0f5c45533bb6'] = $pane;
    $display->panels['main'][0] = 'new-8e9b4850-b148-48e1-972b-0f5c45533bb6';
    $pane = new stdClass();
    $pane->pid = 'new-cdd46a6d-aef5-47ef-9bcf-d7004c9e5d5a';
    $pane->panel = 'main';
    $pane->type = 'slate_render';
    $pane->subtype = 'slate_render:library-opening-hours-banner';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cdd46a6d-aef5-47ef-9bcf-d7004c9e5d5a';
    $display->content['new-cdd46a6d-aef5-47ef-9bcf-d7004c9e5d5a'] = $pane;
    $display->panels['main'][1] = 'new-cdd46a6d-aef5-47ef-9bcf-d7004c9e5d5a';
    $pane = new stdClass();
    $pane->pid = 'new-217fa725-6299-4cb1-b2db-73f5b664930a';
    $pane->panel = 'main';
    $pane->type = 'slate_render';
    $pane->subtype = 'slate_render:hero-image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '217fa725-6299-4cb1-b2db-73f5b664930a';
    $display->content['new-217fa725-6299-4cb1-b2db-73f5b664930a'] = $pane;
    $display->panels['main'][2] = 'new-217fa725-6299-4cb1-b2db-73f5b664930a';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_82ceb8b0-698d-46b3-be21-84443486cc68'] = $handler;

  return $export;
}
