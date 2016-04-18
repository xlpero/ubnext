<div class="main">
  <div class="container">
  <?php if (!empty ($content['header'])) : ?>
    <div class="row">
      <div class="col-sm-10 col-md-8 col-sm-offset-1 col-md-offset-2">
        <?php print render($content['header']); ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty ($content['main'])) : ?>
    <?php print render($content['main']); ?>
  <?php endif; ?>
</div>
