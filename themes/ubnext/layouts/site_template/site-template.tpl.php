<?php if (!empty($content['topbar'])): ?>
  <div class="topbar clearfix">
    <?php print render($content['topbar']); ?>
  </div>
<?php endif; ?>


<!-- ### HEADER ### -->
<header id="header">  
      <div class="left">
        <div class="siteNav-logo">
          <div class="logo">
            <a href="/"><div class="logo-image"></div></a>  
          </div>
        </div>
        <div class="site-headers">
          <div class="site-title">
            <a href="#"><?php print variable_get('site_name'); ?></a>
          </div>
          <div class="site-title-tagline">
              <?php print variable_get('site_slogan'); ?>
          </div>
        </div>
      </div>
      <div class="right">
        <nav>
          <?php print render($content['toplinks']); ?>
        </nav>
      </div>
  </header>

<!-- ### END HEADER ### -->



<!-- ### MAIN NAVIGATION ### --> 
<div class="full-width-wrapper">
  <div class="main-navigation-wrapper">
    <div class="main-navigation-inner-wrapper">
      <div class="secondary">
        <a id="menu-toggler-btn" href="javascript:void(0);"><span>Meny</span><i class="fa fa-bars"></i></a>
        <!-- SECONDARY NAV -->
        <nav class="secondary-navigation">
          <ul role="menu" class="secondary-navigation-nav">
            <li><a href="#">Våra bibliotek</a></li>
            <li><a href="#">Kansliet</a></li>
            <li><a href="#">Kvinnsam</a></li>
          </ul>
        </nav>
        <!-- END SECONDARY NAV --> 
      </div>
      <div class="primary">
        <!-- PRIMARY NAV -->
        <nav class="main-navigation">
          <?php print render($content['navigation']); ?>
        </nav>
        <!-- END PRIMARY NAV --> 
      </div>

      

    </div>
  </div>
</div>
<!-- ### END NAVIGATION ### -->

<?php if (!empty($content['pagetitle'])): ?>
  <section class="page-head">
    <?php print render($content['pagetitle']); ?>
  </section>
<?php endif; ?>

<?php if (!empty($content['content'])): ?>
  <section class="main">
    <div class="wrap">
      <?php print render($content['content']); ?>
    </div>
  </section>
<?php endif; ?>




<!-- ### FOOTER ### -->
<div id="footer-wrapper" class="full-width-wrapper">
  <footer id="footer">  
    <div class="row">
      <div class="links-to-guides">
        <h3>Alla guider</h3>
        <ul>
          <li><a href="#">Guide 1</a></li>
          <li><a href="#">Guide 1</a></li>
          <li><a href="#">Guide 1</a></li>
          <li><a href="#">Guide 1</a></li>
          <li><a href="#">Guide 1</a></li>
        </ul>
      </div>
      <div class="links-to-libraries">
        <h3>Alla bibliotek</h3>
        <ul>
          <li><a href="#">Bibliotek sammhällsvetenskapliga</a></li>
          <li><a href="#">Bibliotek</a></li>
          <li><a href="#">Bibliotek</a></li>
          <li><a href="#">Bibliotek</a></li>
          <li><a href="#">Bibliotek</a></li>
        </ul>
      </div>
    </div>
  </footer>
</div>
<!-- ### END FOOTER ### -->

<!-- ### SITE BOTTOM ### --> 
<div class="full-width-wrapper site-bottom-wrapper">
  <div class="site-bottom"> 
    <div class="left">
      <div class="logo"><div class="logo-image"></div></div>
    </div>
    <div class="right">
      &copy; <?php print variable_get('site_name'); ?>  
    </div>
  </div>
</div>
<!-- ### END SITE BOTTOM ### --> 


