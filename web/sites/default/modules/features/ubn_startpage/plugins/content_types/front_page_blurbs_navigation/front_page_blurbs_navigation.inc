<?php
/**
 * @file
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Front page blurbs navigation'),
  'description' => t('Front page blurbs navigation.'),
  'category' => 'UBNext',
  'edit form' => 'ubn_startpage_front_page_blurbs_navigation_content_type_settings',
);

/**
 * Settings callback.
 */
function ubn_startpage_front_page_blurbs_navigation_content_type_settings($form, &$form_state) {
  return $form;
}


/**
 * Render callback.
 */
function ubn_startpage_front_page_blurbs_navigation_content_type_render($subtype, $conf, $panel_args, $context) {
  drupal_add_js(drupal_get_path('module', 'ubn_startpage') . '/ubn_startpage_blurbs_navigation.js');

  $queue = entityqueue_subqueue_load('front_page_blurbs_navigation');
  $wrapper = entity_metadata_wrapper('entityqueue_subqueue', $queue);

  //TODO: Hardcoded for now, or load queue and check entity type?
  $blurbs = array();
  foreach($wrapper->eq_node as $delta => $blurb) {
    
    // Set $path to the internal Drupal path of the parent or
    // to NULL for the current path 
    $path = $blurb->value()->path['source'];
    $parent = menu_link_get_preferred($path);
    $parameters = array(
        'active_trail' => array($parent['plid']),
        'only_active_trail' => FALSE,
        'min_depth' => $parent['depth']+1,
        'max_depth' => $parent['depth']+1,
        'conditions' => array('plid' => $parent['mlid']),
      );
    $children = menu_build_tree($parent['menu_name'], $parameters);

    // convert to array and cherry-pick attributes
    $arr_children = array();
    foreach ($children as $child) {
      $temp_child = array('url' => $child['link']['link_path'], 'title' => $child['link']['title']);
      $arr_children[] = $temp_child;
    }

    $blurb->value()->ubn_menu_children = $arr_children;
    $blurbs[] = $blurb->value();
  }
  $block = new stdClass();
  $block->title = '';
  $block->content  = '';
  if (!empty($blurbs)) {
    $renderable = entity_view('node', $blurbs, 'ubn_blurb_navigation');
    $blurbs = drupal_render($renderable);
    $block->content = slate_render('front-page-navigation-blurbs', array('blurbs' => $blurbs));
  }

  return $block;
}
