<div class="container log-in-form ub-panel-separator">
	<div class="row">
		<div class="col-sm-6">
			<h2><?php print variable_get('site_name'); ?></h2>
			<p><?php print t('Enter your email to get a new password.') ?></p>
		</div>
		<div class="col-sm-6">
			<?php print render($form['name']); ?>
			<?php print render($form[actions][submit]); ?>

			<div class="ubnext-user-login-form-wrapper">
			  <?php print drupal_render_children($form) ?>
			</div>
		</div>
	</div>
</div>