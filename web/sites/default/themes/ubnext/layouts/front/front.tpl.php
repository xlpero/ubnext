<?php if (!empty($content['search'])): ?>
  <div id="search">

    <div id="search-widget" class="panel-separator">
      <div class="search-widget-cover">
          <img src="<?php print path_to_theme();?>/css/img/search-widget-bg.jpg"/>
          <div class="search-widget-cover-content">

            <div class="search-widget-content container">
              <h2 class="slogan h1 no-top-margin">{{ slogan | raw }}</h2>
              <div class="row">
                <div class="col-sm-12 search-widget-content-plate">
                  <div class="row">
                    <div class="col-sm-8">
                      <form action="{{ url }}">
                        <label for="q">{{Label here}}</label>
                        <div class="input-group">
                          <input type="text" name="q" class="form-control input-lg" aria-label="{{ aria_label }}" placeholder="{{ placeholder }}">
                          <span class="input-group-btn">
                          <button class="btn btn-lg btn-primary" type="submit"><i class="fa fa-search"></i></button>
                          </span>
                        </div><!-- /input-group -->
                      </form>
                    </div>
                    <div class="col-sm-4">
                      Linklist here
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
      </div>
    </div>

      <?php //print render($content['search']); ?>
  </div>
<?php endif ?>

<?php if (!empty($content['services'])): ?>
  <div id="services" class="container panel-separator">
    <div class="row">
      <div class="col-xs-12 col-md-10 col-md-offset-1">
        <?php print render($content['services']); ?>
      </div>
    </div>
  </div>
<?php endif ?>

<div class="container">
  <?php if (!empty ($content['navigation'])) : ?>
    <?php print render($content['navigation']); ?>
  <?php endif; ?>
</div>

<div class="divider fullwidth hidden-xs hidden-sm no-margin-top"></div>

<div class="container fullwidth-on-xs">
  <?php if (!empty ($content['promoted_top'])) : ?>
    <?php print render($content['promoted_top']); ?>
  <?php endif; ?>
</div>

<?php if (!empty($content['news'])): ?>
  <div id="news" class="container panel-separator">
    <div class="row">
      <div class="col-xs-12 col-sm-6 col-sm-offset-3">
        <?php print render($content['news']); ?>
      </div>
    </div>
  </div>
<?php endif ?>

<div class="container">
  <?php if (!empty ($content['promoted'])) : ?>
    <?php print render($content['promoted']); ?>
  <?php endif; ?>
</div>

<?php if (!empty($content['main'])): ?>
  <div id="main" class="container panel-separator">
    <div class="row">
      <div class="col-xs-12 col-sm-8 col-sm-offset-2">
        <?php print render($content['main']); ?>
      </div>
    </div>
  </div>
<?php endif ?>
