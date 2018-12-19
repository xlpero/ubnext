(function($) {
  Drupal.behaviors.ubn_startpage_equal_heights = {
    attach: function(context, settings) {
      if ($.fn.matchHeight) {
        $('.blurb', context).matchHeight();
      }
    }
  };
})(jQuery);
