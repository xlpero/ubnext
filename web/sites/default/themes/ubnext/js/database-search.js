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
    var height = $(".main").height();
    if ($("body").hasClass("loading")) {
      // remove it
      $(".main").hide();
      $(".facet-filter").fadeTo("fast", 1);
      $(".main").fadeIn();
      $("body").removeClass("loading");
      $(".main").height("auto");
    }
    else {
      // add it
      $(".main").height(height);
      $(".facet-filter").fadeTo("fast", 0.5);
      $(".main").fadeOut();
      $("body").addClass("loading");
    }

  }
  function loadHTMLFragment(url) {
    toggleLoader();
    $.get(url, function(data) {
      $(".main").html($(data).find(".main"));
      $(".sidebar").html($(data).find(".facet-filter"));
      History.pushState(null, null, url);
      toggleLoader();
    });

  }
  return {

    init: function(selector) {
      // setup history.js

      setupHistory();
      var $selector = $(selector);
      if ($selector) {

        var linkTarget = selector + " .facet-filter a, .clear-search-btn";
        $(document).on("click", linkTarget, function() {
          loadHTMLFragment($(this).attr("href"));
          if ($(this).hasClass("clear-search-btn"))
          {
            $('input.auto_submit').val('');
          }
          return false;
        });

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
