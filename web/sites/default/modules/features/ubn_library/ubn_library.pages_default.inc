<?php
/**
 * @file
 * ubn_library.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ubn_library_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
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
  $display->layout = 'onecol_wide';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
      'header' => NULL,
    ),
    'main' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '62b39ac7-9145-4603-97db-bbe98d1421db';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5e4d22a5-0850-45cb-a053-572c4e85d6f5';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
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
    $pane->uuid = '5e4d22a5-0850-45cb-a053-572c4e85d6f5';
    $display->content['new-5e4d22a5-0850-45cb-a053-572c4e85d6f5'] = $pane;
    $display->panels['main'][0] = 'new-5e4d22a5-0850-45cb-a053-572c4e85d6f5';
    $pane = new stdClass();
    $pane->pid = 'new-e4a7d860-a199-469e-9a81-f8edeaca0ae0';
    $pane->panel = 'main';
    $pane->type = 'library_resource';
    $pane->subtype = 'library_resource';
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
      'style' => 'container',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'light',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e4a7d860-a199-469e-9a81-f8edeaca0ae0';
    $display->content['new-e4a7d860-a199-469e-9a81-f8edeaca0ae0'] = $pane;
    $display->panels['main'][1] = 'new-e4a7d860-a199-469e-9a81-f8edeaca0ae0';
    $pane = new stdClass();
    $pane->pid = 'new-19be738f-316b-4061-9a04-acc4dd6b1c0b';
    $pane->panel = 'main';
    $pane->type = 'library_map';
    $pane->subtype = 'library_map';
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
      'style' => 'container',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'white',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '19be738f-316b-4061-9a04-acc4dd6b1c0b';
    $display->content['new-19be738f-316b-4061-9a04-acc4dd6b1c0b'] = $pane;
    $display->panels['main'][2] = 'new-19be738f-316b-4061-9a04-acc4dd6b1c0b';
    $pane = new stdClass();
    $pane->pid = 'new-f3bbe9fd-0ff8-4543-905f-0a7c0c1e830c';
    $pane->panel = 'main';
    $pane->type = 'library_contact';
    $pane->subtype = 'library_contact';
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
      'style' => 'container',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'white',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'f3bbe9fd-0ff8-4543-905f-0a7c0c1e830c';
    $display->content['new-f3bbe9fd-0ff8-4543-905f-0a7c0c1e830c'] = $pane;
    $display->panels['main'][3] = 'new-f3bbe9fd-0ff8-4543-905f-0a7c0c1e830c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5e4d22a5-0850-45cb-a053-572c4e85d6f5';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  return $export;
}