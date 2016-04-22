(function ($) {


Drupal.behaviors.database = {
  attach: function(context, settings) {
      Drupal.setupHistory();
      $(".form-autocomplete", context).focus();
      $(".form-autocomplete", context).on("change paste keyup", function() {
          if ($(".form-autocomplete").val().length > 0) {
            Drupal.toggleClearFilters(context, true);
          }
          else {
            Drupal.toggleClearFilters(context, false);
          }
      });

      $(".facet-filter a, .clear-search-btn, .ubn-search-results-show-all, .sort-item", context).on("click", function() {
          Drupal.loadHTMLFragment($(this).attr("href"));
          if ($(this).hasClass("clear-search-btn"))
          {
            $('.form-autocomplete',context).val(''); // does not trigger change..
            Drupal.toggleClearFilters(context, false);
            $(".form-autocomplete", context).focus();
          }
          return false;
      });

      $('.ubn-facet-header', context).on( "click", function() {
        var $next = $(this).next();
        if ($next.hasClass("item-list")) {
          if ($next.hasClass("expanded")) {
              $next.removeClass("expanded")
              var $fa = $(this).find(".fa")
              if ($fa.hasClass("fa-chevron-up")) {
                $fa.removeClass("fa-chevron-up");
                $fa.addClass("fa-chevron-down");
              }
          }
          else {
            $next.addClass("expanded");
            var $fa = $(this).find(".fa")
            if ($fa.hasClass("fa-chevron-down")) {
              $fa.removeClass("fa-chevron-down");
              $fa.addClass("fa-chevron-up");
            }

          }
        }
        else {
          Drupal.loadHTMLFragment($(this).children().find("a").attr('href'));
        }
      });


      $('.submit-btn', context).on("click", function() {
        var query = $(".form-autocomplete").val();
        var url = $("form", context).attr("action") + query;
        Drupal.loadHTMLFragment(url);
        return false;
      })

      }
  };

  Drupal.setupHistory = function() {
    // Prepare
    History = window.History; // Note: We are using a capital H instead of a lower h

    History.Adapter.bind(window,'statechange',function(){ // Note: We are using statechange instead of popstate
      // Log the State
    //  var State = History.getState(); // Note: We are using History.getState() instead of event.state
    //  History.log('statechange:', State.data, State.title, State.url);
    });
  };


  Drupal.toggleClearFilters = function(context, show) {
    if (show === true) {
      $(".clear-search-btn", context).fadeIn(200);
    }
    else {
      $(".clear-search-btn", context).fadeOut(200);
    }
  };

  Drupal.toggleLoader = function() {
    var height = $(".main").height();
    if ($("body").hasClass("loading")) {
      // remove it
      $(".main-inner").hide();
      $(".facet-filter").fadeTo("fast", 1);
      $(".main-inner").fadeIn();
      $("body").removeClass("loading");
      $(".main").height("auto");
    }
    else {
      // add it
      $(".main").height(height);
      $(".facet-filter").fadeTo("fast", 0.5);
      $(".main-inner").fadeOut();
      $("body").addClass("loading");
    }

  };

  Drupal.loadHTMLFragment = function(url) {
    Drupal.toggleLoader();
    $.get(url, function(data) {
      var newContent = $(".ajax-container").html($(data).find(".ajax-container").html());
      History.pushState(null, null, url);
      Drupal.toggleLoader();
      Drupal.attachBehaviors(newContent);
    });
  };


    Drupal.jsAC.prototype.select = function(node) {
    var autocompleteValue = $(node).data('autocompleteValue');
    // Check whether this is not a suggestion but a "link".
    if (autocompleteValue.charAt(0) == ' ') {
      window.location.href = autocompleteValue.substr(1);
      return false;
    }
    this.input.value = autocompleteValue;
    $(this.input).trigger('autocompleteSelect', [node]);
    if ($(this.input).hasClass('auto_submit')) {
      if (typeof Drupal.search_api_ajax != 'undefined') {
        // Use Search API Ajax to submit
        Drupal.search_api_ajax.navigateQuery($(this.input).val());
      }
      else {
      //  var selector = getSetting(this.input, 'selector', ':submit');
       // $(selector, this.input.form).trigger('click');
      }
      return true;
    }
  };

})(jQuery);


