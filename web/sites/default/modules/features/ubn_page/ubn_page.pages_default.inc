<?php
/**
 * @file
 * ubn_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ubn_page_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_2a4b8744-508b-4c0f-bd8f-86a4fa9d91f3';
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
    'main' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3c785124-14ea-40bb-b281-31a9329c0b23';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e3df4bf2-4c92-4ef6-a375-a198cb2772c9';
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
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e3df4bf2-4c92-4ef6-a375-a198cb2772c9';
    $display->content['new-e3df4bf2-4c92-4ef6-a375-a198cb2772c9'] = $pane;
    $display->panels['main'][0] = 'new-e3df4bf2-4c92-4ef6-a375-a198cb2772c9';
    $pane = new stdClass();
    $pane->pid = 'new-7b603e3e-7c61-4ad5-9bd4-5ca568050b69';
    $pane->panel = 'main';
    $pane->type = 'slate_render';
    $pane->subtype = 'slate_render:library-opening-hours-banner';
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
    $pane->uuid = '7b603e3e-7c61-4ad5-9bd4-5ca568050b69';
    $display->content['new-7b603e3e-7c61-4ad5-9bd4-5ca568050b69'] = $pane;
    $display->panels['main'][1] = 'new-7b603e3e-7c61-4ad5-9bd4-5ca568050b69';
    $pane = new stdClass();
    $pane->pid = 'new-8414a01c-f282-44b7-9f3b-afa34b91e33e';
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
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8414a01c-f282-44b7-9f3b-afa34b91e33e';
    $display->content['new-8414a01c-f282-44b7-9f3b-afa34b91e33e'] = $pane;
    $display->panels['main'][2] = 'new-8414a01c-f282-44b7-9f3b-afa34b91e33e';
    $pane = new stdClass();
    $pane->pid = 'new-fc378e18-63ad-4e8e-b4cd-bbc7a8f67fb8';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'fc378e18-63ad-4e8e-b4cd-bbc7a8f67fb8';
    $display->content['new-fc378e18-63ad-4e8e-b4cd-bbc7a8f67fb8'] = $pane;
    $display->panels['main'][3] = 'new-fc378e18-63ad-4e8e-b4cd-bbc7a8f67fb8';
    $pane = new stdClass();
    $pane->pid = 'new-f49d8c04-39d9-4b89-aca9-3d19c20fcc82';
    $pane->panel = 'main';
    $pane->type = 'slate_render';
    $pane->subtype = 'slate_render:library-properties';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'f49d8c04-39d9-4b89-aca9-3d19c20fcc82';
    $display->content['new-f49d8c04-39d9-4b89-aca9-3d19c20fcc82'] = $pane;
    $display->panels['main'][4] = 'new-f49d8c04-39d9-4b89-aca9-3d19c20fcc82';
    $pane = new stdClass();
    $pane->pid = 'new-955d37a7-32c7-4b87-b14b-4273a1ea33a0';
    $pane->panel = 'main';
    $pane->type = 'slate_gmap';
    $pane->subtype = 'slate_gmap:node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'gmap_slate' => 'library-map',
      'gmap_item_content_slate' => 'library-map-item',
      'lat_lng_field' => 'field_location',
      'gmap_tools_settings' => array(
        'container_id' => 'slate-gmap-node',
        'gmap_tools_namespace' => 'slate_gmap_node',
        'gmap_tools_gmap_create_gmap' => 1,
        'gmap_tools_gmap_options' => array(
          'mapTypeId' => 'ROADMAP',
          'zoom' => '15',
          'min_zoom' => '',
          'max_zoom' => '',
          'center' => array(
            'lat' => '0',
            'lng' => '0',
          ),
        ),
        'gmap_tools_behaviors' => array(
          'clustered' => array(
            'enabled' => 0,
          ),
          'info_windows' => array(
            'enabled' => 1,
          ),
          'items_sidebar' => array(
            'enabled' => 0,
            'options' => array(
              'wrapper' => '',
              'limit' => '',
              'bounce' => 0,
              'items_filter' => array(
                'body' => '',
              ),
            ),
          ),
          'fit_items_bounds' => array(
            'enabled' => 0,
            'options' => array(
              'max_zoom' => '',
              'min_zoom' => '',
            ),
          ),
        ),
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'bundles' => array(
        'library' => 'library',
      ),
      'container_id' => 'slate-gmap-node',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '955d37a7-32c7-4b87-b14b-4273a1ea33a0';
    $display->content['new-955d37a7-32c7-4b87-b14b-4273a1ea33a0'] = $pane;
    $display->panels['main'][5] = 'new-955d37a7-32c7-4b87-b14b-4273a1ea33a0';
    $pane = new stdClass();
    $pane->pid = 'new-7c4c7fc8-306f-4cd3-9d92-608de6b5d877';
    $pane->panel = 'main';
    $pane->type = 'slate_render';
    $pane->subtype = 'slate_render:library-contact';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '7c4c7fc8-306f-4cd3-9d92-608de6b5d877';
    $display->content['new-7c4c7fc8-306f-4cd3-9d92-608de6b5d877'] = $pane;
    $display->panels['main'][6] = 'new-7c4c7fc8-306f-4cd3-9d92-608de6b5d877';
    $pane = new stdClass();
    $pane->pid = 'new-2b04e45a-7ba0-4d4d-98d6-f874e234fe61';
    $pane->panel = 'main';
    $pane->type = 'slate_render';
    $pane->subtype = 'slate_render:library-opening-hours';
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
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '2b04e45a-7ba0-4d4d-98d6-f874e234fe61';
    $display->content['new-2b04e45a-7ba0-4d4d-98d6-f874e234fe61'] = $pane;
    $display->panels['main'][7] = 'new-2b04e45a-7ba0-4d4d-98d6-f874e234fe61';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_2a4b8744-508b-4c0f-bd8f-86a4fa9d91f3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_75e1767f-61d5-443b-9456-0e86608b78ce';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'Libraries',
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
          'name' => 'entity_field_value:node:page:field_template',
          'settings' => array(
            'field_template' => array(
              'und' => array(
                0 => array(
                  'value' => 'libraries',
                ),
              ),
            ),
            'field_template_value' => array(
              0 => 'libraries',
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
  $display->uuid = '20a21b24-5ea9-4706-b757-2bb313975b11';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-58939798-2006-4e3e-9e32-e3840910a4bf';
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
    $pane->uuid = '58939798-2006-4e3e-9e32-e3840910a4bf';
    $display->content['new-58939798-2006-4e3e-9e32-e3840910a4bf'] = $pane;
    $display->panels['main'][0] = 'new-58939798-2006-4e3e-9e32-e3840910a4bf';
    $pane = new stdClass();
    $pane->pid = 'new-376e1c75-6e4c-43c2-903d-0a3ce654c613';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'library_list-libraries';
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
    $pane->uuid = '376e1c75-6e4c-43c2-903d-0a3ce654c613';
    $display->content['new-376e1c75-6e4c-43c2-903d-0a3ce654c613'] = $pane;
    $display->panels['main'][1] = 'new-376e1c75-6e4c-43c2-903d-0a3ce654c613';
    $pane = new stdClass();
    $pane->pid = 'new-b3b3304e-4b2b-4310-b0d8-913b909b9ac8';
    $pane->panel = 'main';
    $pane->type = 'slate_gmap';
    $pane->subtype = 'slate_gmap:node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'gmap_tools_settings' => array(
        'container_id' => 'slate-gmap-node',
        'gmap_tools_namespace' => 'slate_gmap_node',
        'gmap_tools_gmap_create_gmap' => 1,
        'gmap_tools_gmap_options' => array(
          'mapTypeId' => 'ROADMAP',
          'zoom' => '14',
          'min_zoom' => '',
          'max_zoom' => '',
          'center' => array(
            'lat' => '0',
            'lng' => '0',
          ),
        ),
        'gmap_tools_behaviors' => array(
          'clustered' => array(
            'enabled' => 0,
          ),
          'info_windows' => array(
            'enabled' => 1,
          ),
          'items_sidebar' => array(
            'enabled' => 0,
            'options' => array(
              'wrapper' => '',
              'limit' => '',
              'bounce' => 0,
              'items_filter' => array(
                'body' => '',
              ),
            ),
          ),
          'fit_items_bounds' => array(
            'enabled' => 1,
            'options' => array(
              'max_zoom' => '',
              'min_zoom' => '',
            ),
          ),
        ),
      ),
      'bundles' => array(
        'library' => 'library',
      ),
      'gmap_slate' => 'libraries-map',
      'gmap_item_content_slate' => 'library-map-item',
      'lat_lng_field' => 'field_location',
      'context' => 'empty',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b3b3304e-4b2b-4310-b0d8-913b909b9ac8';
    $display->content['new-b3b3304e-4b2b-4310-b0d8-913b909b9ac8'] = $pane;
    $display->panels['main'][2] = 'new-b3b3304e-4b2b-4310-b0d8-913b909b9ac8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-376e1c75-6e4c-43c2-903d-0a3ce654c613';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_75e1767f-61d5-443b-9456-0e86608b78ce'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_f69415b1-e449-4cd0-859c-f2bea71148bb';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'Page',
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
  $display->uuid = 'b6f36589-9536-420c-8d41-57a59f9d4348';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ce69a7ac-895b-4e74-96e3-1054f934577b';
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
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ce69a7ac-895b-4e74-96e3-1054f934577b';
    $display->content['new-ce69a7ac-895b-4e74-96e3-1054f934577b'] = $pane;
    $display->panels['main'][0] = 'new-ce69a7ac-895b-4e74-96e3-1054f934577b';
    $pane = new stdClass();
    $pane->pid = 'new-f5c386c1-afc9-4a08-96c3-2cd3ee33e780';
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
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f5c386c1-afc9-4a08-96c3-2cd3ee33e780';
    $display->content['new-f5c386c1-afc9-4a08-96c3-2cd3ee33e780'] = $pane;
    $display->panels['main'][1] = 'new-f5c386c1-afc9-4a08-96c3-2cd3ee33e780';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f5c386c1-afc9-4a08-96c3-2cd3ee33e780';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_f69415b1-e449-4cd0-859c-f2bea71148bb'] = $handler;

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
    $pane->pid = 'new-d74996d4-26c1-4f35-b21f-13ab0f20bcd1';
    $pane->panel = 'navigation';
    $pane->type = 'ubn_menu';
    $pane->subtype = 'ubn_menu:main-menu';
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
    $pane->uuid = 'd74996d4-26c1-4f35-b21f-13ab0f20bcd1';
    $display->content['new-d74996d4-26c1-4f35-b21f-13ab0f20bcd1'] = $pane;
    $display->panels['navigation'][0] = 'new-d74996d4-26c1-4f35-b21f-13ab0f20bcd1';
    $pane = new stdClass();
    $pane->pid = 'new-ce326e53-b34a-4815-b93f-3210320a4edd';
    $pane->panel = 'pagetitle';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = FALSE;
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
function ubn_page_default_page_manager_pages() {
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
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '40c86ccc-6666-442a-a994-f89c035b8757';
    $display->content['new-40c86ccc-6666-442a-a994-f89c035b8757'] = $pane;
    $display->panels['main'][0] = 'new-40c86ccc-6666-442a-a994-f89c035b8757';
    $pane = new stdClass();
    $pane->pid = 'new-ea3f5579-ce3d-4d53-a14a-726f1d81d213';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'library_list-panel_pane_1';
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
    $pane->uuid = 'ea3f5579-ce3d-4d53-a14a-726f1d81d213';
    $display->content['new-ea3f5579-ce3d-4d53-a14a-726f1d81d213'] = $pane;
    $display->panels['main'][1] = 'new-ea3f5579-ce3d-4d53-a14a-726f1d81d213';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'libraries';
  $page->task = 'page';
  $page->admin_title = 'Libraries';
  $page->admin_description = 'admin desc';
  $page->path = 'libraries';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_libraries__panel';
  $handler->task = 'page';
  $handler->subtask = 'libraries';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
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
  $display->uuid = '018d4a83-41ac-4354-af21-e7cc5a6ec32e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3fd60d5d-6435-460d-b7e4-c0f9d64660cd';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'library_list-libraries';
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
    $pane->uuid = '3fd60d5d-6435-460d-b7e4-c0f9d64660cd';
    $display->content['new-3fd60d5d-6435-460d-b7e4-c0f9d64660cd'] = $pane;
    $display->panels['main'][0] = 'new-3fd60d5d-6435-460d-b7e4-c0f9d64660cd';
    $pane = new stdClass();
    $pane->pid = 'new-6732628d-c431-47c3-ac46-6af4ca875899';
    $pane->panel = 'main';
    $pane->type = 'slate_gmap';
    $pane->subtype = 'slate_gmap:node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'gmap_tools_settings' => array(
        'container_id' => 'slate-gmap-node',
        'gmap_tools_namespace' => 'slate_gmap_node',
        'gmap_tools_gmap_create_gmap' => 1,
        'gmap_tools_gmap_options' => array(
          'mapTypeId' => 'ROADMAP',
          'zoom' => '14',
          'min_zoom' => '',
          'max_zoom' => '',
          'center' => array(
            'lat' => '0',
            'lng' => '0',
          ),
        ),
        'gmap_tools_behaviors' => array(
          'clustered' => array(
            'enabled' => 0,
          ),
          'info_windows' => array(
            'enabled' => 1,
          ),
          'items_sidebar' => array(
            'enabled' => 0,
            'options' => array(
              'wrapper' => '',
              'limit' => '',
              'bounce' => 0,
              'items_filter' => array(
                'body' => '',
              ),
            ),
          ),
          'fit_items_bounds' => array(
            'enabled' => 1,
            'options' => array(
              'max_zoom' => '',
              'min_zoom' => '',
            ),
          ),
        ),
      ),
      'bundles' => array(
        'library' => 'library',
      ),
      'gmap_slate' => 'libraries-map',
      'gmap_item_content_slate' => 'library-map-item',
      'lat_lng_field' => 'field_location',
      'context' => 'empty',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6732628d-c431-47c3-ac46-6af4ca875899';
    $display->content['new-6732628d-c431-47c3-ac46-6af4ca875899'] = $pane;
    $display->panels['main'][1] = 'new-6732628d-c431-47c3-ac46-6af4ca875899';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['libraries'] = $page;

  return $pages;

}
