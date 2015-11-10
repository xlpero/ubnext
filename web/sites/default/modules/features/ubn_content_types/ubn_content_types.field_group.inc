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
    'weight' => '7',
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
      0 => 'field_study_seats_count',
      1 => 'field_group_study_rooms_count',
      2 => 'field_adapted_study_rooms_count',
      3 => 'field_gu_print',
      4 => 'field_quiet_reading_room',
      5 => 'field_wlan',
      6 => 'field_food_heating_facilities',
      7 => 'field_cafe',
      8 => 'field_book_return_box',
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
