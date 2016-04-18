<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<div class="row panel-separator">
  <div class="col-sm-10 col-md-8 col-sm-offset-1 col-md-offset-2">
    <div class="divider"></div>
    <h1 class="small"><?php print $view->get_title(); ?></h1>
    <?php foreach ($rows as $id => $row): ?>
      <?php print $row; ?>
    <?php endforeach; ?>
    <?php
      $options = array();
      $options['attributes']['class'] =  'more-news-link';
    ?>
    <div class="more-news-link pull-right"><?php print l(t("More news"), "/news") ?> <i class="fa fa-chevron-right"></i></div>
  </div>
</div>
