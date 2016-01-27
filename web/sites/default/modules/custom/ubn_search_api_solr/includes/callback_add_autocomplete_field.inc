<?php

/**
 * @file
 * Contains UBNSearchApiSolrAlterAddAutocompleteField.
 */

/**
 * Search API data alteration callback that adds an URL field for all items.
 */
class UBNSearchApiSolrAlterAddAutocompleteField extends SearchApiAbstractAlterCallback {

  public function configurationForm() {
    $form['enable'] = array(
      '#title' => t('Enable'),
      '#type' => 'checkbox',
      '#default_value' => 0,
    );
    return $form;
  }

  public function configurationFormValidate(array $form, array &$values, array &$form_state) {
  }

  public function configurationFormSubmit(array $form, array &$values, array &$form_state) {
    if (empty($values['enable'])) {
      return array();
    }
    $this->options = $values;
    return $values;
  }

  public function alterItems(array &$items) {
  }

  public function propertyInfo() {
    $info = array();
    //if enabled
    $info['autocomplete'] = array(
      'label' => t('Autocomplete field'),
      'description' => 'todo',
      'type' => 'text', //ok?
    );
    return $info;
  }
}
