(function($) {
  Drupal.behaviors.ubn_news_equal_heights = {
    attach: function(context, settings) {
      if ($.fn.matchHeight) {
        $('.story-promoted', context).matchHeight();
      }
    }
  };
})(jQuery);
