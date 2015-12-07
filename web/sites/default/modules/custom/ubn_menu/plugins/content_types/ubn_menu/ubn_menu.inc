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
    'category' => 'UBNext',
    //'edit form' => 'ubn_menu_slate_slate_gmap_content_type_settings',
  );
  $menu_name = 'main-menu';
  $menu_label = 'Main menu';
  //TODO: full instead of all
  foreach(array('all', 'top-level', 'menu-trail', 'bottom-level', 'bottom-level-dropdown') as $variant) { 
    $types['ubn_menu:' . $menu_name . ':' . $variant ] = $plugin + array('title' => 'UBN Menu: ' .  $menu_label . ' (' . $variant . ')'); //t?
  }

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
  list(, $menu_name, $type) = explode(':', $subtype);
  $cache = drupal_static(__FUNCTION__);
  $menu_name = 'main-menu';

  if(!isset($cache[$menu_name . ':page_tree_by_level'])) {
    $page_tree = menu_tree_page_data($menu_name);
    _ubn_menu_prune($page_tree);
    $page_tree_by_level = _ubn_menu_menu_tree_by_level($page_tree);
    $cache[$menu_name . ':page_tree_by_level'] = $page_tree_by_level;
  }
  $page_tree_by_level = $cache[$menu_name . ':page_tree_by_level'];
  $block = new stdClass();
  $block->title = t('UBN Menu'); //title?, none?

  switch($type) {
    case 'all':
      $menu_output_by_level = array();
      foreach($page_tree_by_level as $level => $tree) {
        $menu_output_by_level[$level] = menu_tree_output($tree);
        $menu_output_by_level[$level] = drupal_render($menu_output_by_level[$level]);
      }

      $menu_top_level = array_shift($menu_output_by_level);
      $menu_bottom_level = !empty($menu_output_by_level) ? array_pop($menu_output_by_level) : '';
      $menu_trail = !empty($menu_output_by_level) ? $menu_output_by_level : array();

      $block->content = slate_render('ubn-menu-main-menu',
        array(
          'menu_top_level' => $menu_top_level,
          'menu_trail' => $menu_trail,
          'menu_bottom_level' => $menu_bottom_level,
        )
      );
      break;
    case 'top-level':
      $menu_top_level = array_shift($page_tree_by_level);
      $links = _ubn_menu_menu_tree_links($menu_top_level);
      //TODO: implement menu-name wild card
      $block->content = slate_render('ubn-menu-top-level', array(
        'links' => $links
      ));
      break;
    case 'bottom-level':
      // First unshift top-level
      //array_shift($page_tree_by_level);
      //$menu_bottom_level = array_pop($page_tree_by_level);
      $menu_bottom_level = _ubn_menu_menu_tree_expanded_level($page_tree_by_level);
      if(!empty($menu_bottom_level)) {
        $links = _ubn_menu_menu_tree_links($menu_bottom_level);
        //TODO: implement menu-name wild card
        $block->content = slate_render('ubn-menu-bottom-level', array(
          'links' => $links
        ));
      }
      else {
        $block->content = '';
      }
      break;
    case 'bottom-level-dropdown':
      $menu_top_level = array_shift($page_tree_by_level);
      $links = _ubn_menu_menu_tree_links($menu_top_level);
      $block->content = slate_render('ubn-menu-top-level-dropdown', array(
        'links' => $links
      ));
      break;
    case 'menu-trail':
      $trail = array();
      foreach($page_tree_by_level as $level) {
        $links = _ubn_menu_menu_tree_links($level);
        foreach($links as $link) {
          if($link['in_active_trail']) {
            $trail[] = $link;
            break;
          }
        }
      }
      if(!empty($trail)) {
        $block->content = slate_render('ubn-menu-menu-trail', array(
          'links' => $trail,
        ));
      }
      else {
        $block->content = '';
      }
      break;
  }

  return $block;
}

function _ubn_menu_menu_tree_links($tree) {
  $items = array();
  // Pull out just the menu links we are going to render so that we
  // get an accurate count for the first/last classes.
  foreach ($tree as $data) {
    if ($data['link']['access'] && !$data['link']['hidden']) {
      $items[] = $data;
    }
  }
  $links = array();
  foreach($tree as $item) {
    $link = array();
    //url options?
    $link['href'] = url($item['link']['href']);
    $link['title'] = $item['link']['title'];
    $link['in_active_trail'] = $item['link']['in_active_trail'];
    $link['has_children'] = $item['link']['has_children'];
    // Since $item['below'] may contain local
    // tasks, only set 'expanded' if the link also has children
    // within the current menu.
    $link['expanded'] = $item['link']['has_children'] && !empty($item['ubn_menu_item_has_below']);
    $links[] = $link;
  }
  return $links;
}

//TODO: naming etc, I'm confusing even myself
// this code smells
function _ubn_menu_menu_tree_expanded_level($menu_tree_by_level) {
  if(count($menu_tree_by_level) > 1) {
    $last_level = array_pop($menu_tree_by_level);
    foreach($last_level as $item) {
      if($item['link']['in_active_trail']) {
        return array();
      }
    }
    return $last_level;
  }
  return array();
}

function _ubn_menu_menu_tree_by_level($menu_tree) {
  $menu_tree_by_level = array();
  $level = 0;
  do {
    $next_level_menu_tree = array();
    foreach($menu_tree as &$item) {
      if(!empty($item['below'])) {
        $next_level_menu_tree += $item['below'];
        $item['below'] = array();
        //Leave marker that this item is expanded as 'below'
        //will not indicat this any more
        $item['ubn_menu_item_has_below'] = TRUE; //? in active-trail
        // enough?
      }
    }
    $menu_tree_by_level[$level++] = $menu_tree;
    $menu_tree = $next_level_menu_tree;
  } while(!empty($menu_tree));
  return $menu_tree_by_level;
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
