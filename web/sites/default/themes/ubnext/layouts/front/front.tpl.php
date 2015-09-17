<div class="container">
	<?php if (!empty($content['main'])): ?>
		<div class="row">
			<div class="col-xs-12 col-sm-8 col-sm-offset-2">
		  		<?php print render($content['main']); ?>
		  	</div>
		</div>
	<?php endif ?>
</div>