<?php global $language; ?>



<?php if (!empty($content['topbar'])): ?>
  <div class="topbar clearfix">
    <?php print render($content['topbar']); ?>
  </div>
<?php endif; ?>

<!-- ### HEADER ### -->
<header>      
  <div class="container">
    <div class="row">
      <div class="col-sm-8">  
        <div class="siteNav-logo <?php echo $language->language; ?>">
          <div class="logo">
            <a href="<?php echo $GLOBALS['base_url']; ?>"><div class="logo-image"></div></a>  
          </div>
        </div>
        <div class="site-headers">
          <div class="site-title">
            <a href="<?php echo $GLOBALS['base_url']; ?>"><?php print variable_get('site_name'); ?></a>
          </div>
        </div>
      </div>
      <div class="col-sm-4">
        <nav class="toplinks">
          <?php print render($content['toplinks']); ?>
        </nav>
      </div>
    </div>
  </div>
</header>

<!-- ### END HEADER ### -->


<!-- ### MAIN NAVIGATION ### --> 
<div class="main-nav-cms">
  <div class="container">
    <div class="row">
      <div class="col-xs-12">
        <nav class="nav-primary">
          <!-- PRIMARY NAV -->
            <?php print render($content['navigation']); ?>
          <!-- END PRIMARY NAV --> 
        </nav>
      </div>
    </div>
  </div>
</div>
<!-- ### END NAVIGATION ### -->

<?php if (!empty($content['tabs'])): ?>
  <div class="container">
    <div class="row">
      <div class="col-xs-12">
        <?php print render($content['tabs']); ?>
      </div>
    </div>
  </div>
<?php endif; ?>

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
        <div class="col-xs-12">

        </div>
      </div>
    </footer>
  </div> 
  <!-- ### END FOOTER ### -->

  <!-- ### SITE BOTTOM ### --> 
  <div class="site-bottom-area">
    <div class="site-bottom container"> 
      <div class="copyright">
        &copy; <?php print variable_get('site_name'); ?>  <?php echo date("Y"); ?>
      </div>
    </div>
  </div>
  <!-- ### END SITE BOTTOM ### --> 
</div> <!-- ### END FOOTER-CMS -->


