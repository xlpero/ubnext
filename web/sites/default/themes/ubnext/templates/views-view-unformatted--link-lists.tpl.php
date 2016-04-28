<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="row panel-separator link-list">
	<?php $index = 0; ?>
	  <?php foreach ($rows as $id => $row): ?>
	  	<div class="col-sm-6">
	    	<?php print $row; ?>
	    	<?php $index++; ?>
		</div>
		<?php if ($index % 2 == 0): ?>
			<div class="clearfix visible-sm-block"></div>
			<div class="clearfix visible-md-block"></div>
			<div class="clearfix visible-lg-block"></div>
		<?php endif; ?>

	  <?php endforeach; ?>
</div>
