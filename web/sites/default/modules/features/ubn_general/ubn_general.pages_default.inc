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
      'pagetitle' => NULL,
      'tabs' => NULL,
      'messages' => NULL,
    ),
    'tabs' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9e33ff90-3988-470d-9ff9-57c03abb7a3d';
  $display->content = array();
  $display->panels = array();
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '011a4262-ca7b-42af-ab00-9d5ee0a36877';
    $display->content['new-011a4262-ca7b-42af-ab00-9d5ee0a36877'] = $pane;
    $display->panels['content'][0] = 'new-011a4262-ca7b-42af-ab00-9d5ee0a36877';
    $pane = new stdClass();
    $pane->pid = 'new-94db747d-dbbe-42bd-9909-a59b215d30bd';
    $pane->panel = 'messages';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '94db747d-dbbe-42bd-9909-a59b215d30bd';
    $display->content['new-94db747d-dbbe-42bd-9909-a59b215d30bd'] = $pane;
    $display->panels['messages'][0] = 'new-94db747d-dbbe-42bd-9909-a59b215d30bd';
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
    $pane->pid = 'new-ce326e53-b34a-4815-b93f-3210320a4edd';
    $pane->panel = 'pagetitle';
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
    $display->panels['pagetitle'][0] = 'new-ce326e53-b34a-4815-b93f-3210320a4edd';
    $pane = new stdClass();
    $pane->pid = 'new-3054dda2-3a4b-428b-b253-726c16c2f284';
    $pane->panel = 'tabs';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
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
    $pane->uuid = '3054dda2-3a4b-428b-b253-726c16c2f284';
    $display->content['new-3054dda2-3a4b-428b-b253-726c16c2f284'] = $pane;
    $display->panels['tabs'][0] = 'new-3054dda2-3a4b-428b-b253-726c16c2f284';
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

/**
 * Implements hook_default_page_manager_pages().
 */
function ubn_general_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front';
  $page->task = 'page';
  $page->admin_title = 'front';
  $page->admin_description = '';
  $page->path = 'front';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_front_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'front';
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
  $display->layout = 'front';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'No Title';
  $display->uuid = 'b0bb68cb-13cf-4310-82a0-499fdb2f2d71';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-40c86ccc-6666-442a-a994-f89c035b8757';
    $pane->panel = 'main';
    $pane->type = 'search_widget';
    $pane->subtype = 'search_widget';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '40c86ccc-6666-442a-a994-f89c035b8757';
    $display->content['new-40c86ccc-6666-442a-a994-f89c035b8757'] = $pane;
    $display->panels['main'][0] = 'new-40c86ccc-6666-442a-a994-f89c035b8757';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front'] = $page;

  return $pages;

}
