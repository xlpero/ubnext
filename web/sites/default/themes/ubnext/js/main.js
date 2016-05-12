(function ($) {
  Drupal.behaviors.ubnext_fitvids = {
    attach: function(context, settings) {
      $('.ubn-video-player', context).fitVids();
    }
  }
  Drupal.ubnext = {
    scrollTo : function($element, callback) {
      if($element.length) {
        $admin_menu = $('#admin-menu-wrapper');
        var offset = $admin_menu.length ? $admin_menu.outerHeight() : 0;
        $('html, body').animate({
          scrollTop: $element.offset().top - offset
        }, 200, "swing", callback);
      }
    }
  };
})(jQuery);
