<?php
/**
 * @file
 * ubn_content_types.features.workbench_scheduler.inc
 */

/**
 * Implements hook_workbench_scheduler_export_schedules().
 */
function ubn_content_types_workbench_scheduler_export_schedules() {
  $items = array(
    'draft_published' => array(
      'name' => 'draft_published',
      'label' => 'Publish draft',
      'start_state' => 'draft',
      'end_state' => 'published',
      'types' => array(
        0 => 'blurb',
        1 => 'page',
        2 => 'story',
      ),
    ),
  );
  return $items;
}
