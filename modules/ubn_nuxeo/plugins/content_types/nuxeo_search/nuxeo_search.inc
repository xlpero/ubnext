<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Nuxeo: Search'),
  'description' => t('Search filesystem on Nuxeo server.'),
  'category' => 'UBNext',
  /*'required context' => new ctools_context_required(t('Library'), 'entity:node'),*/
  'edit form' => 'ubn_nuxeo_nuxeo_search_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_nuxeo_nuxeo_search_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */

function ubn_nuxeo_nuxeo_search_search($query = null, $filter = null) {

  $data = array(
    array(
      'filename' => 'title 1', 
      'url' => 'http://www.google.se',
      'author' => 'Johan Von Geijer',
      'size' => '200kb',
    ),
    array(
      'filename' => 'title 2', 
      'url' => 'http://www.google.se',
      'author' => 'Johan Von Geijer',
      'size' => '200kb',
    ),
  );

  return $data;
};


function ubn_nuxeo_nuxeo_search_get_query_params() {

};

function ubn_nuxeo_nuxeo_search_content_type_render($subtype, $conf, $panel_args, $context) {
 

  //global $language_content;

  //$data = entity_metadata_wrapper('node', $context->data);
  //$data = []

     // $data->language($language_content->language);
  $data = ubn_nuxeo_nuxeo_search_search();
  
  $block = new stdClass();
  $block->title = t('Nuxeo search');
  $block->content = slate_render('nuxeo_search', array('resultlist' => $data));

  return $block;
}
