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

<div class="mega-menu">
  <ul>

    <li>
      <a href="#">Tjänster</a>
      <ul>
        <li><a href="#">link testar </a></li>
        <li><a href="#">Boka grupprum</a></li>
        <li><a href="#">Boka annat</a></li>
        <li><a href="#">Fråga bibliotikare</a></li>
        <li><a href="#">Digitalisera</a></li>
      </ul>
    </li>
    <li>
      <a href="#">Skriva</a>
      <ul>
        <li><a href="#">link 1</a></li>
        <li><a href="#">link 1</a></li>
        <li><a href="#">link 1</a></li>
        <li><a href="#">link 1</a></li>
        <li><a href="#">link 1</a></li>
      </ul>
    </li>
  </ul>
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
<div id="footer-wrapper" class="full-width-wrapper padding-20">
  <footer id="footer">  
    <div class="row">
      <div class="col-1">
        <h3>Alla guider</h3>
        <ul>
          <li><a href="#">Guide 1</a></li>
          <li><a href="#">Guide 1</a></li>
          <li><a href="#">Guide 1</a></li>
          <li><a href="#">Guide 1</a></li>
          <li><a href="#">Guide 1</a></li>
        </ul>
      </div>
      <div class="col-2">
        <h3>Allt annat</h3>
        <ul>
          <li><a href="#">Annat 123 </a></li>
          <li><a href="#">Annat 123 </a></li>
          <li><a href="#">Annat 123 </a></li>
          <li><a href="#">Annat 123 </a></li>
          <li><a href="#">Annat 123 </a></li>
        </ul>Annat 123 
      </div>
      <div class="col-3">
        <h3>Alla andra bibliotek</h3>
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
<div class="full-width-wrapper site-bottom-wrapper padding-20">
  <div class="site-bottom"> 

    <div class="logotype">  
      <div class="logo"><div class="logo-image"></div></div>
    </div>
    <div class="copyright">
      &copy; <?php print variable_get('site_name'); ?>  <?php echo date("Y"); ?>
    </div>
  </div>
</div>
<!-- ### END SITE BOTTOM ### --> 


