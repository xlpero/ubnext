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
    $classes = ' class="full-width-wrapper ' . $vars['pane']->css['css_class'] . '"';
  }

  if (!empty($vars['pane']->css['css_id'])) {
    $id = ' id="' . $vars['pane']->css['css_id'] . '"';
  }

  $output = '<div' . $classes . '>';
  $output .= render($vars['content']->content);
  $output .= '</div>';



  return $output;
}
