<?php if (!empty($content['topbar'])): ?>
  <div class="topbar clearfix">
    <?php print render($content['topbar']); ?>
  </div>
<?php endif; ?>

<?php if (!empty($content['header'])): ?>
  <header id="header">
    <div class="wrap">
      <?php print render($content['header']); ?>
    </div>
    <?php print render($content['navigation']); ?>
  </header>
<?php endif; ?>

<?php if (!empty($content['content'])): ?>
  <section id="main">
    <div class="wrap">
      <?php print render($content['content']); ?>
    </div>
  </section>
<?php endif; ?>

<?php if (!empty($content['footer'])): ?>
  <footer id="footer">
    <div class="wrap">
      <?php print render($content['footer']); ?>
    </div>
  </footer>
<?php endif; ?>
