<?php
/*
  if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  }
    print $row . ' hej';
*/

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php print $gmap_container; ?>
