<?php
/**
 * @file
 */


/**
 * Plugin definition.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Dictionary: List of Terms'),
  'description' => t('A List of Terms for a Dictionary.'),
  'category' => 'UBNext',
  'edit form' => 'ubn_dictionary_term_list_content_type_settings',
);


/**
 * Settings callback.
 */
function ubn_dictionary_term_list_content_type_settings($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function ubn_dictionary_term_list_content_type_render($subtype, $conf, $panel_args, $context) {
  global $language;

  $block = new stdClass();
  $block->title = t('List of Terms');

  $query = new EntityFieldQuery();

  $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'dictionary_term')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->propertyCondition('language', $language->language, '=');

  $result = $query->execute();

  // If there is no terms to show, bail.
  if (empty($result['node'])) {
    return;
  }

  $list = array_fill_keys(ubn_dictionary_get_index(), array());

  foreach (entity_load('node', array_keys($result['node'])) as $_term) {
    $term = entity_metadata_wrapper('node', $_term);

    $key = mb_substr($term->label(), 0, 1);

    $list[$key][$term->label()] = array(
      'label' => $term->label(),
      'entity' => $term,
      'primary' => TRUE,
    );

    foreach ($term->field_dictionary_term_synonyms as $synonym) {
      $key = mb_substr($synonym->value(), 0, 1);

      $list[$key][$synonym->value()] = array(
        'label' => $synonym->value(),
        'entity' => $term,
        'primary' => FALSE,
      );
    }
  }

  foreach ($list as &$terms) {
    uksort($terms, 'ubn_general_strnatcmp');
  }

  $block->content = slate_render('dictionary_term-list', array('list' => $list));

  return $block;
}
