<?php
/**
 * @file
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Terms: Search results'),
  'description' => t('Terms search results.'),
  'category' => 'UBNext',
  'edit form' => 'ubn_terms_terms_search_result_content_type_settings',
);

/**
 * Settings callback.
 */
function ubn_terms_terms_search_result_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_terms_terms_search_result_content_type_render($subtype, $conf, $panel_args, $context) {
  global $language_content;

  drupal_add_js(drupal_get_path('theme', 'ubnext') . '/js/vendor/jquery.scrollTo.min.js');
  drupal_add_js(drupal_get_path('module', 'ubn_terms') . '/js/ubn_terms.js');

  $default_groups = array(
    'sv' => array(
      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'Å', 'Ä', 'Ö'
    ),
    'en' => array(
      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    ),
  );

  $query = new EntityFieldQuery();
  $results = $query
    ->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', array('term', 'term_synonym'), 'IN')
    ->fieldOrderBy('name_field', 'value', 'ASC')
    ->execute();

  $terms = array();
  if (!empty($results['taxonomy_term'])) {
    $terms = entity_load('taxonomy_term', array_keys($results['taxonomy_term']));
  }

  //UTF-8 array keys ok? Seems so but not 100% sure
  $grouped_terms = array();
  foreach($terms as $term) {
    $first_letter = drupal_substr($term->name, 0, 1);
    $group = NULL;
    $matches = array();
    preg_match('@\p{L}|\p{N}@u', $first_letter, $matches);
    if (!empty($matches[0])) {
      $group = is_numeric($first_letter) ? '[0-9]' : drupal_strtoupper($first_letter);
      $grouped_terms[$group][] = $term;
    }
    else {
      //TODO: this is pretty ugly, but wtf
      global $user;
      if($user->uid) {
        drupal_set_message(t('Invalid first letter "%letter" for term "%term"', array('%letter' => $first_letter, '%term' => $term->name)), 'warning');
      }
    }
  }


  $groups = array_unique(array_merge($default_groups[$language_content->language], array_keys($grouped_terms)));
  usort($groups, 'ubn_general_strnatcmp');

  //Special case for 0-9, always last for all collations
  $key = array_search('0-9', $groups);
  if($key !== FALSE) {
    unset($groups[$key]);
  }
  $groups[] = '0-9';

  $term_groups = array();
  foreach($groups as $group) {
    $term_group = array(
      'group' => array(
        'name' => $group,
        'identifier' => ubn_term_safe_css_identifier($group),
      ),
      'terms' => array(),
    );
    if(isset($grouped_terms[$group])) {
      foreach($grouped_terms[$group] as $term) {
        $renderable = entity_view('taxonomy_term', array($term), 'ubn_term_search_result');
        $term_group['terms'][$term->tid] = drupal_render($renderable);
      }
    }
    $term_groups[] = $term_group;
  }

  $block = new stdClass();
  $block->title = t('Search');
  $block->content = slate_render('terms-search-result', array(
    'term_groups' => $term_groups,
  ));
  return $block;
}
