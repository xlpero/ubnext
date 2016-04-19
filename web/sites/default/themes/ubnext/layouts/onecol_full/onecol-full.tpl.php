<div class="main">
  <div class="container">
    <?php if (!empty ($content['header'])) : ?>
      <div class="row">
        <div class="col-sm-10 col-md-8 col-sm-offset-1 col-md-offset-2">
          <?php print render($content['header']); ?>
        </div>
      </div>
    <?php endif; ?>
  </div>

  <div class="container fullwidth-on-xs">
    <?php if (!empty ($content['promoted_top'])) : ?>
      <?php print render($content['promoted_top']); ?>
    <?php endif; ?>
  </div>

  <div class="container">
    <?php if (!empty ($content['main_top'])) : ?>
      <?php print render($content['main_top']); ?>
    <?php endif; ?>
  </div>

  <div class="container fullwidth-on-xs">
    <?php if (!empty ($content['promoted'])) : ?>
      <?php print render($content['promoted']); ?>
    <?php endif; ?>
  </div>

  <div class="container">
    <?php if (!empty ($content['main'])) : ?>
      <?php print render($content['main']); ?>
    <?php endif; ?>
  </div>
</div>
