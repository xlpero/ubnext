
<?php if (!empty($content['services'])): ?>

<?php endif ?>


<?php if (!empty($content['main'])): ?>
	<div class="container">
		<div class="row">
			<div class="col-xs-12 col-sm-8 col-sm-offset-2">
		  		<?php print render($content['main']); ?>
		  	</div>
		</div>
	</div>
<?php endif ?>

