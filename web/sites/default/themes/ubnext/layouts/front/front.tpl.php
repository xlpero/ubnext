<?php if (!empty($content['search'])): ?>
	<section id="search" class="container panel-separator">
		<div class="row">
			<div class="col-xs-12 col-sm-8 col-sm-offset-2">
		  		<?php print render($content['search']); ?>
		  	</div>
		</div>
	</section>
<?php endif ?>

<?php if (!empty($content['services'])): ?>
	<section id="services" class="container  panel-separator">
		<div class="row">
			<div class="col-xs-12 col-md-10 col-md-offset-1">
				<?php print render($content['services']); ?>
			</div>
		</div>
	</section>
<?php endif ?>

<?php if (!empty($content['news'])): ?>
	<section id="news" class="container panel-separator">
		<div class="row">
			<div class="col-xs-12 col-sm-6">
				<?php print render($content['news']); ?>
			</div>
		</div>
	</section>
<?php endif ?>

<?php if (!empty($content['main'])): ?>
	<section id="main" class="container panel-separator">
		<div class="row">
			<div class="col-xs-12 col-sm-8 col-sm-offset-2">
		  		<?php print render($content['main']); ?>
		  	</div>
		</div>
	</section>
<?php endif ?>

