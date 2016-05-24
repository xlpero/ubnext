<?php
/**
 * @file
 * The class is a helpful way to provide both an updated search query link and
 * access to all the link components for themers.
 */
class UBNSearchApiSpellcheckSuggestionLink extends SearchApiSpellcheckSuggestionLink {
  //TODO: Highlight corrected words like google would be neat?
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
