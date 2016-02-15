var myModule = (function ($) {
  var History = null;


  function setupHistory() {
    // Prepare
    History = window.History; // Note: We are using a capital H instead of a lower h

    History.Adapter.bind(window,'statechange',function(){ // Note: We are using statechange instead of popstate
      // Log the State
    //  var State = History.getState(); // Note: We are using History.getState() instead of event.state
    //  History.log('statechange:', State.data, State.title, State.url);
    });
  }

  function toggleLoader() {
    var height = $(".ajax-container").height();
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
      $(".ajax-container").height(height);
      $(".facet-filter").fadeTo("fast", 0.5);
      $(".main-inner").fadeOut();
      $("body").addClass("loading");
    }

  }
  function loadHTMLFragment(url) {
    toggleLoader();
    $.get(url, function(data) {
      $(".ajax-container").html($(data).find(".ajax-container"));
      History.pushState(null, null, url);
      toggleLoader();
    });

  }


  function getSetting(input, setting, defaultValue) {
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

  return {

    init: function(selector) {
      if (typeof Drupal.jsAC != 'undefined') {
        Drupal.jsAC.prototype.select = function(node) {
          var autocompleteValue = $(node).data('autocompleteValue');
          // Check whether this is not a suggestion but a "link".
          if (autocompleteValue.charAt(0) == ' ') {
          //  window.location.href = autocompleteValue.substr(1);
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
              var selector = getSetting(this.input, 'selector', ':submit');
              $(selector, this.input.form).trigger('click');
            }
            return true;
          }
        };
      }
      // setup history.js
      setupHistory();
      var $selector = $(selector);
      if ($selector) {

        var linkTarget = selector + " .facet-filter a, .clear-search-btn, .ubn-search-results-show-all, .sort-item";
        $(document).on("click", linkTarget, function() {
          loadHTMLFragment($(this).attr("href"));
          if ($(this).hasClass("clear-search-btn"))
          {
            $('input.auto_submit').val('');
          }
          return false;
        });

        var submitTarget = selector + " .form-submit";
        $(document).on("click", submitTarget, function() {
          var query = $(".auto_submit").val();
          var url = $selector.find(".clear-search-btn").attr("href") + "/" + query;
          loadHTMLFragment(url);
          return false;
        })
          var headerTarget = selector + " .ubn-facet-header";
          $(document).on( "click", headerTarget, function() {
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
            loadHTMLFragment($(this).children().find("a").attr('href'));
          }
        });

      }
    }

  }

})(jQuery);

jQuery(document).ready(function() {
  myModule.init(".page-search-databases");
})
