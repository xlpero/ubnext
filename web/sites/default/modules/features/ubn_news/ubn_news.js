(function($) {
  Drupal.behaviors.ubn_news_equal_heights = {
    attach: function(context, settings) {
      $('.story-promoted', context).matchHeight();
    }
  };
})(jQuery);
