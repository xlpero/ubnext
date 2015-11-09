<?php
/**
 * @file
 */



/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('General: Search widget'),
  'description' => t('This is the search widget that will forward search to Summon'),
  'category' => 'UBNext',
  'edit form' => 'ubn_general_search_widget_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_general_search_widget_content_type_settings($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['number_of_items'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of items'),
    '#description' => t('The number of items in Summon'),
    '#default_value' => !empty($conf['number_of_items']) ? $conf['number_of_items'] : '100 000',
  );
  return $form;
}



/**
 * Ctools edit form submit handler.
 *
 * @param $form
 * @param $form_state
 */
function ubn_general_search_widget_content_type_settings_submit($form, &$form_state) {
      foreach (array('number_of_items') as $key) {
        $form_state['conf'][$key] = $form_state['values'][$key];
      }
     // $form_state['conf']['number_of_items'] = $form_state['values'][];
}

/**
 * 
 *
 * Render callback.
 */
function ubn_general_search_widget_content_type_render($subtype, $conf, $panel_args, $context) {
  global $language;
  $block = new stdClass();
  $number = '100000000'; // default number
  if (!empty($conf['number_of_items'])) {
    $number = $conf['number_of_items'];
  }
  elseif ($record_count = variable_get('ubn_general_summon_record_count', FALSE)) {
    $number = $record_count;
  }
  $search_slogan = t(
    'Search among <strong class="hidden-xs"> @number </strong> books, articles, magazines and more...',
    array(
      '@number' => _ubn_slate_number_format($number)
    )
  );
  $lang =  $language->language;
  //dpm($lang);
  if ($lang == 'en') {
    $url = "http://gothenburg.summon.serialssolutions.com/en/search/";
  }
  elseif ($lang == 'sv') {
    $url = "http://gothenburg.summon.serialssolutions.com/sv-SE/search/";
  }

  $search_list  = array(
    'slogan' =>  $search_slogan,
    'placeholder' => t('Search for...'),
    'aria' => 'Search terms',
    'url' => $url
  );

  //$block->title = "detta är titel";
  $block->content = slate_render('search-widget', array('list' => $search_list));//drupal_get_form('ubn_general_super_search_form');
  drupal_add_js(drupal_get_path('module', 'ubn_general') . '/plugins/content_types/search_widget/search-widget.js');

  return $block;
}


