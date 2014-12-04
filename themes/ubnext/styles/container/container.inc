<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Container'),
  'description' => t('...'),
  'render pane' => 'container_style_render_pane',
);


/**
 * Render callback.
 */
function theme_container_style_render_pane($vars) {
  $classes = '';
  $id = '';

  if (!empty($vars['pane']->css['css_class'])) {
    $classes = ' class="' . $vars['pane']->css['css_class'] . '"';
  }

  if (!empty($vars['pane']->css['css_id'])) {
    $id = ' id="' . $vars['pane']->css['css_id'] . '"';
  }

  $output = '<section' . $classes . $id . '>';
  $output .= '<div class="wrap">';
  $output .= render($vars['content']->content);
  $output .= '</div>';
  $output .= '</section>';

  return $output;
}
