<?php
/**
 * @file
 * ubn_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ubn_search_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'search_api_page_site__panel_context_2df2c3c4-37b6-4579-a306-8a2280ad3d4d';
  $handler->task = 'search_api_page';
  $handler->subtask = 'site';
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
  $display->uuid = '20d7e418-e9dc-45d9-b179-f2f545f39e12';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-63b99275-c580-4f69-a19a-dd00424c5be4';
    $pane->panel = 'main';
    $pane->type = 'search_api_page_search_box';
    $pane->subtype = 'search_api_page_search_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'page' => 'site',
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
    $pane->uuid = '63b99275-c580-4f69-a19a-dd00424c5be4';
    $display->content['new-63b99275-c580-4f69-a19a-dd00424c5be4'] = $pane;
    $display->panels['main'][0] = 'new-63b99275-c580-4f69-a19a-dd00424c5be4';
    $pane = new stdClass();
    $pane->pid = 'new-1aa4157c-a8e8-4442-9d85-83e06788a419';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Content types',
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
    $pane->uuid = '1aa4157c-a8e8-4442-9d85-83e06788a419';
    $display->content['new-1aa4157c-a8e8-4442-9d85-83e06788a419'] = $pane;
    $display->panels['main'][1] = 'new-1aa4157c-a8e8-4442-9d85-83e06788a419';
    $pane = new stdClass();
    $pane->pid = 'new-331f4528-21b9-4ef5-a140-c125147cde54';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-J5pGIgqlzb1Z0Fbz6bvodsbEuL2a6kIH';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Topics',
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
    $pane->uuid = '331f4528-21b9-4ef5-a140-c125147cde54';
    $display->content['new-331f4528-21b9-4ef5-a140-c125147cde54'] = $pane;
    $display->panels['main'][2] = 'new-331f4528-21b9-4ef5-a140-c125147cde54';
    $pane = new stdClass();
    $pane->pid = 'new-4534c9ea-a234-4e31-8bb7-14fb61367a51';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-CGMubJo6cFDprsoqZV86pVo2ZAUnp0jA';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Media types',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '4534c9ea-a234-4e31-8bb7-14fb61367a51';
    $display->content['new-4534c9ea-a234-4e31-8bb7-14fb61367a51'] = $pane;
    $display->panels['main'][3] = 'new-4534c9ea-a234-4e31-8bb7-14fb61367a51';
    $pane = new stdClass();
    $pane->pid = 'new-ee5866d4-afc4-446a-a5b2-c149f77bed36';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-5sW8rFImTIPbXCg9c5HpBIs3peS1jAWt';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Public access',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'ee5866d4-afc4-446a-a5b2-c149f77bed36';
    $display->content['new-ee5866d4-afc4-446a-a5b2-c149f77bed36'] = $pane;
    $display->panels['main'][4] = 'new-ee5866d4-afc4-446a-a5b2-c149f77bed36';
    $pane = new stdClass();
    $pane->pid = 'new-0909fa2f-3447-43c1-a63b-25462029c584';
    $pane->panel = 'main';
    $pane->type = 'search_api_page_result';
    $pane->subtype = 'search_api_page_result';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'page' => 'site',
      'per_page' => '30',
      'result_page_search_form' => 0,
      'get_per_page' => 0,
      'view_mode' => 'search_api_page_result',
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '0909fa2f-3447-43c1-a63b-25462029c584';
    $display->content['new-0909fa2f-3447-43c1-a63b-25462029c584'] = $pane;
    $display->panels['main'][5] = 'new-0909fa2f-3447-43c1-a63b-25462029c584';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_api_page_site__panel_context_2df2c3c4-37b6-4579-a306-8a2280ad3d4d'] = $handler;

  return $export;
}
