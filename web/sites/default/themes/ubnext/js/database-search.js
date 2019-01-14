(function ($) {
Drupal.behaviors.database = {
  attach: function(context, settings) {
      Drupal.setupHistory();
      if ($(".form-autocomplete").val() === "") {
        if (/=field_topics_depth_/.test(window.location.href)) {
          $('.ubn-search-sorts').hide();
        }
        else {
          $('.ubn-search-sorts .last').hide();
        }
      }
      else {
        $('.ubn-search-sorts .last').show();
      }
      $(".form-autocomplete", context).focus();
      $(".form-autocomplete", context).on("change paste keyup", function() {
          if ($(this).val().length > 0) {
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

      $('.database-item-link-title a', context).on( "click", function() {
        window.location.href = $(this).attr("href") + "?refering=" + escape(window.location.href);
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
        var actionUrl = Drupal.settings.ubn_databases.basePath;
        var lastChar = actionUrl.substr(-1); // Selects the last character
        if (lastChar !== '/') {         // If the last character is not a slash
          actionUrl += "/";
        }
        actionUrl = actionUrl + query;
        Drupal.loadHTMLFragment(actionUrl);
        return false;
      })

      }
  };

  Drupal.alreadyTriggered = false;

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
      Drupal.alreadyTriggered = false;
    });
  };




  var getSetting = function (input, setting, defaultValue) {
    // Earlier versions of jQuery, like the default for Drupal 7, don't properly
    // convert data-* attributes to camel case, so we access it via the verbatim
    // name from the attribute (which also works in newer versions).
    var search = $(input).data('search-api-autocomplete-search');
    if (typeof search == 'undefined'
        || typeof Drupal.settings.search_api_autocomplete == 'undefined'
        || typeof Drupal.settings.search_api_autocomplete[search] == 'undefined'
        || typeof Drupal.settings.search_api_autocomplete[search][setting] == 'undefined') {
      return defaultValue;
    }
    return Drupal.settings.search_api_autocomplete[search][setting];
  };

  if (Drupal.jsAC) {
      Drupal.jsAC.prototype.onkeyup = function (input, e) {
        if (!e) {
          e = window.event;
        }
        // This comes from drupals autocomplete.js
        if (!e) {
          e = window.event;
        }
        switch (e.keyCode) {
          case 16: // Shift.
          case 17: // Ctrl.
          case 18: // Alt.
          case 20: // Caps lock.
          case 33: // Page up.
          case 34: // Page down.
          case 35: // End.
          case 36: // Home.
          case 37: // Left arrow.
          case 38: // Up arrow.
          case 39: // Right arrow.
          case 40: // Down arrow.
            return true;

          case 9:  // Tab.
          case 13: 
            if ($(input).hasClass('auto_submit')) {
                var selector = getSetting(input, 'selector', ':submit');
                $(selector, input.form).trigger('click');
                Drupal.alreadyTriggered = true;
            }
          case 27: // Esc.
            this.hidePopup(e.keyCode);
            return true;

          default: // All other keys.
            if (input.value.length > 0 && !input.readOnly) {
              this.populatePopup();
            }
            else {
              this.hidePopup(e.keyCode);
            }
            return true;
        }
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
            if (!Drupal.alreadyTriggered) {
              var selector = getSetting(this.input, 'selector', ':submit');
              $(selector, this.input.form).trigger('click');
              Drupal.alreadyTriggered = false;
            }
          }
          return true;
        }
      };
    }

})(jQuery);


