<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => FALSE,
  'title' => t('Slate gmap'),
  'description' => t('A map displaying locations.'),
  'category' => 'Slate GMap',
  //'required context' => new ctools_context_optional(t('Content'), 'entity:node'),
);


// TODO: hook-info
function gmap_tools_slate_slate_gmap_content_type_content_type($subtype) {
  dsm('wtf');
  dsm($subtype);
  //???
}

function gmap_tools_slate_slate_gmap_content_type_content_types() {
  $types = array();
  //Get all entity types with one or more bundles with one more geofields
  $entity_types_field_instances = field_info_instances();
  foreach($entity_types_field_instances as $entity_type => $bundles_field_instances) {
    $entity_info = entity_get_info($entity_type);
    foreach($bundles_field_instances as $bundle_name => $field_instances) {
      foreach($field_instances as $field_instance) {
        $field_info = field_info_field($field_instance['field_name']);
        if($field_info['type'] === 'geofield') {
          $plugin = array(
            'title' => "Slate GMap: {$entity_info['bundles'][$bundle_name]['label']} ($entity_type:$bundle_name)",
            'category' => 'Slate GMap',
            'edit form' => 'gmap_tools_slate_slate_gmap_content_type_settings',
          );
          //$plugin['required context'] = new ctools_context_required('Content', 'entity:'. $entity_type); //bundle??
          $types['slate_gmap:' . $entity_type . ':' . $bundle_name] = $plugin;
          break;
        }
      }
    }
  }
  return $types;
}

function gmap_tools_slate_get_slates_by_type() {
  $slates = slate_get_slates();
  $slates_by_type = array();
  foreach($slates as $key => $slate) {
    if(!empty($slate['type'])) {
      $slates_by_type[$slate['type']] = $slate;
      $slates_by_type['slate'] = $key;
    }
  }
  return $slates_by_type;
}

/**
 * Settings callback.
 */
function gmap_tools_slate_slate_gmap_content_type_settings($form, &$form_state) {

  list(, $entity_type, $bundle_name) = explode(':', $form_state['subtype_name']);

  $gmap_slates = array();
  $gmap_item_content_slates = array(
    '' =>  t('<None>'),
  );
  foreach(slate_get_slates() as $slate => $info) {
    if($info['type'] === 'gmap_tools_slate_gmap') {
      $gmap_slates[$slate] = $info['name'];
    }
    if($info['type'] === 'gmap_tools_slate_gmap_item_content') {
      $gmap_item_content_slates[$slate] = $info['name'];
    }
  }
  $conf = $form_state['conf'];

  $conf += array(
    'gmap_tools_settings' => array(
      'gmap_tools_namespace' => str_replace(':', '_', $form_state['subtype_name']),
    ),
  );

  //TODO: defaults

  $form['gmap_slate'] = array(
    '#type' => 'select',
    '#options' =>  $gmap_slates,
    '#title' => t('GMap slate'),
    '#description' => 'TODO',
    '#default_value' => !empty($conf['gmap_slate']) ? $conf['gmap_slate'] : NULL,
  );
  //Rename to info_window_content_slate?
  $form['gmap_item_content_slate'] = array(
    '#type' => 'select',
    '#options' => $gmap_item_content_slates,
    '#title' => t('GMap item content slate'),
    '#description' => 'TODO',
    '#default_value' => !empty($conf['gmap_item_content_slate']) ? $conf['gmap_item_content_slate'] : NULL,
  );

  //TODO: geofield/lat_lng_field
  //TODO: helper function for this? Get supported fields etc?
  $lat_lng_fields = array();
  $field_instances = field_info_instances($entity_type, $bundle_name);
  foreach($field_instances as $field_instance) {
    $field = field_info_field($field_instance['field_name']);
    if($field['type'] === 'geofield') {
      $lat_lng_fields[$field_instance['field_name']] = "{$field_instance['label']} ({$field_instance['field_name']})"; //TODO: t?
    }
  }
  //TODO 'lat_lng_field_name' ?
  $form['lat_lng_field'] = array(
    '#type' => 'select',
    '#options' => $lat_lng_fields,
    '#title' => t('Geofield'),
    '#description' => 'TODO',
    '#default_value' => !empty($conf['lat_lng_field']) ? $conf['lat_lng_field'] : NULL,
  );

  $form['gmap_tools_settings'] = array(
    '#title' => t("GMap settings"),
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  $form['gmap_tools_settings'] += gmap_tools_gmap_settings_form(!empty($conf['gmap_tools_settings']) ? $conf['gmap_tools_settings'] : array());

  return $form;
}

//This feels ugly, why no way of declare settings in plugin definition instead?
//But ctools example does it this way so guess it's ok
function gmap_tools_slate_slate_gmap_content_type_settings_submit($form, &$form_state) {
  foreach(array('gmap_slate', 'gmap_item_content_slate', 'lat_lng_field', 'gmap_tools_settings') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Render callback.
 */
function gmap_tools_slate_slate_gmap_content_type_render($subtype, $conf, $panel_args, $context) {
  global $language_content;
  list(, $entity_type, $bundle_name) = explode(':', $subtype);

  $block = new stdClass();
  $block->title = t('Library Map');

  if (empty($context->data)) { //TODO: remove this check?
    $query = new EntityFieldQuery();

    $query
      ->entityCondition('entity_type', $entity_type)
      ->entityCondition('bundle', $bundle_name);

    if($entity_type === 'node') {
      $query->propertyCondition('status', NODE_PUBLISHED);
    }
    //TOOD: fix entity translation
    //$query->addTag('ENTITY_TRANSLATION');

    $result = $query->execute();

    if (empty($result[$entity_type])) {
      return $block;
    }

    $entities = entity_load($entity_type, array_keys($result[$entity_type]));
  }
  else {
    $entities = array($context->data); //TODO: hmm, check plugin definition
  }

  $gmap_items = array();

  foreach ($entities as $entity) {
    $wrapper = entity_metadata_wrapper($entity_type, $entity);
    $wrapper->language($language_content->language);
    //Wrapper?
    //$uri = entity_uri($entity_type, $entity);
    $lat_lng_field_value = $wrapper->get($conf['lat_lng_field'])->value();

    if(!empty($lat_lng_field_value)) {
      $id = $wrapper->getIdentifier();
      //TODO: check geo type etc?
      $gmap_items[$entity_type . '-' . $id] = array(
        'title' => $wrapper->label(),
        'lat' => $lat_lng_field_value['lat'],
        'lng' => $lat_lng_field_value['lon'],
      );

      if(!empty($conf['gmap_item_content_slate'])) { 
        $slate_info = slate_get_slate($conf['gmap_item_content_slate']);
        //TODO: warn/throw exception if no models? or model of wrong entity type?
        if(!empty($slate_info['models'])) {
          list($model, $model_info) = each($slate_info['models']);
          if($model_info['type'] === 'entity:' . $entity_type) {
            $content = slate_render($conf['gmap_item_content_slate'], array(
              $model => $entity,
            ));
            $gmap_items[$entity_type . '-' . $id]['content'] = $content;
          }
        }
      }
    }
  }
  $gmap_namespace = $conf['gmap_tools_settings']['gmap_tools_namespace'];
  $gmap_container_id = drupal_clean_css_identifier($gmap_namespace);

  //This will add all js-settings etc
  gmap_tools_gmap($gmap_namespace, $gmap_container_id, $gmap_items, $conf['gmap_tools_settings']);
  
  $block->content = slate_render($conf['gmap_slate'], array(
    //or setting for id? Yes, with default as namespace css identifier
    'id' => $gmap_container_id,
  ));

  return $block;
}
