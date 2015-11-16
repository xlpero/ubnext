<?php
/**
 * @file
 * ubn_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ubn_content_types_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_address_information|node|library|form';
  $field_group->group_name = 'group_address_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'library';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Address information',
    'weight' => '8',
    'children' => array(
      0 => 'field_delivery_address',
      1 => 'field_mailing_address',
      2 => 'field_visiting_address',
      3 => 'field_location_override',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Address information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-address-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_address_information|node|library|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_file_attachments|field_collection_item|field_content_sections|form';
  $field_group->group_name = 'group_file_attachments';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_content_sections';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'File attachments',
    'weight' => '5',
    'children' => array(
      0 => 'field_file_atoms',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'File attachments',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-file-attachments field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_file_attachments|field_collection_item|field_content_sections|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_library_resources|node|library|form';
  $field_group->group_name = 'group_library_resources';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'library';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Library resources',
    'weight' => '6',
    'children' => array(
      0 => 'field_adapted_study_rooms_count',
      1 => 'field_book_return_box',
      2 => 'field_cafe',
      3 => 'field_food_heating_facilities',
      4 => 'field_group_study_rooms_count',
      5 => 'field_gu_print',
      6 => 'field_quiet_reading_room',
      7 => 'field_study_seats_count',
      8 => 'field_wlan',
      9 => 'field_special_collections',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Library resources',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-library-resources field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_library_resources|node|library|form'] = $field_group;

  return $export;
}
