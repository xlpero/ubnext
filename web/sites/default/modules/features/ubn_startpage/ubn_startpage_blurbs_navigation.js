(function($) {
  // Not needed since general pane behaviour takes care of this
  /*
  Drupal.behaviors.ubn_startpage_blurbs_navigation_equal_heights = {
    attach: function(context, settings) {
      $('.blurb-navigation', context).matchHeight();
    }
  };
  */
  Drupal.behaviors.ubn_startpage_blurbs_navigation_show_more = {
    attach: function(context, settings) {
      var max_items = 5;
      var show_all_text = Drupal.t('Show more');
      var hide_text = Drupal.t('Hide');
      $('.blurb-navigation', context).each(function() {
        $this = $(this);
        var $blurb_container = $this.closest('.blurb-navigation');

        var $extra_items = $('.ubn-panel-links-link-list li:gt(' + (max_items - 1) + ')', $this);

        if ($extra_items.length) {
          // Set initial state
          //$extra_items.hide();
          $blurb_container.addClass('collapsed');

          //TODO: drupal js-theme function?
          var $show_more_link = $('<div class="blurb-navigation-show-more"><a href="javascript:void(0);">' + show_all_text + '</a> <i class="fa fa-chevron-down aria-hidden="true"></div>');

          $('.ubn-panel-links-link-list', $this).after($show_more_link);

          var $show_more_link_a = $show_more_link.find('a');
          var $show_more_link_i = $show_more_link.find('i');
          $show_more_link.click(function() {
            //TODO: namespaced expanded-class?
            if (!$blurb_container.hasClass('collapsed')) {
              //$extra_items.hide();
              $show_more_link_a.text(show_all_text);
              $show_more_link_i.removeClass('fa-chevron-up');
              $show_more_link_i.addClass('fa-chevron-down');
              $blurb_container.addClass('collapsed');
            }
            else {
              //$extra_items.fadeIn(200); //or just .hide()?
              //$extra_items.show();
              $show_more_link_a.text(hide_text);
              $show_more_link_i.removeClass('fa-chevron-down');
              $show_more_link_i.addClass('fa-chevron-up');
              $blurb_container.removeClass('collapsed');
            }
            $.fn.matchHeight._update(false);
          });
        }
      });
    }
  }
})(jQuery);
