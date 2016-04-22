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
  $handler->name = 'search_api_page_databases__panel_context_66fb699e-47bb-4215-ad27-bf59ecb4e5bb';
  $handler->task = 'search_api_page';
  $handler->subtask = 'databases';
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
    'contexts' => array(
      0 => array(
        'identifier' => 'Page',
        'keyword' => 'page',
        'name' => 'entity_uuid:node',
        'uuid' => 'b1961886-660a-4c82-a142-518506df8a05',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'onecol_sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
      'sidebar' => NULL,
      'topbar' => NULL,
      'searchbartop' => NULL,
      'shortcuts' => NULL,
      'header' => NULL,
      'alertarea' => NULL,
      'main_top' => NULL,
      'search_bar_top' => NULL,
    ),
    'main' => array(
      'style' => 'naked',
    ),
    'header' => array(
      'style' => 'naked',
    ),
    'main_top' => array(
      'style' => 'naked',
    ),
    'search_bar_top' => array(
      'style' => 'naked',
    ),
    'sidebar' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0c35b779-f10d-45da-8afc-f89d4d68c82e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-38551aaa-0b57-47de-bd32-3a1c4209ab00';
    $pane->panel = 'header';
    $pane->type = 'slate_render';
    $pane->subtype = 'slate_render:page-admin-links';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any embedded_page content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => array(
        0 => 'context_entity_uuid:node_1',
      ),
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '38551aaa-0b57-47de-bd32-3a1c4209ab00';
    $display->content['new-38551aaa-0b57-47de-bd32-3a1c4209ab00'] = $pane;
    $display->panels['header'][0] = 'new-38551aaa-0b57-47de-bd32-3a1c4209ab00';
    $pane = new stdClass();
    $pane->pid = 'new-962e4cc6-9687-47fd-900d-be7b0fb1d131';
    $pane->panel = 'header';
    $pane->type = 'slate_render';
    $pane->subtype = 'slate_render:page-head';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'show_date' => 0,
      'context' => array(
        0 => 'context_entity_uuid:node_1',
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
    $pane->uuid = '962e4cc6-9687-47fd-900d-be7b0fb1d131';
    $display->content['new-962e4cc6-9687-47fd-900d-be7b0fb1d131'] = $pane;
    $display->panels['header'][1] = 'new-962e4cc6-9687-47fd-900d-be7b0fb1d131';
    $pane = new stdClass();
    $pane->pid = 'new-5d336d16-3a73-4150-953f-2e2f923eae06';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'search_api_sorts-search-sorts';
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
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5d336d16-3a73-4150-953f-2e2f923eae06';
    $display->content['new-5d336d16-3a73-4150-953f-2e2f923eae06'] = $pane;
    $display->panels['main'][0] = 'new-5d336d16-3a73-4150-953f-2e2f923eae06';
    $pane = new stdClass();
    $pane->pid = 'new-e8e7619e-7c4e-488f-b9a2-3b3cb009b743';
    $pane->panel = 'main';
    $pane->type = 'search_api_page_result';
    $pane->subtype = 'search_api_page_result';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'page' => 'databases',
      'per_page' => '40',
      'result_page_search_form' => 0,
      'get_per_page' => 1,
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e8e7619e-7c4e-488f-b9a2-3b3cb009b743';
    $display->content['new-e8e7619e-7c4e-488f-b9a2-3b3cb009b743'] = $pane;
    $display->panels['main'][1] = 'new-e8e7619e-7c4e-488f-b9a2-3b3cb009b743';
    $pane = new stdClass();
    $pane->pid = 'new-12ef259b-f8d2-410b-8ed4-e7a31adbdc8b';
    $pane->panel = 'main_top';
    $pane->type = 'slate_render';
    $pane->subtype = 'slate_render:content-sections';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'context_entity_uuid:node_1',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '12ef259b-f8d2-410b-8ed4-e7a31adbdc8b';
    $display->content['new-12ef259b-f8d2-410b-8ed4-e7a31adbdc8b'] = $pane;
    $display->panels['main_top'][0] = 'new-12ef259b-f8d2-410b-8ed4-e7a31adbdc8b';
    $pane = new stdClass();
    $pane->pid = 'new-3d1a8c22-70f2-4beb-bd22-08072805459c';
    $pane->panel = 'main_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'malfunction_messages-panel_pane_1';
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
    $pane->uuid = '3d1a8c22-70f2-4beb-bd22-08072805459c';
    $display->content['new-3d1a8c22-70f2-4beb-bd22-08072805459c'] = $pane;
    $display->panels['main_top'][1] = 'new-3d1a8c22-70f2-4beb-bd22-08072805459c';
    $pane = new stdClass();
    $pane->pid = 'new-8ce72e3e-4b6b-48dc-9ce1-5867a659b542';
    $pane->panel = 'main_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'database_shortcuts-panel_pane_1';
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
    $pane->uuid = '8ce72e3e-4b6b-48dc-9ce1-5867a659b542';
    $display->content['new-8ce72e3e-4b6b-48dc-9ce1-5867a659b542'] = $pane;
    $display->panels['main_top'][2] = 'new-8ce72e3e-4b6b-48dc-9ce1-5867a659b542';
    $pane = new stdClass();
    $pane->pid = 'new-9ae1ff6d-4776-475a-8cd3-948940f0e225';
    $pane->panel = 'search_bar_top';
    $pane->type = 'search_api_page_search_box';
    $pane->subtype = 'search_api_page_search_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'page' => 'databases',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9ae1ff6d-4776-475a-8cd3-948940f0e225';
    $display->content['new-9ae1ff6d-4776-475a-8cd3-948940f0e225'] = $pane;
    $display->panels['search_bar_top'][0] = 'new-9ae1ff6d-4776-475a-8cd3-948940f0e225';
    $pane = new stdClass();
    $pane->pid = 'new-82de267b-a0cf-4836-9c24-d21c2a09d730';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-n34MERb5dMRY2ZPh09ozouTbc17LwCkQ';
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
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '82de267b-a0cf-4836-9c24-d21c2a09d730';
    $display->content['new-82de267b-a0cf-4836-9c24-d21c2a09d730'] = $pane;
    $display->panels['sidebar'][0] = 'new-82de267b-a0cf-4836-9c24-d21c2a09d730';
    $pane = new stdClass();
    $pane->pid = 'new-63c0229b-8912-4961-a94d-bcf6e28cc7dd';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-R93Ie1tGJwYkUTq4Npg1qrmZ7O5IWlaL';
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
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '63c0229b-8912-4961-a94d-bcf6e28cc7dd';
    $display->content['new-63c0229b-8912-4961-a94d-bcf6e28cc7dd'] = $pane;
    $display->panels['sidebar'][1] = 'new-63c0229b-8912-4961-a94d-bcf6e28cc7dd';
    $pane = new stdClass();
    $pane->pid = 'new-dffb2701-0ac2-475b-bae6-f9bf5e428433';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-bP0TBXood5sMi2c2BkbgZi9Q9lTnkF4T';
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
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'dffb2701-0ac2-475b-bae6-f9bf5e428433';
    $display->content['new-dffb2701-0ac2-475b-bae6-f9bf5e428433'] = $pane;
    $display->panels['sidebar'][2] = 'new-dffb2701-0ac2-475b-bae6-f9bf5e428433';
    $pane = new stdClass();
    $pane->pid = 'new-1ef65f74-cf42-48b3-aaa7-d965534d80c8';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-prqwgUUkeC4TQfT1AXYLlEipeLB31esZ';
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
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '1ef65f74-cf42-48b3-aaa7-d965534d80c8';
    $display->content['new-1ef65f74-cf42-48b3-aaa7-d965534d80c8'] = $pane;
    $display->panels['sidebar'][3] = 'new-1ef65f74-cf42-48b3-aaa7-d965534d80c8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-82de267b-a0cf-4836-9c24-d21c2a09d730';
  $handler->conf['display'] = $display;
  $export['search_api_page_databases__panel_context_66fb699e-47bb-4215-ad27-bf59ecb4e5bb'] = $handler;

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
    $pane->pid = 'new-bdf0e3c6-0098-43e1-b4dd-8b2d9fb4dd25';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-LhYHYSlyv21lZbeNLNwNo46NtP44z0L8';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'bdf0e3c6-0098-43e1-b4dd-8b2d9fb4dd25';
    $display->content['new-bdf0e3c6-0098-43e1-b4dd-8b2d9fb4dd25'] = $pane;
    $display->panels['main'][2] = 'new-bdf0e3c6-0098-43e1-b4dd-8b2d9fb4dd25';
    $pane = new stdClass();
    $pane->pid = 'new-641105a2-79d1-4d3c-8920-951ede62840d';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-dVsSI6NLrtwYt1bPkR1W4HHeuhKw2bbx';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '641105a2-79d1-4d3c-8920-951ede62840d';
    $display->content['new-641105a2-79d1-4d3c-8920-951ede62840d'] = $pane;
    $display->panels['main'][3] = 'new-641105a2-79d1-4d3c-8920-951ede62840d';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '4534c9ea-a234-4e31-8bb7-14fb61367a51';
    $display->content['new-4534c9ea-a234-4e31-8bb7-14fb61367a51'] = $pane;
    $display->panels['main'][4] = 'new-4534c9ea-a234-4e31-8bb7-14fb61367a51';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'ee5866d4-afc4-446a-a5b2-c149f77bed36';
    $display->content['new-ee5866d4-afc4-446a-a5b2-c149f77bed36'] = $pane;
    $display->panels['main'][5] = 'new-ee5866d4-afc4-446a-a5b2-c149f77bed36';
    $pane = new stdClass();
    $pane->pid = 'new-da845b38-d8f7-4037-a774-0037fefc8b7e';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'search_api_sorts-search-sorts';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'da845b38-d8f7-4037-a774-0037fefc8b7e';
    $display->content['new-da845b38-d8f7-4037-a774-0037fefc8b7e'] = $pane;
    $display->panels['main'][6] = 'new-da845b38-d8f7-4037-a774-0037fefc8b7e';
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
      'get_per_page' => 1,
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
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '0909fa2f-3447-43c1-a63b-25462029c584';
    $display->content['new-0909fa2f-3447-43c1-a63b-25462029c584'] = $pane;
    $display->panels['main'][7] = 'new-0909fa2f-3447-43c1-a63b-25462029c584';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_api_page_site__panel_context_2df2c3c4-37b6-4579-a306-8a2280ad3d4d'] = $handler;

  return $export;
}
