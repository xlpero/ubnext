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
  'title' => t('Slate GMap'),
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


function _gmap_tools_slate_geofield_info_instances($_entity_type = NULL) {
  $geofield_info = array();
  $entity_types_field_instances = field_info_instances();
  foreach($entity_types_field_instances as $entity_type => $bundles_field_instances) {
    foreach($bundles_field_instances as $bundle_name => $field_instances) {
      foreach($field_instances as $field_name => $field_instance) {
        $field_info = field_info_field($field_name);
        if($field_info['type'] === 'geofield') {
          if(!isset($geofield_info[$entity_type])) {
            $geofield_info[$entity_type] = array();
          }
          if(!isset($geofield_info[$entity_type][$bundle_name])) {
            $geofield_info[$entity_type][$bundle_name] = array();
          }
          $geofield_info[$entity_type][$bundle_name][$field_name] = $field_instance;
        }
      }
    }
  }
  return isset($_entity_type) ? (isset($geofield_info[$_entity_type]) ? $geofield_info[$_entity_type] : array()) : $geofield_info;
}

function gmap_tools_slate_slate_gmap_content_type_content_types() {
  $types = array();
  //Get all entity types with one or more bundles with one more geofields
  foreach(array_keys(_gmap_tools_slate_geofield_info_instances()) as $entity_type) {
    $entity_info = entity_get_info($entity_type);
    $plugin = array(
      'title' => "Slate GMap: {$entity_info['label']}",
      'category' => 'Slate GMap',
      'required context' => new ctools_context_optional($entity_info['label'], "entity:$entity_type"),
      'edit form' => 'gmap_tools_slate_slate_gmap_content_type_settings',
    );
    $types['slate_gmap:' . $entity_type] = $plugin;
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

  list(, $entity_type) = explode(':', $form_state['subtype_name']);

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

  //TODO: defaults?
  $conf += array(
    'gmap_tools_settings' => array(
      'gmap_tools_namespace' => str_replace(':', '_', $form_state['subtype_name']),
    ),
  );


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


  $entity_info = entity_get_info($entity_type);
  $bundles_geofield_instances = _gmap_tools_slate_geofield_info_instances($entity_type);
  $bundles = array();
  foreach(array_keys($bundles_geofield_instances) as $bundle_name) {
    $bundles[$bundle_name] = $entity_info['bundles'][$bundle_name]['label'];
  }

  $form['bundles'] = array(
    '#type' => 'checkboxes',
    '#options' => $bundles,
    '#title' => t('Bundles'),
    '#description' => t('Select bundles to filter on'),
    '#default_value' => !empty($conf['bundles']) ? $conf['bundles'] : NULL,
  );

  //Flatten array, we are only interested in geofields per entity_type
  $geofield_instances = call_user_func_array('array_merge', $bundles_geofield_instances);

  //TODO: geofield/lat_lng_field
  //TODO: helper function for this? Get supported fields etc?
  $lat_lng_fields = array();
  foreach($geofield_instances as $field_instance) {
    $field = field_info_field($field_instance['field_name']);
    if($field['type'] === 'geofield') {
      $lat_lng_fields[$field_instance['field_name']] = "{$field_instance['label']} ({$field_instance['field_name']})";
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

  //TODO: in gmap settings?
  $form['gmap_tools_settings']['container_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Map container element id'),
    '#default_value' => !empty($conf['gmap_tools_settings']['container_id']) ?
    $conf['gmap_tools_settings']['container_id'] : drupal_clean_css_identifier($conf['gmap_tools_settings']['gmap_tools_namespace']),
    '#required' => TRUE,
  );


  $form['gmap_tools_settings'] += gmap_tools_gmap_settings_form(!empty($conf['gmap_tools_settings']) ? $conf['gmap_tools_settings'] : array());

  return $form;
}

//This feels ugly, why no way of declare settings in plugin definition instead?
//But ctools example does it this way so guess it's ok
function gmap_tools_slate_slate_gmap_content_type_settings_submit($form, &$form_state) {
  //TODO: validate instead of silently sanitizing
  $form_state['conf']['gmap_tools_settings']['container_id'] = drupal_clean_css_identifier($form_state['values']['gmap_tools_setting']['container_id']);
  $form_state['conf']['bundles'] = array_filter($form_state['values']['bundles']);
  foreach(array('gmap_slate', 'gmap_item_content_slate', 'lat_lng_field', 'gmap_tools_settings') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Render callback.
 */
function gmap_tools_slate_slate_gmap_content_type_render($subtype, $conf, $panel_args, $context) {
  global $language_content;
  list(, $entity_type) = explode(':', $subtype);

  $block = new stdClass();
  $block->title = t('Library Map');

  //TODO: add field condition to avoid fetching entities without the geofield!!
  if (empty($context->data)) { //TODO: remove this check?
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $entity_type);
    if(!empty($conf['bundles'])) {
      foreach($conf['bundles'] as $bundle_name) {
        $query->entityCondition('bundle', $bundle_name);
      }
    }
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
    $entities = array($context->data);
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

  //TODO: respect create map setting


  //If only one item, set as map center, and deactive fit-bounds behavior
  //Is this kludgy or nice?
  if(count($gmap_items) === 1) {
    $gmap_item = current($gmap_items);
    $conf['gmap_tools_settings']['gmap_tools_gmap_options']['center']['lat'] = $gmap_item['lat'];
    $conf['gmap_tools_settings']['gmap_tools_gmap_options']['center']['lng'] = $gmap_item['lng'];
    //TODO: Could screw with max/min zoom settings? Instead adjust behavior in
    //js?
    $conf['gmap_tools_settings']['gmap_tools_behaviors']['fit_items_bounds']['enabled'] = FALSE;
  }

  //This will add all js-settings etc
  gmap_tools_gmap($gmap_namespace, $gmap_container_id, $gmap_items, $conf['gmap_tools_settings']);

  $block->content = slate_render($conf['gmap_slate'], array(
    //or setting for id? Yes, with default as namespace css identifier
    'id' => $gmap_container_id,
  ));

  return $block;
}
