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
  $handler->name = 'node_view__panel_context_8e7fc5ba-4a2f-4e16-8462-a9ef87b5e135';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -21;
  $handler->conf = array(
    'title' => 'Story',
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
              'story' => 'story',
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
  $display->layout = 'onecol';
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
  $display->uuid = 'ec51631f-ef19-44bc-af28-9f251e2c6f86';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d1fcdb6a-c878-41ab-973b-a5a82ef0d73b';
    $pane->panel = 'main';
    $pane->type = 'slate_render';
    $pane->subtype = 'slate_render:page-head';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'show_date' => 1,
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
    $pane->uuid = 'd1fcdb6a-c878-41ab-973b-a5a82ef0d73b';
    $display->content['new-d1fcdb6a-c878-41ab-973b-a5a82ef0d73b'] = $pane;
    $display->panels['main'][0] = 'new-d1fcdb6a-c878-41ab-973b-a5a82ef0d73b';
    $pane = new stdClass();
    $pane->pid = 'new-e4aa1714-1a7c-42f5-b911-16dc6ebd3905';
    $pane->panel = 'main';
    $pane->type = 'slate_render';
    $pane->subtype = 'slate_render:content-sections';
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
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e4aa1714-1a7c-42f5-b911-16dc6ebd3905';
    $display->content['new-e4aa1714-1a7c-42f5-b911-16dc6ebd3905'] = $pane;
    $display->panels['main'][1] = 'new-e4aa1714-1a7c-42f5-b911-16dc6ebd3905';
    $pane = new stdClass();
    $pane->pid = 'new-c0e9536c-2ff9-4411-aaad-5c26fb6af380';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'stories-latest_stories';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c0e9536c-2ff9-4411-aaad-5c26fb6af380';
    $display->content['new-c0e9536c-2ff9-4411-aaad-5c26fb6af380'] = $pane;
    $display->panels['main'][2] = 'new-c0e9536c-2ff9-4411-aaad-5c26fb6af380';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d1fcdb6a-c878-41ab-973b-a5a82ef0d73b';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_8e7fc5ba-4a2f-4e16-8462-a9ef87b5e135'] = $handler;

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
    'main' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a0e72b8b-9862-40cf-a574-a424253ccee2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c0f20a47-6dd9-46bd-8e43-ddd1bb706562';
    $pane->panel = 'main';
    $pane->type = 'slate_render';
    $pane->subtype = 'slate_render:static-page-head';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'ubn_i18n' => array(
        'title' => 'News',
        'ingress' => 'This is lead',
      ),
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
    $pane->uuid = 'c0f20a47-6dd9-46bd-8e43-ddd1bb706562';
    $display->content['new-c0f20a47-6dd9-46bd-8e43-ddd1bb706562'] = $pane;
    $display->panels['main'][0] = 'new-c0f20a47-6dd9-46bd-8e43-ddd1bb706562';
    $pane = new stdClass();
    $pane->pid = 'new-a268191e-56c3-461c-af42-7546fd63626b';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'stories-latest_stories_promoted';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a268191e-56c3-461c-af42-7546fd63626b';
    $display->content['new-a268191e-56c3-461c-af42-7546fd63626b'] = $pane;
    $display->panels['main'][1] = 'new-a268191e-56c3-461c-af42-7546fd63626b';
    $pane = new stdClass();
    $pane->pid = 'new-122b7a81-0da1-4a89-9f24-10646fa7c723';
    $pane->panel = 'main';
    $pane->type = 'search_api_page_result';
    $pane->subtype = 'search_api_page_result';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'page' => 'stories',
      'per_page' => '5',
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
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '122b7a81-0da1-4a89-9f24-10646fa7c723';
    $display->content['new-122b7a81-0da1-4a89-9f24-10646fa7c723'] = $pane;
    $display->panels['main'][2] = 'new-122b7a81-0da1-4a89-9f24-10646fa7c723';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_api_page_stories__panel_context_0eb0f05a-df43-4283-b1ea-7e7bc4f5bade'] = $handler;

  return $export;
}
