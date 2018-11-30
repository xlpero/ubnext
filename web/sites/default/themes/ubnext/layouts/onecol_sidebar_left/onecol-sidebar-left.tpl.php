<?php //TODO: rename to search page or similar ?>

<div class="container">
  <?php if (!empty ($content['header'])) : ?>
    <div class="row">
      <div class="col-sm-10 col-md-8 col-sm-offset-1 col-md-offset-2">
        <?php print render($content['header']) ?>
      </div>
    </div>
  <?php endif; ?>
</div>

<div class="container rs_preserve rs_skip">
  <?php if (!empty ($content['main_top'])) : ?>
    <div class="rs_preserve">
      <?php print render($content['main_top']) ?>
    </div>
  <?php endif; ?>

  <div class="row rs_preserve rs_skip">
    <?php if (!empty ($content['search_bar_top'])) : ?>
      <div class="searchbar-top col-xs-12 col-sm-10 col-md-8 col-md-offset-2 col-sm-offset-1">
        <?php print render($content['search_bar_top']); ?>
      </div>
    <?php endif; ?>
  </div>
  </div>
  <div class="row ajax-containerrs_preserve  rs_skip">
    <?php if (!empty ($content['sidebar'])) : ?>
    <aside class="sidebar  col-xs-12 col-sm-4">
      <div class="facet-filter rs_preserve">
        <?php print render($content['sidebar']); ?>
      </div>
    </aside>
    <?php endif; ?>

    <?php if (!empty ($content['sidebar'])) : ?>
      <div class="main col-xs-12 col-sm-8 rs_preserve rs_skip">
    <?php else : ?>
      <div class="main col-xs-12 col-sm-8 col-sm-offset-2 center no-sidebar rs_preserve rs_skip">
    <?php endif; ?>
      <div class="main-inner rs_preserve rs_skip">
    	   <?php print render($content['main']); ?>
      </div>
    </div>
  </div>
</div>
