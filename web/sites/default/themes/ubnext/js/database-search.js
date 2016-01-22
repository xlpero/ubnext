var myModule = (function ($) {
  return {
    init: function(selector) {
      var $selector = $(selector);
      if ($selector) {
        $selector.find(".ubn-facet-header").bind( "click", function() {
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
            window.location = $(this).children().find("a").attr('href');
          }
        });

      }
    }
  }

})(jQuery);

jQuery(document).ready(function() {
  myModule.init(".page-search-databases");
})
