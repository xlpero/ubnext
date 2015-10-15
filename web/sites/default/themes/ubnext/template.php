<?php
/**
 * @file
 */



function ubnext_links__locale_block($variables) {
  global $language;
  unset($variables['links'][$language->language]);
  return theme('links', $variables);
}
/**
 *
 */
function ubnext_preprocess_html(&$vars) {
  global $is_https;
  drupal_add_css(($is_https ? 'https' : 'http') . '://fonts.googleapis.com/css?family=Open+Sans:700,400', array('type' => 'external'));

  // If the Guide feature is enabled, add chapter-1 class to body if the first
  // chapter on a guide is active.
  if (module_exists('ubn_guide')) {
    $page = page_manager_get_current_page();

    if (!empty($page['task']['name']) && $page['task']['name'] === 'node_view') {
      $node = entity_metadata_wrapper('node', reset($page['contexts'])->data);

      if ($node->getBundle() === 'guide') {
        $vars['classes_array'][] = 'chapter-1';
      }
      elseif ($node->getBundle() === 'guide_chapter') {
        $root = ubn_guide_get_root($node);
        $children = array_keys(ubn_guide_get_children($root->getIdentifier(), 1));

        $index = array_search($node->getIdentifier(), $children);

        if ($index === 0) {
          $vars['classes_array'][] = 'chapter-1';
        }
      }
    }
  }

  $vars['classes_array'][] = 'new-class';
}

/**
 * Change the CSS @import rules to <link> tags.
 */
function ubnext_pre_render_styles($elements) {
  if (isset($elements['#group_callback'])) {
    $elements['#groups'] = $elements['#group_callback']($elements['#items']);
    unset($elements['#group_callback']);
  }
  if (isset($elements['#aggregate_callback'])) {
    $elements['#aggregate_callback']($elements['#groups']);
    unset($elements['#aggregate_callback']);
  }

  foreach ($elements['#groups'] as &$group) {
    if ($group['type'] == 'file' && isset($group['preprocess'])) {
      foreach ($group['items'] as $index => $item) {
        if (!file_exists($item['data'])) {
          unset($group['items'][$index]);
        }
      }

      $group['preprocess'] = FALSE;
    }
  }

  return $elements;
}

/**
 * Implements hook_css_alter().
 */
function ubnext_css_alter(&$css) {
  // Remove some stylesheets.
  unset(
    $css['misc/vertical-tabs.css'],
    //$css['misc/ui/jquery.ui.theme.css'],
    $css['modules/block/block.css'],
    $css['modules/locale/locale.css'],
    $css['modules/book/book.css'],
    $css['modules/comment/comment.css'],
    $css['modules/dblog/dblog.css'],
    $css['modules/field/theme/field.css'],
    $css['modules/file/file.css'],
    $css['modules/filter/filter.css'],
    $css['modules/forum/forum.css'],
    $css['modules/help/help.css'],
    $css['modules/menu/menu.css'],
    $css['modules/node/node.css'],
    $css['modules/openid/openid.css'],
    $css['modules/poll/poll.css'],
    $css['modules/profile/profile.css'],
    $css['modules/search/search.css'],
    $css['modules/statistics/statistics.css'],
    $css['modules/syslog/syslog.css'],
    $css['modules/system/admin.css'],
    $css['modules/system/maintenance.css'],
    $css['modules/system/system.css'],
    $css['modules/system/system.admin.css'],
    $css['modules/system/system.base.css'],
    $css['modules/system/system.maintenance.css'],
    $css['modules/system/system.menus.css'],
    $css['modules/system/system.messages.css'],
    $css['modules/system/system.theme.css'],
    $css['modules/taxonomy/taxonomy.css'],
    $css['modules/tracker/tracker.css'],
    $css['modules/update/update.css'],
    $css['modules/user/user.css'],
    $css[drupal_get_path('module', 'admin_menu') . '/admin_menu.uid1.css'],
    $css[drupal_get_path('module', 'ctools') . '/css/ctools.css'],
    $css[drupal_get_path('module', 'diff') . '/css/diff.default.css'],
    $css[drupal_get_path('module', 'panels') . '/css/panels.css'],
    $css[drupal_get_path('module', 'views') . '/css/views.css']
  );

  // Load the Contextual CSS last, whether overridden or not.
  if (isset($css['modules/contextual/contextual.css'])) {
    $css['modules/contextual/contextual.css']['group'] = CSS_THEME;
    $css['modules/contextual/contextual.css']['weight'] = 100;
  }
}
