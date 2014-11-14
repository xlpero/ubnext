<?php
/**
 * @file
 * ubn_guide.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ubn_guide_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Guide',
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
              'guide' => 'guide',
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
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8c44c2dd-97e8-49e9-976d-1ecde191f9a2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-32e72bd9-7f0d-4eed-83c6-7f8663a631ff';
    $pane->panel = 'left';
    $pane->type = 'guide_navigation';
    $pane->subtype = 'guide_navigation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '32e72bd9-7f0d-4eed-83c6-7f8663a631ff';
    $display->content['new-32e72bd9-7f0d-4eed-83c6-7f8663a631ff'] = $pane;
    $display->panels['left'][0] = 'new-32e72bd9-7f0d-4eed-83c6-7f8663a631ff';
    $pane = new stdClass();
    $pane->pid = 'new-259bdb02-6936-46ea-b3d2-0a54d0d4835b';
    $pane->panel = 'left';
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
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '259bdb02-6936-46ea-b3d2-0a54d0d4835b';
    $display->content['new-259bdb02-6936-46ea-b3d2-0a54d0d4835b'] = $pane;
    $display->panels['left'][1] = 'new-259bdb02-6936-46ea-b3d2-0a54d0d4835b';
    $pane = new stdClass();
    $pane->pid = 'new-ab33d1c8-ae14-45a2-9595-c0127c17e752';
    $pane->panel = 'left';
    $pane->type = 'guide_navigation';
    $pane->subtype = 'guide_navigation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ab33d1c8-ae14-45a2-9595-c0127c17e752';
    $display->content['new-ab33d1c8-ae14-45a2-9595-c0127c17e752'] = $pane;
    $display->panels['left'][2] = 'new-ab33d1c8-ae14-45a2-9595-c0127c17e752';
    $pane = new stdClass();
    $pane->pid = 'new-9da5cb3c-a3a7-4d9c-9fad-a14beba4a988';
    $pane->panel = 'right';
    $pane->type = 'guide_toc';
    $pane->subtype = 'guide_toc';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9da5cb3c-a3a7-4d9c-9fad-a14beba4a988';
    $display->content['new-9da5cb3c-a3a7-4d9c-9fad-a14beba4a988'] = $pane;
    $display->panels['right'][0] = 'new-9da5cb3c-a3a7-4d9c-9fad-a14beba4a988';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Guide: Chapter',
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
              'guide_chapter' => 'guide_chapter',
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
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8c44c2dd-97e8-49e9-976d-1ecde191f9a2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-32e72bd9-7f0d-4eed-83c6-7f8663a631ff';
    $pane->panel = 'left';
    $pane->type = 'guide_navigation';
    $pane->subtype = 'guide_navigation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '32e72bd9-7f0d-4eed-83c6-7f8663a631ff';
    $display->content['new-32e72bd9-7f0d-4eed-83c6-7f8663a631ff'] = $pane;
    $display->panels['left'][0] = 'new-32e72bd9-7f0d-4eed-83c6-7f8663a631ff';
    $pane = new stdClass();
    $pane->pid = 'new-259bdb02-6936-46ea-b3d2-0a54d0d4835b';
    $pane->panel = 'left';
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
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '259bdb02-6936-46ea-b3d2-0a54d0d4835b';
    $display->content['new-259bdb02-6936-46ea-b3d2-0a54d0d4835b'] = $pane;
    $display->panels['left'][1] = 'new-259bdb02-6936-46ea-b3d2-0a54d0d4835b';
    $pane = new stdClass();
    $pane->pid = 'new-ab33d1c8-ae14-45a2-9595-c0127c17e752';
    $pane->panel = 'left';
    $pane->type = 'guide_navigation';
    $pane->subtype = 'guide_navigation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ab33d1c8-ae14-45a2-9595-c0127c17e752';
    $display->content['new-ab33d1c8-ae14-45a2-9595-c0127c17e752'] = $pane;
    $display->panels['left'][2] = 'new-ab33d1c8-ae14-45a2-9595-c0127c17e752';
    $pane = new stdClass();
    $pane->pid = 'new-9da5cb3c-a3a7-4d9c-9fad-a14beba4a988';
    $pane->panel = 'right';
    $pane->type = 'guide_toc';
    $pane->subtype = 'guide_toc';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9da5cb3c-a3a7-4d9c-9fad-a14beba4a988';
    $display->content['new-9da5cb3c-a3a7-4d9c-9fad-a14beba4a988'] = $pane;
    $display->panels['right'][0] = 'new-9da5cb3c-a3a7-4d9c-9fad-a14beba4a988';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  return $export;
}
