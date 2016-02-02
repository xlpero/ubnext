<?php
/**
 * @file
 * Contains SearchApiSolrAutocompleteServerSuggester.
 */

/**
 * Provides a suggester plugin that retrieves suggestions from the Solr
 * SuggesterComponent.
 *
 * The server needs to be a Solr 5.0+ server for this to work properly.
 */
class SearchApiSolrAutocompleteServerSuggester extends SearchApiAutocompleteServerSuggester {

  /**
   * {@inheritdoc}
   */
  public static function supportsIndex(SearchApiIndex $index) {
    //TODO: how get service class, and instance of?
    try {
      $server = $index->server();
      $service_info = search_api_get_service_info($server->class);
      return
        $service_info['class'] === 'SearchApiSolrService' ||
        is_subclass_of($service_info['class'], 'SearchApiSolrService');
    }
    catch (SearchApiException $e) {
      return FALSE;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function defaultConfiguration() {
    $index = $this->getSearch()->index();
    return parent::defaultConfiguration() + array(
      'solr_server' => array(
        'suggester_path' => 'autocomplete',
        'suggester_dictionaries' => '',
      ),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function buildConfigurationForm(array $form, array &$form_state) {
    $form = parent::buildConfigurationForm($form, $form_state);
    $form['solr_server'] = array(
      '#type' => 'fieldset',
      '#title' => t('Solr server'),
      '#desciption' => t('Solr server suggester settings'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#tree' => TRUE,
    );
    $form['solr_server']['suggester_dictionaries'] = array(
      '#title' => t('Suggester dictionaries'),
      '#type' => 'textarea',
      '#description' => t('One dictionary per line, in order of precedence.'),
      '#default_value' => implode("\n", $this->configuration['solr_server']['suggester_dictionaries']),
    );
    return $form;
  }
  /**
   * {@inheritdoc}
   */
  public function submitConfigurationForm(array $form, array &$form_state) {
    $form_state['values']['solr_server']['suggester_dictionaries'] =
      array_map(
        'trim',
        explode(
          "\n",
          $form_state['values']['solr_server']['suggester_dictionaries']
        )
      );
    parent::submitConfigurationForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function getAutocompleteSuggestions(SearchApiQueryInterface $query, $incomplete_key, $user_input) {
    return $query
      ->getIndex()
      ->server()
      ->getSolrSuggestionCompomentAutocompleteSuggestions(
          $user_input,
          $this->configuration['solr_server']
        );
  }
}
