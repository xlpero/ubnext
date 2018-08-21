<?php
/**
 * @file
 * ubn_alert.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ubn_alert_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_scheduler_alert_and_info_message';
  $strongarm->value = array();
  $export['workbench_scheduler_alert_and_info_message'] = $strongarm;

  return $export;
}
