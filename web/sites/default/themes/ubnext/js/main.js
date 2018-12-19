(function ($) {

  Drupal.behaviors.ubnext_shortcuts = {
    attach : function(context, settings) {
      var items = $('.latest-stories-widget-link-list li');
      if (items.length > 3) {
        $('.latest-stories-widget-link-list li:nth-child(n+5)').hide();
      }
      if (items.length < 5) {
        $("#btn-load-more-shortcuts").hide();
      }
      $('#btn-load-more-shortcuts').bind('click', function() {
        $('.latest-stories-widget-link-list li:nth-child(n+5)').slideToggle(50);
        if ($('#btn-load-more-shortcuts').hasClass("closed")) {
          $('#btn-load-more-shortcuts').removeClass("closed");
        }
        else {
          $('#btn-load-more-shortcuts').addClass("closed");
        }
      });

      $('.latest-stories-widget-link-list li').bind('click', function() {
        let url = $(this).find('a').attr("href");
        window.location.href = url;
      });


    }
  };

  Drupal.behaviors.ubnext_fitvids = {
    attach: function(context, settings) {
      $('.ubn-video-player', context).fitVids();
    }
  };

  Drupal.behaviors.ubnext_equal_heights = {
    attach : function(context, settings) {
      /* TODO: rename ubn-pane */
      if ($.fn.matchHeight) {
        $('.ubn-panel-links', context).matchHeight();
      }
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
