(function ($) {

  Drupal.attachBehaviors = function(context, settings) {
    var links = $('.content-sections a');
    links.each(function(){
        var t = $(this).parent().html().indexOf('<a');
        if(t>0){
            $(this).addClass('no-arrow');
        }

    });
  };

  Drupal.behaviors.ubnext_fitvids = {
    attach: function(context, settings) {
      $('.ubn-video-player', context).fitVids();
    }
  };

  Drupal.behaviors.ubnext_equal_heights = {
    attach : function(context, settings) {
      /* TODO: rename ubn-pane */
      $('.ubn-panel-links', context).matchHeight();
    }
  };

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
