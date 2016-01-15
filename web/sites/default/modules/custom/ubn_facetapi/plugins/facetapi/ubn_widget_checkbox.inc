<?php

class UBNFacetapiWidgetCheckbox extends FacetapiWidget {

  /**
   * Overrides FacetapiWidget::__construct().
   *
   * For links, it is better to use the machine name of the facet as opposed to
   * the alias for the key. Alias are usually, but not necessarily, unique. It
   * doesn't make sense to group links in the same element as they are usually
   * rendered in blocks with are separate from one another.
   */
  public function __construct($id, array $realm, FacetapiFacet $facet, stdClass $settings) {
    parent::__construct($id, $realm, $facet, $settings);
    $this->key = $facet['name'];
  }

  /**
   * Implements FacetapiWidget::execute().
   */
  public function execute() {
    $build = &$this->build[$this->facet['field alias']];
    $settings = $this->settings->settings;
    // Initializes links attributes, adds rel="nofollow" if configured.
    $attributes = ($settings['nofollow']) ? array('rel' => 'nofollow') : array();
    $attributes += array('class' => $this->getItemClasses());

    //TODO: Perhaps a little more robustness/configurability:
    // for now assuming "1"
    if(!empty($build) && isset($build[1])) {
      $checkbox_item = $build[1];
      $label = !empty($settings['checkbox_label']) ? $settings['checkbox_label'] : $checkbox_item['#markup'];
      $variables = array(
        'text' => $label,
        'active' => $checkbox_item['#active'],
        'path' => $checkbox_item['#path'],
        'container_attributes' => array('class' => 'ubn-facetapi-checkbox-item'),
        'options' => array(
          'attributes' => array('class' => 'ubn-facetapi-checkbox-item-link', 'rel' => 'nofollow'), //id?
          'html' => $checkbox_item['#html'],
          'query' => $checkbox_item['#query'],
        ),
      );
      $facet_title = theme('ubn_facetapi_checkbox_widget_item', $variables);

      $build = array(
        '#theme' => 'ubn_facetapi_item_list',
        '#items' => array(),
        '#attributes' => $this->build['#attributes'],
        '#container_attributes' => array('class' => array('ubn-facet', 'ubn-facet-checkbox')),
        '#title' => $facet_title,
      );
    }
    else {
      $build = array();
    }
  }

  /**
   * Gets the base class array for a facet item.
   *
   * @return array
   *   An array of classes.
   */
  function getItemClasses() {
    return array();
  }

  /**
   * Overrides FacetapiWidget::settingsForm().
   */
  function settingsForm(&$form, &$form_state) {
    // @see http://drupal.org/node/1370342
    $form['widget']['widget_settings']['links'][$this->id]['nofollow'] = array(
      '#type' => 'checkbox',
      '#title' => t('Prevent crawlers from following facet links'),
      '#default_value' => !empty($this->settings->settings['nofollow']),
      '#description' => t('Add the <code>rel="nofollow"</code> attribute to facet links to maximize SEO by preventing crawlers from indexing duplicate content and getting stuck in loops.'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    //TODO: i18n, how?
    //Default to field label? how?
    $form['widget']['widget_settings']['links'][$this->id]['checkbox_label'] = array(
      '#type' => 'textfield',
      '#title' => t('Checkbox label'),
      '#default_value' => !empty($this->settings->settings['checkbox_label']) ?
        $this->settings->settings['checkbox_label'] : '',
      '#description' => t('The checkbox label.'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
  }

  /**
   * Overrides FacetapiWidget::getDefaultSettings().
   */
  function getDefaultSettings() {
    return array(
      'nofollow' => 1,
      'checkbox_label' => '',
    );
  }
}
