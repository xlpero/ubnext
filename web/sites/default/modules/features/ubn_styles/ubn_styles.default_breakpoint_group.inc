<?php
/**
 * @file
 * ubn_styles.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function ubn_styles_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'library_hero';
  $breakpoint_group->name = 'Library hero';
  $breakpoint_group->breakpoints = array(
    0 => 'breakpoints.theme.ubnext.small',
    1 => 'breakpoints.theme.ubnext.extra_small',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['library_hero'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'page_content';
  $breakpoint_group->name = 'Page content';
  $breakpoint_group->breakpoints = array(
    0 => 'breakpoints.theme.ubnext.small',
    1 => 'breakpoints.theme.ubnext.extra_small',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['page_content'] = $breakpoint_group;

  return $export;
}
