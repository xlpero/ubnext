<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<div class="row">
  <div class="col-sm-offset-8 col-sm-4 hidden-xs library-libraries-opening-hours-header"><strong><?php print t('Opening hours'); ?></strong></div>
</div>
<ul class="row list-unstyled ub-list-of-links">
	<?php foreach ($rows as $id => $row): ?>
	  <li class="col-sm-8 col-sm-offset-2"><?php print $row; ?></li>
	<?php endforeach; ?>
</ul>

