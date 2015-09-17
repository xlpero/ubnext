<?php

/**
 * Fetches data via HTTP.
 */
class UBNOpeningHoursFeedsFetcher extends FeedsFetcher {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $source_config = $source->getConfigFor($this);

    //This could be a setting, or use sites timezone?
    $tz = new DateTimeZone('Europe/Stockholm');
    $now = new DateTime('now', $tz);

    $query = array(
      'start_date' => $now->format('Y-m-d'),
      'days' => 7, //setting for this?
      'lang' => 'sv', //hmmm
    );

    //TODO: use drupal_http_build_query instead to get rid of potential url
    // rewriting etc?
    $url = url($source_config['endpoint_url'], array('query' => $query, 'external' => TRUE));

    $options = array();
    if(!empty($this->config['request_timeout'])) {
      $options['timeout'] = $this->config['request_timeout'];
    }

    $result = drupal_http_request($url, $options);

    //TODO: proper error handling?
    if(isset($result->error)) {
      throw new Exception($result->error);
    }
    else if($result->code != 200) {
      throw new Exception('Expected HTTP response code 200, got ' . $result->code);
    }

    $fetcher_result = new FeedsFetcherResult($result->data);

    return $fetcher_result;
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'request_timeout' => NULL,
    );
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    // Per importer override of global http request timeout setting.
    $form['request_timeout'] = array(
      '#type' => 'textfield',
      '#title' => t('Request timeout'),
      '#description' => t('Timeout in seconds to wait for an HTTP get request to finish. Default value is 30.'),
      '#default_value' => $this->config['request_timeout'],
      '#element_validate' => array('element_validate_integer_positive'),
      '#maxlength' => 3,
      '#size'=> 30,
    );
    return $form;
  }

  /**
   * Expose source form.
   */
  public function sourceForm($source_config) {
    $form = parent::sourceForm($source_config);
    $form['endpoint_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Endpoint url'),
      '#default_value' => !empty($source_config['endpoint_url']) ? $source_config['endpoint_url'] : 'http://130.241.35.161:3014/locations',
      '#maxlength' => NULL,
      '#required' => TRUE,
    );
    return $form;
  }

  /**
   * Override parent::sourceFormValidate().
   */
  public function sourceFormValidate(&$values) {
    $values['endpoint_url'] = trim($values['endpoint_url']);

    // Keep a copy for error messages.
    $original_url = $values['endpoint_url'];

    if (!feeds_valid_url($values['endpoint_url'], TRUE)) {
      $form_key = 'feeds][' . get_class($this) . '][endpoint_url';
      form_set_error($form_key, t('The URL %endpoint_url is invalid.', array('%endpoint_url' => $original_url)));
    }
  }

  /**
   * Implement FeedsFetcher::importPeriod().
   */
  /*
  public function importPeriod(FeedsSource $source) {
  }
  */

}
