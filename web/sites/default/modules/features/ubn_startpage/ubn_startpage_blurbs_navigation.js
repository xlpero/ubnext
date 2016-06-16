(function($) {
  Drupal.behaviors.ubn_startpage_blurbs_navigation_equal_heights = {
    attach: function(context, settings) {
      $('.blurb-navigation', context).matchHeight();
    }
  };
})(jQuery);
