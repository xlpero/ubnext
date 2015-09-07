<?php

/**
 * @file
 * Field Collection Item translation handler for the Entity Translation module.
 */

/**
 * Field Collection Item translation handler.
 *
 * Overrides default behaviours for Field Collection Item properties.
 */
class EntityTranslationFieldCollectionItemHandler extends EntityTranslationDefaultHandler {

  /**
   * {@inheritdoc}
   */
  public function __construct($entity_type, $entity_info, $entity) {
    parent::__construct('field_collection_item', $entity_info, $entity);

    // Initialize the path scheme for the current bundle, unless we are dealing
    // with the "default" bundle.
    if ($this->bundle != $entity_info['translation']['entity_translation']['default_scheme']) {
      $this->setPathScheme($this->bundle);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getAccess($op) {
    return field_collection_item_access($op, $this->entity);
  }

  /**
   * {@inheritdoc}
   */
  public function getLanguage() {
    $langcode = $this->entity->langcode() ? $this->entity->langcode() : LANGUAGE_NONE;
    // Use the field language as entity language.
    if ($langcode == LANGUAGE_NONE) {
      // If the current field is untranslatable, try inherit the host entity
      // language.
      if (($host_entity_type = $this->entity->hostEntityType()) && entity_translation_enabled($host_entity_type) && ($host_entity = $this->entity->hostEntity())) {
        $handler = $this->factory->getHandler($host_entity_type, $host_entity);
        $langcode = $handler->getFormLanguage();
      }
      // If the host entity is not translatable, use the default language
      // fallback.
      else {
        $langcode = parent::getLanguage();
      }
    }
    return $langcode;
  }

}
