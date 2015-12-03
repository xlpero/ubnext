<?php
/**
 * @file
 * ubn_content_types.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function ubn_content_types_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Library hero';
  $picture_mapping->machine_name = 'library_hero';
  $picture_mapping->breakpoint_group = 'library_hero';
  $picture_mapping->mapping = array(
    'breakpoints.theme.ubnext.small' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'library_hero',
      ),
    ),
    'breakpoints.theme.ubnext.extra_small' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'library_hero_extra_small',
      ),
    ),
  );
  $export['library_hero'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Page content';
  $picture_mapping->machine_name = 'page_content';
  $picture_mapping->breakpoint_group = 'page_content';
  $picture_mapping->mapping = array(
    'breakpoints.theme.ubnext.small' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'page_content',
      ),
    ),
    'breakpoints.theme.ubnext.extra_small' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'page_content_extra_small',
      ),
    ),
  );
  $export['page_content'] = $picture_mapping;

  return $export;
}
