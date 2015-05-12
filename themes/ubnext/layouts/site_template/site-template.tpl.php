<?php if (!empty($content['topbar'])): ?>
  <div class="topbar clearfix">
    <?php print render($content['topbar']); ?>
  </div>
<?php endif; ?>

<!-- ### HEADER ### -->
<div class="header-cms">
  <header id="header" class="container">  
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
</div>

<!-- ### END HEADER ### -->



<!-- ### MAIN NAVIGATION ### --> 
<div class="main-nav-cms">
    <div class="main-navigation-area">
      <div class="main-navigation-wrap container">
        <div class="secondary">
          <a id="menu-toggler-btn" href="javascript:void(0);"><span>Meny</span><i class="fa fa-bars"></i></a>
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
    <div class="mega-menu-area">
      <div class="mega-menu container">
        <ul class="list-unstyled row">
          <li class="col-xs-12 col-sm-4">
            <a href="#">Tjänster</a>
            <ul class="list-unstyled">
              <li><a href="#">link testar </a></li>
              <li><a href="#">Boka grupprum</a></li>
              <li><a href="#">Boka annat</a></li>
              <li><a href="#">Fråga bibliotikare</a></li>
              <li><a href="#">Digitalisera</a></li>
            </ul>
          </li>
          <li class="col-xs-12 col-sm-4">
            <a href="#">Skriva</a>
            <ul class="list-unstyled">
              <li><a href="#">link 1</a></li>
              <li><a href="#">link 1</a></li>
              <li><a href="#">link 1</a></li>
              <li><a href="#">link 1</a></li>
              <li><a href="#">link 1</a></li>
            </ul>
          </li>
        </ul>
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
  <section class="main-cms">
    <div class="wrap">
      <?php print render($content['content']); ?>
    </div>
  </section>
<?php endif; ?>



<div class="footer-cms">
  <!-- ### FOOTER ### -->
  <div class="footer-area">
    <footer id="footer" class="container">  
      <div class="row">
        <div class="col-xs-12 col-sm-4">
          <h3>Alla guider</h3>
          <ul class="list-unstyled">
            <li><a href="#">Guide 1</a></li>
            <li><a href="#">Guide 1</a></li>
            <li><a href="#">Guide 1</a></li>
            <li><a href="#">Guide 1</a></li>
            <li><a href="#">Guide 1</a></li>
          </ul>
        </div>
        <div class="col-xs-12 col-sm-4">
          <h3>Allt annat</h3>
          <ul class="list-unstyled">
            <li><a href="#">Annat 123 </a></li>
            <li><a href="#">Annat 123 </a></li>
            <li><a href="#">Annat 123 </a></li>
            <li><a href="#">Annat 123 </a></li>
            <li><a href="#">Annat 123 </a></li>
          </ul>Annat 123 
        </div>
        <div class="col-xs-12 col-sm-4">
          <h3>Alla andra bibliotek</h3>
          <ul class="list-unstyled">
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
  <div class="site-bottom-area">
    <div class="site-bottom container"> 

      <div class="logotype">  
        <div class="logo"><div class="logo-image"></div></div>
      </div>
      <div class="copyright">
        &copy; <?php print variable_get('site_name'); ?>  <?php echo date("Y"); ?>
      </div>
    </div>
  </div>
  <!-- ### END SITE BOTTOM ### --> 
</div> <!-- ### END FOOTER-CMS -->


