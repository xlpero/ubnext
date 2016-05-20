(function($) {
  Drupal.behaviors.ubn_terms = {
    attach: function(context, settings) {
      $("#terms-search-controls-search-box", context).focus();
      $('.clear-search-btn', context).on("click", function() {
          $("#terms-search-controls-search-box").val("");// does not trigger change..
          toggleClearFilters(context, false);
          $("#terms-search-controls-search-box", context).focus();
          $("#terms-search-controls-search-box").trigger("change");
      })
      var toggleClearFilters = function(context, show) {
        if (show === true) {
          $(".clear-search-btn", context).fadeIn(200);
        }
        else {
          $(".clear-search-btn", context).fadeOut(200);
        }
      };

      $("#terms-search-controls-search-box", context).on("change paste keyup", function() {
          if ($(this).val().length > 0) {
            toggleClearFilters(context, true);
          }
          else {
            toggleClearFilters(context, false);
          }
      });
    }
  };
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


      $termlinks = $('.terms-groups-group-item a, .term-synonym-terms a', context);
      $termlinks.on("click", function(e) {
        var hashTarget = decodeURIComponent(e.currentTarget.hash);
        Drupal.ubnext.scrollTo($(hashTarget, function() {
          // this is where to open the term
          $("a[href='" + hashTarget + "-description']").trigger("click");
        }));
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
        //this.field('body');
        this.ref('id');
      });
      //TODO: safer class name
      $('.term', context).each(function() {
        $this = $(this);
        var doc = {
          id: $this.attr('id'),
          title: $this.children('.term-name').text(),
//          body: $this.children('.term-description').text(),
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

      $('#terms-search-controls-search-box', context).on('keyup change', function() {
        var query = $(this).val();
        if(query) {
          var results = idx.search(query);
          // Focus out show all
          $term_groups.hide();
          $terms.hide();

          // 1 disable all links in menu
          $letterNavItems = $(".letter-nav .terms-groups-group-item", context);
          $letterNavItems.addClass("disabled");

          // 2 enable does link that are valid 
          if (results.length == 0) {
            $("#terms-search-results", context).addClass("no-result");
          }
          else {
            $("#terms-search-results", context).removeClass("no-result"); 
          }

          for(i in results) {
           // var dataGroupStr = "[data-term-group-id='" + results[i].ref + "]'";
           // $(dataGroupStr).removeClass("disabled");
            $('#' + results[i].ref).show().parents('.term-group').show();
            $('#' + results[i].ref).show().parents('.term-group').show();
            var groupId = $('#' + results[i].ref).data('term-group-id');
            $letterNavItems.each(function(index) {
              if ($(this).hasClass("terms-groups-group-" + groupId)) {
                $(this).removeClass("disabled");
              }
            });
          }
        }
        else {
          $term_groups.show();
          $terms.show();
          if ($letterNavItems) {
            $letterNavItems.removeClass("disabled");
          }
          $("#terms-search-results", context).removeClass("no-result"); 

        }
      });

    }
  };
})(jQuery);
