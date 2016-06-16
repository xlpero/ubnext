<?php if (!empty($content['search'])): ?>
  <div id="search" class="container panel-separator">
    <div class="row">
      <div class="col-xs-12 col-sm-8 col-sm-offset-2">
        <?php print render($content['search']); ?>
      </div>
    </div>
  </div>
<?php endif ?>

<?php if (!empty($content['services'])): ?>
  <div id="services" class="container  panel-separator">
    <div class="row">
      <div class="col-xs-12 col-md-10 col-md-offset-1">
        <?php print render($content['services']); ?>
      </div>
    </div>
  </div>
<?php endif ?>

<div class="container">
  <?php if (!empty ($content['navigation'])) : ?>
    <?php print render($content['navigation']); ?>
  <?php endif; ?>
</div>

<div class="container fullwidth-on-xs">
  <?php if (!empty ($content['promoted_top'])) : ?>
    <?php print render($content['promoted_top']); ?>
  <?php endif; ?>
</div>

<?php if (!empty($content['news'])): ?>
  <div id="news" class="container panel-separator">
    <div class="row">
      <div class="col-xs-12 col-sm-6">
        <?php print render($content['news']); ?>
      </div>
    </div>
  </div>
<?php endif ?>

<div class="container">
  <?php if (!empty ($content['promoted'])) : ?>
    <?php print render($content['promoted']); ?>
  <?php endif; ?>
</div>

<?php if (!empty($content['main'])): ?>
  <div id="main" class="container panel-separator">
    <div class="row">
      <div class="col-xs-12 col-sm-8 col-sm-offset-2">
        <?php print render($content['main']); ?>
      </div>
    </div>
  </div>
<?php endif ?>
