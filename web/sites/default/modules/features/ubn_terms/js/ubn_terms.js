(function($) {
  Drupal.behaviors.ubn_terms_collapsible = {
    attach : function(context, settings) {
      $collapsibles = $('.term-collapsible', context);
      $collapsibles.on('show.bs.collapse', function() {
        //Showing
        $(this).find('.fa.fa-dynamic').removeClass('fa-chevron-down').addClass('fa-chevron-up');
      });
      $collapsibles.on('hide.bs.collapse', function() {
        //Hiding
        $(this).find('.fa.fa-dynamic').removeClass('fa-chevron-up').addClass('fa-chevron-down');
      });

    }
  };
  Drupal.behaviors.ubn_terms_lunr = {
    attach : function(context, settings) {
      /*
       * Lunr initialization
       */
      var language = $('html').attr('lang');
      var idx = lunr(function() {
        if(language in lunr) {
          this.use(lunr[language]);
        }
        this.field('title', { boost: 10 });
        //this.field('body');
        this.ref('id');
      });
      //TODO: safer class name
      $('.term', context).each(function() {
        $this = $(this);
        var doc = {
          id: $this.attr('id'),
          title: $this.children('.term-name').text()/*,
          body: $this.children('.term-description').text()*/
        };
        idx.add(doc);
      });

      //TODO:
      /*
         var debounce = function (fn) {
         var timeout;
         return function () {
         var args = Array.prototype.slice.call(arguments),
         ctx = this;
         clearTimeout(timeout);
         timeout = setTimeout(function () {
         fn.apply(ctx, args);
         }, 100);
         };
         }
      */

      /*
       * Search behaviour
       */
      var $search = $('#terms-search-controls-search-box', context);
      $search.focus();

      // Clear search button
      var $clear_btn = $('.clear-search-btn', context);

      var toggle_clear_filters = function(show) {
        if (show) {
          $clear_btn.fadeIn(200);
        }
        else {
          $clear_btn.fadeOut(200);
        }
      };

      $clear_btn.on('click', function() {
        $search.val(''); // does not trigger change..
        toggle_clear_filters(false);
        $search.focus();
        $search.trigger('change');
      });

      var $terms = $('.term', context);
      var $term_groups = $('.term-group', context);
      var $letter_nav_items = $('.letter-nav .terms-groups-group-item', context);
      var $terms_search_results = $('#terms-search-results', context);

      // Free text search
      $('#terms-search-controls-search-box', context).on('keyup change', function() {
        var query = $(this).val();

        if(query) {
          var results = idx.search(query);
          // Focus out show all
          $term_groups.hide();
          $terms.hide();
          toggle_clear_filters(true);

          // Disable all links in menu
          $letter_nav_items.addClass('disabled');

          // Enable does link that are valid
          if (results.length) {
            $terms_search_results.removeClass('no-result');
          }
          else {
            $terms_search_results.addClass('no-result');
          }
          var terms_group_ids = {};
          for(i in results) {
            $('#' + results[i].ref).show().parents('.term-group').show();
            var group_id = $('#' + results[i].ref).data('term-group-id');
            terms_group_ids[group_id] = group_id;
          }
          for(group_id in terms_group_ids) {
            $letter_nav_items.filter('.terms-groups-group-' + group_id).removeClass('disabled');
          }
        }
        else {
          $term_groups.show();
          $terms.show();
          toggle_clear_filters(false);
          $letter_nav_items.removeClass('disabled');
          $terms_search_results.removeClass('no-result');
        }
      });

      // Clear search on term/term-group click
      $term_links = $('.terms-groups-group-item a, .term-synonym-terms a', context);
      $term_links.on('click', function(e) {
        $clear_btn.trigger('click');
        var hash_target = decodeURIComponent(e.currentTarget.hash);
        Drupal.ubnext.scrollTo($(hash_target, context), function() {
          // this is where to open the term
          $(hash_target, context).find('.term-name').trigger('click');
        });
      });
    }
  };
})(jQuery);
