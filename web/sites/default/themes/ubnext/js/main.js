(function ($) {
  Drupal.behaviors.ubnext_fitvids = {
    attach: function(context, settings) {
      $('.ubn-video', context).fitVids();
    }
  }
}
})(jQuery);
