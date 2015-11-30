<?php
/**
 * @file
 */

//TODO: add info?
/**
 * Plugin definition.
 */
$plugin = array(
  'single' => FALSE,
  'title' => t('UBN Main menu'),
  'description' => t('The UBN Main menu'),
  'category' => 'UBN Menu',
);


function ubn_menu_ubn_menu_content_type_content_types() {
  $types = array();
  //TODO: Perhaps don't hard code
  $plugin = array(
    'title' => "UBN Menu: Main menu",
    'category' => 'UBNext',
    //'edit form' => 'ubn_menu_slate_slate_gmap_content_type_settings',
  );
  $types['ubn_menu:main-menu'] = $plugin;
  return $types;
}


/**
 * Settings callback.
 */
/*
function ubn_menu_ubn_menu_content_type_settings($form, &$form_state) {
  return $form;
}
function ubn_menu_ubn_menu_content_type_settings_submit($form, &$form_state) {
  foreach(array() as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
*/

/**
 * Render callback.
 */
function ubn_menu_ubn_menu_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = t('UBN Menu');
  $page_tree = menu_tree_page_data('main-menu');
  _ubn_menu_prune($page_tree);

  $page_tree_by_level = array();
  $level = 0;
  do {
    $next_level_page_tree = array();
    foreach($page_tree as &$item) {
      if(!empty($item['below'])) {
        $next_level_page_tree += $item['below'];
        $item['below'] = array();
      }
    }
    $page_tree_by_level[$level++] = $page_tree;
    $page_tree = $next_level_page_tree;
  } while(!empty($page_tree));

  $menu_output_by_level = array();
  foreach($page_tree_by_level as $level => $tree) {
    $menu_output_by_level[$level] = menu_tree_output($tree);
    $menu_output_by_level[$level] = drupal_render($menu_output_by_level[$level]);
  }

  $block->content = slate_render('ubn-menu-main-menu',
    array('menu_by_level' => $menu_output_by_level)
  );

  return $block;
}

function _ubn_menu_prune(&$tree) {
  $no_active_trails = TRUE;
  foreach($tree as $item) {
    if($item['link']['in_active_trail']) {
      $no_active_trails = FALSE;
    }
    if($item['link']['in_active_trail'] && empty($item['below'])) {
      return;
    }
  }

  if($no_active_trails) {
    return;
  }

  foreach($tree as $key => $item) {
    if(!$item['link']['in_active_trail'] && $item['link']['plid']) {
      unset($tree[$key]);
    }
    else if(!empty($item['below'])) {
      _ubn_menu_prune($tree[$key]['below']);
    }
  }
}

/*
function _ubn_menu_partition_by_level($tree, $level = 0) {
  $items = array(
    $level => array(),
  );
  foreach($tree as $key => $item) {
    if(!empty($items['below'])) {
      $items = array_merge($items, ubn_menu_partition_by_level($items['below'], $level++));
      unset($items['below']);
    }
    $items[$level][$key] = $item;
  }
  return $items;
}
*/
