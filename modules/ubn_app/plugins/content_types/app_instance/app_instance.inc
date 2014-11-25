<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'title' => 'App: Instance',
);


/**
 * Get a content type.
 */
function ubn_app_app_instance_content_type_content_type($subtype) {
  $types = ubn_app_app_instance_content_type_content_types();
  if (isset($types[$subtype])) {
    return $types[$subtype];
  }
}

/**
 * Get a list of all content types.
 */
function ubn_app_app_instance_content_type_content_types() {
  $types = array();

  $query = new EntityFieldQuery();

  $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'app')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $result = $query->execute();

  if (!empty($result['node'])) {
    foreach (array_keys($result['node']) as $_app) {
      $app = entity_metadata_wrapper('node', $_app);

      $plugin = array(
        'title' => $app->label(),
        'category' => 'App',
        'edit form' => 'ubn_app_app_instance_content_type_content_type_settings',
      );

      $types['app_instance:' . $app->getIdentifier()] = $plugin;
    }
  }

  return $types;
}

/**
 * Settings callback.
 */
function ubn_app_app_instance_content_type_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_app_app_instance_content_type_render($subtype, $conf, $panel_args, $context) {
  list(, $app_id) = explode(':', $subtype);

  $app = entity_metadata_wrapper('node', $app_id);

  $block = new stdClass();
  $block->title = $app->label();
  $block->content = ubn_app_include_app($app);

  return $block;
}

/**
 * Admin title callback.
 */
function ubn_app_app_instance_content_type_admin_title($subtype, $conf, $context) {
  list(, $app_id) = explode(':', $subtype);

  $app = entity_metadata_wrapper('node', $app_id);

  return t('App "@name"', array('@name' => $app->label()));
}
