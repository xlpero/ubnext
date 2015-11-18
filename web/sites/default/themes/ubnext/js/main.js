(function ($) {
  Drupal.behaviors.ubnext_fitvids = {
    attach: function(context, settings) {
      console.log('attaching content');
      console.dir($('.ubn-video-player', context));
      $('.ubn-video-player', context).fitVids();
    }
  }
})(jQuery);
