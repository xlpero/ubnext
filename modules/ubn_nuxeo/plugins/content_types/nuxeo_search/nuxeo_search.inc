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

function _ubn_nuxeo_search($search_params = array()) {

  if (empty($search_params)) {
    $search_string = 'dooku.ub.gu.se:8080/nuxeo/api/v1/query/CoreQueryDocumentPageProvider?query=SELECT+*+FROM+Document+WHERE+ecm%3Afulltext+%3D+%3F+AND+ecm%3AprimaryType+%3D+%27File%27+AND+ecm%3AcurrentLifeCycleState+%3C%3E+%27deleted%27+AND+ecm%3AisLatestVersion+%3D+1&queryParams=hjalp&pageSize=10';
  }

  $json = '{"entity-type":"documents","isPaginable":true,"resultsCount":3,"pageSize":10,"maxPageSize":0,"currentPageSize":3,"currentPageIndex":0,"numberOfPages":1,"isPreviousPageAvailable":false,"isNextPageAvailable":false,"isLastPageAvailable":false,"isSortable":true,"hasError":false,"errorMessage":null,"totalSize":3,"pageIndex":0,"pageCount":1,"entries":[{"entity-type":"document","repository":"default","uid":"50cb470b-ca2c-4493-a487-8c4e606286ab","path":"/Filsystem/workspaces/P/DigIT/Utvecklarteamet/Minnesanteckningar/._Word Work File D_3.tmp._1418137235281_.trashed","type":"File","state":"project","parentRef":"8e9b03fe-da75-4e14-970d-f1b6c46b5f2f","versionLabel":"0.1","isCheckedOut":false,"title":"._Hej kom och hjalp mig.docx","lastModified":"2014-12-09T14:52:35.81Z","facets":["Downloadable","Commentable","Immutable","Versionable","Metadata","Publishable","HasRelatedText","Thumbnail"],"changeToken":"1418136755815","contextParameters":{"documentURL":"/nuxeo/nxdoc/default/50cb470b-ca2c-4493-a487-8c4e606286ab/view_documents"}},{"entity-type":"document","repository":"default","uid":"0b268e18-9748-4b22-a9b7-409ec18f111f","path":"/Filsystem/workspaces/P/DigIT/Utvecklarteamet/Minnesanteckningar/._Word Work File D_44161._1418137253465_.trashed","type":"File","state":"project","parentRef":"8e9b03fe-da75-4e14-970d-f1b6c46b5f2f","versionLabel":"0.1","isCheckedOut":false,"title":"._Hej kom och hjalp mig.docx","lastModified":"2014-12-09T15:00:34.92Z","facets":["Downloadable","Commentable","Immutable","Versionable","Metadata","Publishable","HasRelatedText","Thumbnail"],"changeToken":"1418137234929","contextParameters":{"documentURL":"/nuxeo/nxdoc/default/0b268e18-9748-4b22-a9b7-409ec18f111f/view_documents"}},{"entity-type":"document","repository":"default","uid":"15b09ab1-eedd-4bd3-9c6e-cbc3c29a7cee","path":"/Filsystem/workspaces/P/DigIT/Utvecklarteamet/Minnesanteckningar/._Word Work File D_44198._1418137318411_.trashed","type":"File","state":"project","parentRef":"8e9b03fe-da75-4e14-970d-f1b6c46b5f2f","versionLabel":"0.1","isCheckedOut":false,"title":"._Hej kom och hjalp mig.docx","lastModified":"2014-12-09T15:01:11.64Z","facets":["Downloadable","Commentable","Immutable","Versionable","Metadata","Publishable","HasRelatedText","Thumbnail"],"changeToken":"1418137271642","contextParameters":{"documentURL":"/nuxeo/nxdoc/default/15b09ab1-eedd-4bd3-9c6e-cbc3c29a7cee/view_documents"}}]}';
  return json_decode($json, true);
}

/**
 * @param $results
 * @return array
 */
function _ubn_nuxeo_get_resultlist($results) {
  //var_dump($results['entries']);

  $data = array();

  foreach ($results['entries'] as $entry) {
    $data[] = array(
      'filename' => $entry['title'],
      'url' => $entry['contextParameters']['documentURL'],
      'author' => $entry['uid'],
      'size' => $entry['entity-type'],
    );
  }
  return $data;
}

function _ubn_nuxeo_get_query_params() {
  $params = drupal_get_query_parameters();
  var_dump($params);
  return $params;
};

/**
 * Render callback.
 */
function ubn_nuxeo_nuxeo_search_content_type_render($subtype, $conf, $panel_args, $context) {
  $params = _ubn_nuxeo_get_query_params();

  $resultlist = _ubn_nuxeo_get_resultlist(_ubn_nuxeo_search());
  //var_dump($resultlist);
  
  $block = new stdClass();
  $block->title = t('Nuxeo search');
  $block->content = slate_render('nuxeo_search', array('resultlist' => $resultlist));

  return $block;
}
