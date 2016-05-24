<?php
/**
 * @file
 * Contains the UBNSearchApiSpellcheckSolr class.
 */

/**
 * Spellcheck class which can provide spelling suggestions. The constructor
 * populates the instance with any suggestions returned by Solr.
 */
class UBNSearchApiSpellcheckSolr extends SearchApiSpellcheckSolr {

  /**
   * Accepts a Drupal arg number which is used to get the value submitted and
   * returns a link to the current page with whatever value is in the URL
   * argument replaced with a suggestion.
   *
   * This method is for search pages which submit the search key string as an
   * argument in a url such as:
   * /search/foo%20bar
   *
   * @param int $arg
   *   Drupal URL argument.
   *
   * @return
   *   SearchApiSpellcheckSuggestionLink if any suggestions could be applied.
   *   if not then returns FALSE.
   *
   * @see getSuggestionLinkForGet()
   */
  public function getSuggestionLinkForArg($arg) {
    if ($suggestion = $this->getSuggestion(arg($arg))) {
      return new UBNSearchApiSpellcheckSuggestionLink($suggestion, 'arg', $arg);
    }
    return FALSE;
  }

  /**
   * Accepts a a query string key  which is used to get the value submitted and
   *
   * returns a link to the current page with whatever value is in the
   * query string replaced with a suggestion.
   *
   * This method is for search pages which submit the search key string as a
   * field in the query string such as:
   * /search/?key=foo%20bar
   *
   * @param string $get
   *   Query string field.
   *
   * @see getSuggestionLinkForArg()
   */
  public function getSuggestionLinkForGet($get) {
    if (isset($_GET[$get])) {
      $original = $_GET[$get];
      if (is_string($original) && $suggestion = $this->getSuggestion($original)) {
        return new UBNSearchApiSpellcheckSuggestionLink($suggestion, 'get', $get);
      }
    }
    return FALSE;
  }
}
