<div class="container">
  <div class="row ub-panel-separator">
    <div class="col-sm-10 col-md-8 col-sm-offset-1 col-md-offset-2"">
      <?php print render($content['header']) ?>
    </div>
  </div>
  <?php if (!empty ($content['alertarea'])) : ?>
  <div class="row ub-panel-separator">
    <div class="col-sm-12 col-md-12">
      <?php print render($content['alertarea']) ?>
    </div>
  </div>
  <?php endif; ?>

  <?php if (!empty ($content['shortcuts'])) : ?>
  <div class="shortcuts-top row">
    <div class="col-xs-12">
      <?php print render($content['shortcuts']) ?>
    </div>
  </div>
  <?php endif; ?>

  <div class="row">
    <div class="searchbar-top col-xs-12 col-sm-8 col-sm-offset-2">
      <?php print render($content['searchbartop']); ?>
    </div>
  </div>
  </div>
  <div class="row ajax-container">
    <?php if (!empty ($content['sidebar'])) : ?>
    <aside class="sidebar col-xs-12 col-sm-4">
      <div class="facet-filter">
        <?php print render($content['sidebar']); ?>
      </div>
    </aside>
    <?php endif; ?>

    <?php if (!empty ($content['sidebar'])) : ?>
      <section class="main col-xs-12 col-sm-8">
    <?php else : ?>
      <section class="main col-xs-12 col-sm-8 col-sm-offset-2 center no-sidebar">
    <?php endif; ?>
      <div class="main-inner">
    	   <?php print render($content['main']); ?>
      </div>
    </section>
  </div>
</div>
