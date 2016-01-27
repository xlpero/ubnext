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
  /*
  public function defaultConfiguration() {
    return array(
      'fields' => array(
        //'autocomplete' => 1,?
      ),
    );
  }
  */

  /**
   * {@inheritdoc}
   */
  public function buildConfigurationForm(array $form, array &$form_state) {
    $form = parent::buildConfigurationForm($form, $form_state);
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function getAutocompleteSuggestions(SearchApiQueryInterface $query, $incomplete_key, $user_input) {
    return $query->getIndex()->server()->getAutocompleteSuggestions($query, $this->getSearch(), $incomplete_key, $user_input);
  }
}
