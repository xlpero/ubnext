<div class="container">
	<div class="row">
		<div class="col-xs-12">
			FRONTPAGE
		</div>
	</div>

	<?php if (!empty($content['main'])): ?>
		<div class="row">
			<div class="col-xs-12">
		  		<?php print render($content['main']); ?>
		  	</div>
		</div>
	<?php endif ?>
</div>