<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
//Preprocess?
$ubn_i18n = isset($view->display_handler->options['pane_conf']['ubn_i18n']) ?
$view->display_handler->options['pane_conf']['ubn_i18n'] : array();
?>

<div class="row panel-separator">
	<div class="col-xs-12 col-sm-8 col-sm-offset-2">
		<h2><?php print $view->get_title(); ?></h2>
		<div class="row">
			<div class="col-sm-12">
				<div class="row">
					<div class="col-sm-offset-7 col-sm-6 hidden-xs library-libraries-opening-hours-header">
						<div class="row">
							<div class="col-xs-12">
								<strong><?php print $ubn_i18n['opening_hours_title'] ? $ubn_i18n['opening_hours_title'] : t('Opening hours'); ?></strong>
							</div>
						</div>
					</div>
				</div>
			</div>
		</div>
		<ul class="list-unstyled ub-list-of-links">
			<?php foreach ($rows as $id => $row): ?>
				<li><?php print $row; ?></li>
			<?php endforeach; ?>
		</ul>
	</div>
</div>
