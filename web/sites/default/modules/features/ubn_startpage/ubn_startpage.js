(function($) {
  Drupal.behaviors.ubn_startpage_equal_heights = {
    attach: function(context, settings) {
      $('.blurb', context).matchHeight();
    }
  };
})(jQuery);
