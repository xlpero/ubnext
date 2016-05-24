<?php
/**
 * @file
 * The class is a helpful way to provide both an updated search query link and
 * access to all the link components for themers.
 */
class UBNSearchApiSpellcheckSuggestionLink extends SearchApiSpellcheckSuggestionLink {

  //TODO: Highlight corrected words like google would be neat?
  /**
   * Constructor.
   *
   * @param SearchApiSpellcheckSuggestion $suggestion
   *   Suggestion to create a link for.
   * @param string $method
   *   A value to represent where the search key is in the url:
   *   - 'get': For the query string such as /search/?key=foo%20bar
   *   - 'arg': For an argument such as /search/foo%20bar
   * @param mixed $method_key
   *   Where in the URL the search key is. This value is different depending on
   *   $method:
   *   - For 'get' string: the query string field
   *   - For 'arg' int: the argument number
   */
  public function __construct(SearchApiSpellcheckSuggestion $suggestion, $method, $method_key) {
    $this->original = $suggestion->original;
    $this->suggestion = $suggestion->suggestion;
    $this->method = $method;
    $this->method_key = $method_key;
    $this->createPath();
    $this->createQuery();
    $this->createUrl();
    $this->createLink();
  }

  /**
   * Sets the property 'path' to the location of search results and also attempting
   * to extract possible path alias for search page base path
   *
   *
   * If the search key is stored in an argument then this part of the path will
   * be updated with the suggested string.
   */
  public function createPath() {
    $args = arg();
    $base_path = implode('/', array_slice($args, 0, $this->method_key));
    $path_alias = drupal_get_path_alias($base_path);
    if ($this->method == 'arg') {
      $args[$this->method_key] = $this->suggestion;
    }
    $this->path = $path_alias . '/' . implode('/', array_slice($args, $this->method_key));
  }
}
