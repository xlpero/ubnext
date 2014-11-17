<?php if (!empty($content['topbar'])): ?>
  <div class="topbar clearfix">
    <?php print render($content['topbar']); ?>
  </div>
<?php endif; ?>





<?php if (!empty($content['header'])): ?>
  <header id="header">  
    <div class="header-inner-wrapper">
      <div class="header-block">
        <div class="left">
          <div class="siteNav-logo">
            <div class="logo">
              <div class="logo-image"></div>
            </div>
          </div>
          <div class="site-headers">
            <div class="site-title">
              <a href="#">Göteborgs Universitetsbibliotek</a>
            </div>
            <div class="site-title-tagline">
            </div>
          </div>
        </div>
        <div class="right">
          <nav>
            <ul>
              <li><a href="#">In english</a></li>
              <li><a href="#">Sök</a></li>
            </ul>
          </nav>
        </div>
      </div>
    </div>  <!-- end header-inner-wrapper --> 
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
