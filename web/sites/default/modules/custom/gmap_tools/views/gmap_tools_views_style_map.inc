<?php
/**
 * @file
 * This file holds style plugin for gmap_tools Views
 *
 * @ingroup gmap_tools
 */

/**
 * @class
 * Extension of the Views Plugin Syle for gmap_tools
 *
 */
class gmap_tools_views_style_map extends views_plugin_style {
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
   
    $options['gmap_tools_namespace'] = array(
      'default' => 'default',
    );

    $options['gmap_tools_bindings'] = array(
      'default' => array(
        'title' => '',
        'lat' => '',
        'lng' => '',
        'marker' => 'default',
      ),
    );

    $behaviors_defaults = array();

    foreach(array_keys(gmap_tools_behaviors()) as $behavior) {
      $behaviors_defaults[$behavior] = array(
        'enabled' => FALSE,
      );
    }

    $options['gmap_tools_behaviors'] = array(
      'default' => $behaviors_defaults,
    );

    //TODO: states
    $options['gmap_tools_gmap_create_gmap'] = array(
      'default' => TRUE,
    );

    $options['gmap_tools_gmap_options'] = array(
      'default' => array(
        'mapTypeId' => 'ROADMAP',
        'zoom' => 12,
        'min_zoom' => '',
        'max_zoom' => '',
        'center' => array(
          'lat' => '',
          'lng' => '',
        ),
      ),
    );

    $options['gmap_tools_bindings_extra'] = array(
      'default' => array(
      ),
    );

    return $options;
  }
  
  
  /**
   * Options form
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    //Prefered way of fething this?
    $fields = isset($this->view->display[$this->view->current_display]->display_options['fields']) ?
      array_keys($this->view->display[$this->view->current_display]->display_options['fields']) :
      array_keys($this->view->display['default']->display_options['fields']);

    $field_options = drupal_map_assoc($fields);

    $form['gmap_tools_namespace'] = array(
      '#title' => t('Namespace'),
      '#type' => 'textfield',
      '#required' => TRUE,
      '#default_value' => $this->options['gmap_tools_namespace'],
    );

    $form['gmap_tools_options'] = array(
      '#title' => t('Gmap tools options'),
      '#type' => 'fieldgroup',
      '#tree' => TRUE,
    );

    //TODO: states
    $form['gmap_tools_gmap_create_gmap'] = array(
      '#title' => t('Create gmap'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['gmap_tools_gmap_create_gmap'],
    );

    $form['gmap_tools_gmap_options'] = array(
      '#title' => t('Gmap options'),
      '#type' => 'fieldset',
      '#tree' => TRUE,
    );

    $gmap_options = $this->options['gmap_tools_gmap_options'];

    //foreach(gmap_tools_gmap_options() as $gmap_option => $gmap_options) {
      $form['gmap_tools_gmap_options']['mapTypeId'] = array(
        '#title' => 'mapTypeId',
        '#type' => 'select',
        '#options' => array(
          'ROADMAP' => t('Roadmap'),
          'SATTELITE' => t('Sattelite'),
          'HYBRID' => t('Hybrid'),
          'TERRAIN' => t('Terrain'),
        ),
      );
    $form['gmap_tools_gmap_options']['zoom'] = array(
      '#title' => 'zoom',
      '#type' => 'select',
      '#options' => range(0, 19),
      '#default_value' => $gmap_options['zoom'],
    );
    
    $form['gmap_tools_gmap_options']['min_zoom'] = array(
      '#title' => 'min_zoom',
      '#type' => 'select',
      '#options' => array('' => t('-- Select --')) + range(0, 19),
      '#default_value' => $gmap_options['min_zoom'],
    );

    $form['gmap_tools_gmap_options']['max_zoom'] = array(
      '#title' => 'max_zoom',
      '#type' => 'select',
      '#options' => array('' => t('-- Select --')) + range(0, 19),
      '#default_value' => $gmap_options['max_zoom'],
    );

    $form['gmap_tools_gmap_options']['center'] = array(
      '#title' => 'center',
      '#type' => 'fieldset',
    );

    $form['gmap_tools_gmap_options']['center']['lat'] = array(
      '#title' => t('Latitude'),
      '#type' => 'textfield',
      '#required' => TRUE,
      '#default_value' => $gmap_options['center']['lat'],
    ); 

    $form['gmap_tools_gmap_options']['center']['lng'] = array(
      '#title' => t('Longitude'),
      '#type' => 'textfield',
      '#required' => TRUE,
      '#default_value' => $gmap_options['center']['lng'],
    ); 

    //}

    $form['gmap_tools_bindings'] = array(
      '#title' => t('Required Bindings'),
      '#type' => 'fieldset',
      '#tree' => TRUE,
    );

    $bindings = $this->options['gmap_tools_bindings'];

    $form['gmap_tools_bindings']['title'] = array(
      '#title' => t('Title source'),
      '#description' => 'todo',
      '#type' => 'select',
      '#options' => $field_options,
      '#required' => TRUE,
      '#default_value' => $bindings['title'],
    );

    $form['gmap_tools_bindings']['lat'] = array(
      '#title' => t('Latitude source'),
      '#description' => 'todo',
      '#type' => 'select',
      '#options' => $field_options,
      '#required' => TRUE,
      '#default_value' => $bindings['lat'],
    );
    
    $form['gmap_tools_bindings']['lng'] = array(
      '#title' => t('Longitude source'),
      '#description' => 'todo',
      '#type' => 'select',
      '#options' => $field_options,
      '#required' => TRUE,
      '#default_value' => $bindings['lng'],
    );

    $form['gmap_tools_bindings']['marker'] = array(
      '#title' => t('Marker type source'),
      '#description' => 'todo',
      '#type' => 'select',
      '#options' => array('' => t('-- Select --')) + $field_options,
      '#default_value' => $bindings['marker'],
    );

    $form['gmap_tools_bindings_extra'] = array(
      '#title' => t('Extra Bindings'),
      '#type' => 'fieldset',
      '#tree' => TRUE,
    );

    $bindings_extra = $this->options['gmap_tools_bindings_extra'];

    $bindings_extra[] = array('source' => '', 'target' => '');
    
    end($bindings_extra);
    $last_delta = key($bindings_extra);

    foreach($bindings_extra as $delta => $binding) {
      $form['gmap_tools_bindings_extra'][$delta] = array(
        //'#title' => 'Binding ' . $delta, //todo: t
        '#type' => 'container',
        //'#tree' => TRUE, //do i need this?
      );

      $form['gmap_tools_bindings_extra'][$delta]['source'] = array(
        '#title' => t('Source'),
        '#type' => 'select',
        '#options' => $field_options,
        '#default_value' => $binding['source'],
      );

      //todo: machinenameshit?
      $form['gmap_tools_bindings_extra'][$delta]['target'] = array(
        '#title' => t('Target'),
        '#type' => 'textfield',
        '#default_value' => $binding['target'],
      );
      if($delta !== $last_delta) {
        $form['gmap_tools_bindings_extra'][$delta]['delete'] = array(
          '#title' => t('Delete'),
          '#type' => 'checkbox',
          '#return_value' => $delta,
        );
      }
    }

    $form['gmap_tools_behaviors'] = array(
      '#title' => t('Behaviors'),
      '#type' => 'fieldset',
      '#description' => 'todo',
    );

    $behaviors = $this->options['gmap_tools_behaviors'];

    $js_data_types = gmap_tools_js_data_types();

    foreach(gmap_tools_behaviors() as $behavior => $info) {
      $form['gmap_tools_behaviors'][$behavior] = array(
        '#type' => 'fieldset',
        '#title' => $info['label'],
        '#description' => isset($info['description']) ? $info['description'] : NULL,
        '#tree' => TRUE,
      );

      $form['gmap_tools_behaviors'][$behavior]['enabled'] = array(
        '#title' => t('Enable'),
        '#type' => 'checkbox',
        '#default_value' => $behaviors[$behavior]['enabled']
      );
      if(isset($info['options'])) {
        $form['gmap_tools_behaviors'][$behavior]['options'] = array(
          '#title' => t('Options'),
          '#type' => 'fieldset',
        );

        foreach($info['options'] as $option => $definition) {
          $element = gmap_tools_js_data_type_form_element(
            $definition,
            isset($behaviors[$behavior]['options'][$option]) ? $behaviors[$behavior]['options'][$option] : NULL
          );

          $form['gmap_tools_behaviors'][$behavior]['options'][$option] = $element;

          //TODO: formapi states depending on enabled on theses
          /*
          $form['gmap_tools_behaviors'][$behavior]['options'][$option] = array(
            '#title' => $definition['label'],
            '#description' => isset($definition['description']) ? $definition['description'] : NULL,
            '#type' => $js_data_types[$definition['type']]['form_api_type'],
            '#required' => isset($definition['required']) ? $definition['required'] : FALSE,
            '#default_value' => 
              ,
          );
          */
        }
      }
    }
  }

  function gmap_tools_container_id() {
    return drupal_clean_css_identifier($this->view->name . '-' . $this->view->current_display);
  }


  function options_validate(&$form, &$form_state) {
    $options =& $form_state['values'][$form_state['section']];
    $bindings =& $options['gmap_tools_bindings_extra'];
    foreach(array_keys($bindings) as $delta) {
      if($bindings[$delta]['delete'] || empty($bindings[$delta]['target'])) {
        unset($bindings[$delta]);
      }
      else {
        // No need to save this
        unset($bindings[$delta]['delete']);
      }
    }
    $gmap_options =& $options['gmap_tools_gmap_options'];
    $gmap_options = array_filter($gmap_options);

    parent::options_validate($form, $form_state);
  }

  function gmap_tools_enabled_behaviors() {
    $enabled_behaviors = array();
    foreach($this->options['gmap_tools_behaviors'] as $behavior => $options) {
      if($options['enabled']) {
        //unset($options['enabled']);
        $enabled_behaviors[$behavior] = isset($options['options']) ? $options['options'] : array();
      }
    }
    return $enabled_behaviors;
  }
  
  /*
  function options_submit(&$form, &$form_state) {
    dsm('submit');
    parent::options_submit($form, $form_state);
  }
  */

  /**
   * Renders views (map)
   */

  function gmap_tools_gmap_options() {
    $options = array_filter($this->options['gmap_tools_gmap_options']);
    $options['zoom'] = (int) $options['zoom'];
    if(isset($options['max_zoom'])) {
      $options['max_zoom'] = (int) $options['max_zoom'];
    }
    if(isset($options['min_zoom'])) {
      $options['min_zoom'] = (int) $options['min_zoom'];
    }
    $options['center']['lat'] = (float) $options['center']['lat'];
    $options['center']['lng'] = (float) $options['center']['lng'];
    return $options;
  }


  function gmap_tools_bindings() {
    $bindings = array_filter($this->options['gmap_tools_bindings']);
    $bindings_extra = $this->options['gmap_tools_bindings_extra'];
    foreach($bindings_extra as $binding) {
      $bindings[$binding['target']] = $binding['source'];
    }
    return $bindings;
  }


  function render_grouping_sets($sets, $level = 0) {

    $output = '';
    //TODO: mappings/bindings... decide on one
    $gmap_mappings = $this->gmap_tools_bindings();

    $gmap_items = array();

    foreach ($sets as $set) {
      foreach ($set['rows'] as $index => $row) {

        $gmap_item = array();

        foreach($gmap_mappings as $target => $source) {
          if(isset($this->view->field[$source])) {
            $field = $this->view->field[$source];
            if($field->allow_advanced_render() && method_exists($field, 'render_item')) {
              $raw_items = $field->get_items($row);
              //TODO: This feels very unsafe
              if(isset($raw_items[0]['rendered'])) {
                $gmap_item[$target] = is_array($raw_items[0]['rendered']) ?
                  drupal_render($raw_items[0]['rendered']) :
                  $raw_items[0]['rendered'];
              }
            }
            else {
              $gmap_item[$target] = $field->render($row);
              if(is_array($gmap_item[$target])) {
                $gmap_item[$target] = drupal_render($gmap_item[$target]);
              }
            }
          }
          else {
            //TODO: Views debugshit
          }
        }
    
        //TODO: row_index?
        $this->view->row_index = $index;
        $set['rows'][$index] = $this->row_plugin->render($row);

        //TODO: how get row wrapper classes
        // in template file??
        $gmap_item['content'] = $set['rows'][$index];

        //TODO: $row->nid is unsafe! binding?
        $gmap_items['id-' . $row->nid] = $gmap_item;
      }
    }

    $js_settings = array(
      //TODO: add create gmap thingy
      'items' => $gmap_items,
    );

    if($this->options['gmap_tools_gmap_create_gmap']) {
      $js_settings += array(
        'container_id' => $this->gmap_tools_container_id(),
        'behaviors' => array(),
        'gmap_options' => $this->gmap_tools_gmap_options(), //fix this (array_filter)
      );
      //Add behaviors js
      //Function for just fetching js, method for init a behavior?
      $behaviors = gmap_tools_behaviors();
      $behaviors_js = array();
      foreach($this->gmap_tools_enabled_behaviors() as $behavior => $options) {
        gmap_tools_init_behavior($behavior);
        //This is kludy, how process in a prettier manner?
        $js_settings['behaviors'][$behavior] = array();
        foreach($options as $option => $value) {
          $type_instance = $behaviors[$behavior]['options'][$option];
          $js_value = gmap_tools_js_data_type_js_value($value, $type_instance);
          if(isset($js_value)) {
            $js_settings['behaviors'][$behavior][$option] = $js_value;
          }
        }
      }

      $container = array(
        '#type' => 'html_tag',
        '#tag' => 'div',
        '#value' => 'Gmap loading...',
        '#attributes' => array(
          'id' => $this->gmap_tools_container_id(),
          'class' => 'gmap-tools-gmap',
          //'style' => 'width:500px;height:500px;',
        ),
      );

      $output .= theme($this->theme_functions(),
        array(
          'view' => $this->view,
          'options' => $this->options,
          'gmap_container' => drupal_render($container))
        );

    }

    drupal_add_js(
      array(
        'gmap_tools_views'=> array(
          $this->options['gmap_tools_namespace'] => $js_settings,
        ),
      ),
      'setting'
    );

    unset($this->view->row_index);
    return $output;
  }
}
