<?php
//TODO: Implement supportsIndex etc!!!!

/**
 * @file
 * Contains UBNSearchApiAutocompleteServerSuggester.
 */

/**
 * Provides a suggester plugin that retrieves suggestions from the server.
 *
 * The server needs to support the "search_api_autocomplete" feature for this to
 * work.
 */
class UBNSearchApiAutocompleteServerSuggester extends SearchApiAutocompleteServerSuggester {
  /**
   * {@inheritdoc}
   */
  public function defaultConfiguration() {
    $index = $this->getSearch()->index();
    return parent::defaultConfiguration() + array(
      'ubn_solr_server' => array(
        'suggester_path' => 'autocomplete',
        'suggester_dictionaries' => $index->machine_name . '_infix',
      ),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function buildConfigurationForm(array $form, array &$form_state) {
    $form = parent::buildConfigurationForm($form, $form_state);

    //TODO: namespacing?
    $form['ubn_solr_server'] = array(
      '#type' => 'fieldset',
      '#title' => t('UBN Solr Server'),
      '#desciption' => t('UBN Solr Server'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#tree' => TRUE,
    );
    $form['ubn_solr_server']['suggester_path'] = array(
      '#title' => t('Suggester request handler path'),
      '#type' => 'textfield',
      '#description' => 'todo',
      '#default_value' => $this->configuration['ubn_solr_server']['suggester_path'],
    );
    //TODO: support for multiple dicts
    $form['ubn_solr_server']['suggester_dictionaries'] = array(
      '#title' => t('Suggester dictionaries'),
      '#type' => 'textarea',
      '#description' => 'One dictionary per line, in order of preference.',
      '#default_value' => $this->configuration['ubn_solr_server']['suggester_dictionaries'],
    );
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function getAutocompleteSuggestions(SearchApiQueryInterface $query, $incomplete_key, $user_input) {
    return $query->getIndex()->server()->getAutocompleteSuggestions(
      $query,
      $this->getSearch(),
      $incomplete_key,
      $user_input,
      $this->configuration['ubn_solr_server']
    );
  }
}
