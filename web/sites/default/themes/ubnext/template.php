<?php
/**
 * @file
 */

function ubnext_get_base_url() {
  global $base_url;
  return $base_url;
}

function ubnext_links__locale_block($variables) {
  global $language;
  unset($variables['links'][$language->language]);
  return theme('links', $variables);
}



function ubnext_preprocess_node(&$vars) {

}

function ubnext_preprocess_panels_pane(&$vars) {
  drupal_add_js(drupal_get_path("theme", "ubnext") . "/js/database-search.js");
}

function ubnext_preprocess_page(&$vars, $hook) {

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

function ubnext_language_switch_links_alter(array &$links, $type, $path) {
  global $language;

  $links['en']['title'] = t('In ') . $links['en']['title'];
  $links['sv']['title'] = t('På ') . $links['sv']['title'];

}

/**
 * make the langswitcher availible in template
 * and remove stuff not wanted
 */

function block_render($module, $block_id) {
  $block = block_load($module, $block_id);
  $block_content = _block_render_blocks(array($block));
  $build = _block_get_renderable_array($block_content);
  $build['locale_language']['#block']->subject = null;
  $build['locale_language']['#contextual_links'] = null;
  $block_rendered = drupal_render($build);
  return $block_rendered;
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
 * Implements hook_html_head_alter().
 */
function ubnext_html_head_alter(&$head_elements) {
}


function ubnext_theme() {
  $items = array();
  $items['bootstrap_search_api_page_search_form'] = array(
    'render element' => 'element',
  );
  $items['user_login'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'ubnext') . '/templates',
    'template' => 'user-login',
    'preprocess functions' => array(
       'ubnext_preprocess_user_login'
    ),
  );
  $items['user_register_form'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'ubnext') . '/templates',
    'template' => 'user-register-form',
    'preprocess functions' => array(
      'ubnext_preprocess_user_register_form'
    ),
  );
  $items['user_pass'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'ubnext') . '/templates',
    'template' => 'user-pass',
    'preprocess functions' => array(
      'ubnext_preprocess_user_pass'
    ),
  );
  return $items;
}

function ubnext_user_login_block($form) {

  $output = drupal_render($form);

  return $output;

}

function ubnext_preprocess_user_login(&$vars) {

  $vars['form']['name']['#attributes']['class'][] = 'form-control';
  $vars['form']['pass']['#attributes']['class'][] = 'form-control';
  $vars['form']['actions']['submit']['#attributes']['class'][] = 'btn btn-primary';
  $vars['intro_text'] = t('Please login.');

}

function ubnext_preprocess_user_register_form(&$vars) {
  $vars['intro_text'] = t('This is my super awesome reg form');
}

function ubnext_preprocess_user_pass(&$vars) {

  $vars['form']['name']['#attributes']['class'][] = 'form-control';
  $vars['form']['actions']['submit']['#attributes']['class'][] = 'btn btn-primary';
  $vars['intro_text'] = t('Please login.');
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

function ubnext_bootstrap_search_api_page_search_form($variables) {
  $element = $variables['element'];
  if (isset($element['#action'])) {
    $element['#attributes']['action'] = drupal_strip_dangerous_protocols($element['#action']);
  }
  element_set_attributes($element, array('method', 'id'));
  if (empty($element['#attributes']['accept-charset'])) {
    $element['#attributes']['accept-charset'] = "UTF-8";
  }


  $search_submit = drupal_render($element['submit_1']);
  $search_input = drupal_render($element['keys_1']);

  foreach(element_children($element, TRUE) as $key) {
    $element['#children'] .= drupal_render($element[$key]);
  }
  // Anonymous DIV to satisfy XHTML compliance.
  return '<form' . drupal_attributes($element['#attributes']) . '><div>'
    . $element['#children'] .
    '<div class="input-group">' . $search_input .
      '<span class="input-group-btn"><div>' . $search_submit . '</div></span>' .
    '</div></form>';
}

function ubnext_bootstrap_form_element_pre_render($elements) {
  //TODO: instead we should search for 'form_element' and remove that
  //array_search
  unset($elements['#theme_wrappers']);
  return $elements;
}

function ubnext_form_search_api_page_search_form_site_alter(&$form, &$form_state, $form_id) {
  // Add bootstrap classes
  $form['keys_1']['#attributes']['class'][] = 'form-control';
  if(!isset($form['submit_1']['#attributes'])) {
    $form['submit_1']['#attributes'] = array();
  }
  if(!isset($form['submit_1']['#attributes']['class'])) {
    $form['submit_1']['#attributes']['class'] = array();
  }
  $form['submit_1']['#attributes']['class'][] = 'btn';
  $form['submit_1']['#attributes']['class'][] = 'btn-primary';

  if(!isset($form['keys_1']['#pre_render'])) {
    $form['keys_1']['#pre_render'] = array();
  }

  $form['keys_1']['#pre_render'][] = 'ubnext_bootstrap_form_element_pre_render';

  $form['#theme_wrappers'] = array();
  $form['#theme'] = array('bootstrap_search_api_page_search_form');
}

/** Facet-API **/

/**
 * Theme functions for the Facet API module.
 */

/**
 * Returns HTML for an inactive facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', 'options', and
 *   'count'. See the l() and theme_facetapi_count() functions for information
 *   about these variables.
 *
 * @ingroup themeable
 */
function ubnext_facetapi_link_inactive($variables) {
  // Builds accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => FALSE,
  );
  $accessible_markup = theme('facetapi_accessible_markup', $accessible_vars);

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $variables['text'] = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Resets link text, sets to options to HTML since we already sanitized the
  // link text and are providing additional markup for accessibility.
  $variables['text'] .= $accessible_markup;
  $variables['options']['html'] = TRUE;

  if(!$variables['hide_inactive_items']) {
    $widget = $variables['operator'] === FACETAPI_OPERATOR_OR && !$variables['limit_active_items'] ?
      '<span class="fa fa-square-o"></span>' :
      '<span class="fa fa-circle-o"></span>';
    $variables['text'] = $widget . $variables['text'];
  }

  $output = theme_link($variables);

  // Adds count to link if one was passed.
  if (isset($variables['count'])) {
    $output .= theme('facetapi_count', $variables);
  }

  return $output;
}

/**
 * Returns HTML for the active facet item's count.
 *
 * @param $variables
 *   An associative array containing:
 *   - count: The item's facet count.
 *
 * @ingroup themeable
 */
function ubnext_facetapi_count($variables) {
  return '<span class="ubn-facet-items-item-count">(' . (int) $variables['count'] . ')</span>';
}

/**
 * Returns HTML for an active facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 *
 * @ingroup themeable
 */
function ubnext_facetapi_link_active($variables) {

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  $widget = $variables['operator'] === FACETAPI_OPERATOR_OR && !$variables['limit_active_items'] ?
    '<span class="fa fa-check-square-o"></span>' :
    '<span class="fa fa-dot-circle-o"></span>';

  $variables['text'] = $widget . theme('facetapi_accessible_markup', $accessible_vars);
  $variables['options']['html'] = TRUE;

  return theme_link($variables) . $link_text;
}

/**
 * Returns HTML for the deactivation widget.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 * @see theme_facetapi_link_active()
 *
 * @ingroup themable
 */
//NOT CURRENTLY USED
function ubnext_facetapi_deactivate_widget($variables) {
  return '<span class="fa fa-check-square-o"></span>';
}
