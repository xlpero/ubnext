
<div class="two-col-right">
  <div class="two-col-right-inner-wrapper">
    <?php if (!empty($content['sidebar'])): ?>
      <section id="sidebar">
        <div class="wrap">
          <?php print render($content['sidebar']); ?>
        </div>
      </section>
    <?php endif; ?>
    <?php if (!empty($content['main'])): ?>
      <section id="main">
        <div class="wrap">
          <?php print render($content['main']); ?>
        </div>
      </section>
    <?php endif; ?>
    <?php if (!empty($content['sidebar-bottom'])): ?>
      <section id="sidebar-mobile-only">
        <div class="wrap">
          <?php print render($content['sidebar-bottom']); ?>
        </div>
      </section>
    <?php endif; ?>

  </div>
</div>