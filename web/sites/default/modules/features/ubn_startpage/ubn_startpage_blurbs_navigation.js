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
      var sm_threshold = 0;
      var md_threshold = 3;
      var show_all_text = Drupal.t('Show all');
      var hide_text = Drupal.t('Hide');

      $('.blurb-navigation', context).each(function() {
        $this = $(this);
        var $blurb_container = $this.closest('.blurb-navigation');

        var $extra_items = $('.ubn-panel-links-link-list li:gt(' + (sm_threshold - 1) + ')', $this);

        if ($extra_items.length >= 0) {
          // Set initial state
          //$extra_items.hide();
          $blurb_container.addClass('collapsed');
          $blurb_container.addClass('collapsible');

          //TODO: drupal js-theme function?
          var $show_more_link = $([
              '<div class="blurb-navigation-show-more">',
              '<a href="javascript:void(0);">',
              '<span class="blurb-navigation-show-more-label">',
              show_all_text,
              '</span>',
              ' <span class="blurb-navigation-show-more-count"></span>',
              '</a>',
              ' <i class="fa fa-chevron-down aria-hidden="true">',
              '</div>'
            ].join('')
          );

          $('.ubn-panel-links-link-list', $this).after($show_more_link);

          var $show_more_link_a_label = $show_more_link.find('.blurb-navigation-show-more-label');
          var $show_more_link_i = $show_more_link.find('i');
          $show_more_link.click(function() {
            //TODO: namespaced expanded-class?
            if (!$blurb_container.hasClass('collapsed')) {
              //$extra_items.hide();
              $show_more_link_a_label.text(show_all_text);
              $show_more_link_i.removeClass('fa-chevron-up');
              $show_more_link_i.addClass('fa-chevron-down');
              $blurb_container.addClass('collapsed');
            }
            else {
              $extra_items.fadeIn(200); //or just .hide()?
              $extra_items.show();

              $show_more_link_a_label.text(hide_text);
              $show_more_link_i.removeClass('fa-chevron-down');
              $show_more_link_i.addClass('fa-chevron-up');
              $blurb_container.removeClass('collapsed');
              //$show_more_link.remove();
            }
            $.fn.matchHeight._update(false);
          });
        }
      });

      var sm_mql = window.matchMedia('(max-width: 767px)');
      var set_items_count = function(threshold) {
        $('.blurb-navigation.collapsible', context).each(function() {
          var $this = $(this);
          var items_count = $('li', $this).length;
          var $show_more = $('.blurb-navigation-show-more', $this);
          if(items_count > threshold) {
            var hidden_items = items_count - threshold;
            $('.blurb-navigation-show-more-count', $this).text('(' + items_count + ')');
            $show_more.show();
          }
          else {
            $show_more.hide();
          }
        });
      }

      var sm_mql_handler = function(mql) {
        if(mql.matches) {
          set_items_count(sm_threshold);
        }
        else {
          set_items_count(md_threshold);
        }
      };
      sm_mql.addListener(sm_mql_handler);
      sm_mql_handler(sm_mql);
    }
  }
})(jQuery);
