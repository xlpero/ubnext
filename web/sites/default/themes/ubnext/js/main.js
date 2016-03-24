(function ($) {
  Drupal.behaviors.ubnext_fitvids = {
    attach: function(context, settings) {
      $('.ubn-video-player', context).fitVids();
    }
  }
})(jQuery);
