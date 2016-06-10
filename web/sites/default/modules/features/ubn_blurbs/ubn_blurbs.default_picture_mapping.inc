<?php
/**
 * @file
 * ubn_blurbs.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function ubn_blurbs_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Blurb';
  $picture_mapping->machine_name = 'blurb';
  $picture_mapping->breakpoint_group = 'ubnext';
  $picture_mapping->mapping = array(
    'breakpoints.theme.ubnext.extra_small' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'blurb_extra_small',
      ),
    ),
    'breakpoints.theme.ubnext.small' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'blurb_small',
      ),
    ),
    'breakpoints.theme.ubnext.medium' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.ubnext.large' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['blurb'] = $picture_mapping;

  return $export;
}
