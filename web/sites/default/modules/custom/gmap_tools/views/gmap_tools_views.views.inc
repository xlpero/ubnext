<?php
/**
 * @file
 * This file holds main views functions for the gmap_tools_views module.
 *
 * @ingroup gmap_tools
 */

/**
 * Implementation of hook_views_plugins().
 */
function gmap_tools_views_views_plugins() {
  $path = drupal_get_path('module', 'gmap_tools_views');
  $plugins = array(
    'module' => 'gmap_tools_views',
    'style' => array(
      'gmap_tools' => array(
        'title' => t('GMap tools gmap'),
        'help' => t('Displays items on a google map.'),
        'handler' => 'gmap_tools_views_style_map',
        'theme' => 'gmap_tools_map',
        'theme path' => $path . '/views',
        //'theme file' => 'xelera-gmap-map.tpl.php',
        //'path' => drupal_get_path('module', 'gmap_tools_views') . '/views', //can remove this?
        'uses fields' => TRUE,
        'uses row plugin' => TRUE, //what is this?
        'uses row class' => TRUE,
        'uses options' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'normal',
        //'js' => array($path . '/gmap_tools_views.js'), //Why does this not work?
        'even empty' => FALSE,
      ),
      /*
      'row' => array(
        'gmap_tools_fields' = array(
          'uses fields' => TRUE,
          'title' => t('GMap tools fields'),
          'help' => t('Display fields through the Display Suite module.'),
          'handler' => 'views_plugin_ds_fields_view',
          'path' => $path . '/views',
          'theme' => 'ds_row_fields',
          'theme path' => $path . '/views',
          'theme file' => 'views_plugin_ds_fields_view.inc',
          'uses options' => TRUE,
          'type' => 'normal',
        ),
      ),
      */
    ),
  );
  return $plugins;
}
