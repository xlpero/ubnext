<div class="main">
  <div class="container">
    <div class="row ub-panel-separator">

    <?php if (!empty ($content['header'])) : ?>
      <?php print render($content['header']); ?>
    <?php endif; ?>

    <?php if (!empty ($content['main'])) : ?>
      <?php print render($content['main']); ?>
    <?php endif; ?>

  </div>
</div>
