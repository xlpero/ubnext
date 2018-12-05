<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="link-list">
	<?php $index = 0; ?>
	  <?php foreach ($rows as $id => $row): ?>
	    	<?php print $row; ?>
	    	<?php $index++; ?>
				<?php if ($index % 2 == 0): ?>
					<div class="clearfix visible-sm-block"></div>
					<div class="clearfix visible-md-block"></div>
					<div class="clearfix visible-lg-block"></div>
				<?php endif; ?>
	  <?php endforeach; ?>
	  <div class="center">
	  	<a id="btn-load-more-shortcuts" class="closed" href="javascript:void(0);"><span class="closed-text"><?php print t('More shortcuts') ?>  <i class="fa fa-plus"></i></span><span class="open-text"><?php print t('Fewer shortcuts') ?>  <i class="fa fa-minus"></i></span></a>
	  </div>
</div>

