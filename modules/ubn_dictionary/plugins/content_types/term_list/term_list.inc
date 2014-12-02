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
  global $language_content;

  $block = new stdClass();
  $block->title = t('List of Terms');

  $query = new EntityFieldQuery();

  $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'dictionary_term')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->addTag('ENTITY_TRANSLATION');

  $result = $query->execute();

  $list = array_fill_keys(ubn_dictionary_get_index(), array());

  if (!empty($result['node'])) {
    foreach (entity_load('node', array_keys($result['node'])) as $_term) {
      $term = entity_metadata_wrapper('node', $_term);

      $term->language($language_content->language);

      $key = mb_substr($term->label(), 0, 1);

      $key = drupal_strtolower($key);

      if (!isset($list[$key])) {
        $key = '0-9';
      }

      $list[$key][$term->label()] = array(
        'label' => $term->label(),
        'entity' => $term,
        'primary' => TRUE,
      );

      foreach ($term->field_dictionary_term_synonyms as $synonym) {
        $key = mb_substr($synonym->value(), 0, 1);

        $key = drupal_strtolower($key);

        if (!isset($list[$key])) {
          $key = '0-9';
        }

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
  }

  $block->content = slate_render('dictionary_term-list', array('list' => $list));

  return $block;
}
