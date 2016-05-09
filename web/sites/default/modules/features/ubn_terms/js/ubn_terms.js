(function($) {
  Drupal.behaviors.ubn_terms = {
    attach: function(context, settings) {
      $("#terms-search-controls-search-box", context).focus();
    }
  };
  Drupal.behaviors.ubn_terms_collapsible = {
    attach : function(context, settings) {
      $collapsibles = $('.term-collapsible', context);
      $collapsibles.on('show.bs.collapse', function() {
        //Showing
        $(this).find('.fa').removeClass('fa-chevron-down').addClass('fa-chevron-up');
      });
      $collapsibles.on('hide.bs.collapse', function() {
        //Hiding
        $(this).find('.fa').removeClass('fa-chevron-up').addClass('fa-chevron-down');
      });


      $termlinks = $('.terms-groups-group-item a, .term-synonym-terms a', context);
      $termlinks.on("click", function(e) {
        var hashTarget = e.currentTarget.hash;
        Drupal.ubnext.scrollTo($(hashTarget));
      });
    }
  };
  Drupal.behaviors.ubn_terms_lunr = {
    attach : function(context, settings) {
      var language = $('html').attr('lang');
      var idx = lunr(function() {
        if(language in lunr) {
          this.use(lunr[language]);
        }
        this.field('title', { boost: 10 });
        this.field('body');
        this.ref('id');
      });
      //TODO: safer class name
      $('.term', context).each(function() {
        $this = $(this);
        var doc = {
          id: $this.attr('id'),
          title: $this.children('.term-name').text(),
          body: $this.children('.term-description').text(),
        };
        idx.add(doc);
      });
      //TODO:
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
      $terms = $('.term', context);
      $term_groups = $('.term-group', context);
      $term_groups_item = $('.terms-groups-group-item', context); 

      $('#terms-search-controls-search-box', context).on('keyup change', function() {
        var query = $(this).val();
        if(query) {
          var results = idx.search(query);
          // Focus out show all

          $term_groups.hide();
          $terms.hide();
          $term_groups_item.hide();

          for(i in results) {
            $('#' + results[i].ref).show().parents('.term-group').show();
            $('#' + results[i].ref).show().parents('.term-group').show();
            console.log($('#' + results[i].ref).show().parents('.term-group'));
          }
        }
        else {
          $term_groups.show();
          $terms.show();

        }
      });

    }
  };
})(jQuery);
