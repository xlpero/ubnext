<?php
/**
 * @file
 * ubn_general.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ubn_general_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'site_template';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'topbar' => NULL,
      'header' => NULL,
      'navigation' => NULL,
      'content' => NULL,
      'footer' => NULL,
      'toplinks' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9e33ff90-3988-470d-9ff9-57c03abb7a3d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ce326e53-b34a-4815-b93f-3210320a4edd';
    $pane->panel = 'content';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
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
    $pane->uuid = 'ce326e53-b34a-4815-b93f-3210320a4edd';
    $display->content['new-ce326e53-b34a-4815-b93f-3210320a4edd'] = $pane;
    $display->panels['content'][0] = 'new-ce326e53-b34a-4815-b93f-3210320a4edd';
    $pane = new stdClass();
    $pane->pid = 'new-011a4262-ca7b-42af-ab00-9d5ee0a36877';
    $pane->panel = 'content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '011a4262-ca7b-42af-ab00-9d5ee0a36877';
    $display->content['new-011a4262-ca7b-42af-ab00-9d5ee0a36877'] = $pane;
    $display->panels['content'][1] = 'new-011a4262-ca7b-42af-ab00-9d5ee0a36877';
    $pane = new stdClass();
    $pane->pid = 'new-e34d37ae-a017-41ad-8e31-c2bd7ead5e1b';
    $pane->panel = 'navigation';
    $pane->type = 'block';
    $pane->subtype = 'system-main-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'e34d37ae-a017-41ad-8e31-c2bd7ead5e1b';
    $display->content['new-e34d37ae-a017-41ad-8e31-c2bd7ead5e1b'] = $pane;
    $display->panels['navigation'][0] = 'new-e34d37ae-a017-41ad-8e31-c2bd7ead5e1b';
    $pane = new stdClass();
    $pane->pid = 'new-179c37da-32bb-42e2-900c-6dbcaec09453';
    $pane->panel = 'toplinks';
    $pane->type = 'block';
    $pane->subtype = 'locale-language';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '179c37da-32bb-42e2-900c-6dbcaec09453';
    $display->content['new-179c37da-32bb-42e2-900c-6dbcaec09453'] = $pane;
    $display->panels['toplinks'][0] = 'new-179c37da-32bb-42e2-900c-6dbcaec09453';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  return $export;
}
