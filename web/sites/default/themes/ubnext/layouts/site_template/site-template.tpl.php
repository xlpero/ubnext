<?php global $language; ?>

<?php if (!empty($content['topbar'])): ?>
  <div class="topbar clearfix">
    <?php print render($content['topbar']); ?>
  </div>
<?php endif; ?>

<!-- ### HEADER ### -->
<div class="header-cms">
  <header>
    <div class="container">
      <div class="row">
        <div class="col-sm-10 col-xs-12">
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
        <div class="col-sm-2">
          <nav class="toplinks">
            <?php print render($content['toplinks']); ?>
          </nav>
        </div>
      </div>
    </div>
  </header>
  </div>

<!-- ### END HEADER ### -->

<!-- ### MAIN NAVIGATION ### -->
<div class="nav-cms primary-nav-cms">
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

<div class="nav-cms primary-nav-cms-dropdown">
    <nav class="nav-primary-dropdown">
      <!-- PRIMARY NAV -->
      <?php print render($content['dropdown_navigation']); ?>
      <!-- END PRIMARY NAV -->
    </nav>
</div>




<?php if(!empty($content['breadcrumb'])): ?>
<div class="nav-cms breadcrumb-nav-cms">
 <div class="container">
    <div class="row">
      <div class="col-xs-12">
        <nav class="nav-breadcrumb">
          <!-- SECONDARY NAV -->
          <?php print render($content['breadcrumb']); ?>
          <!-- END SECONDARY NAV -->
        </nav>
      </div>
    </div>
  </div>
</div>
<?php endif; ?>


<?php if(!empty($content['navigation_secondary'])): ?>
<div class="nav-cms secondary-nav-cms">
 <div class="container">
    <div class="row">
      <div class="col-xs-12">
        <nav class="nav-secondary">
          <!-- SECONDARY NAV -->
          <?php print render($content['navigation_secondary']); ?>
          <!-- END SECONDARY NAV -->
        </nav>
      </div>
    </div>
  </div>
</div>
<?php endif; ?>
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

<?php if (!empty($content['messages'])): ?>
  <div class="container">
    <div class="message-box-cms" class="row">
      <div class="col-xs-12">
        <div class="alert alert-info" role="alert">
          <?php print render($content['messages']); ?>
        </div>
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



<!-- Google Tag Manager -->
<noscript><iframe src="//www.googletagmanager.com/ns.html?id=GTM-NR65TR"
height="0" width="0" style="display:none;visibility:hidden"></iframe></noscript>
<script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':
new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
'//www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
})(window,document,'script','dataLayer','GTM-NR65TR');</script>
<!-- End Google Tag Manager -->
