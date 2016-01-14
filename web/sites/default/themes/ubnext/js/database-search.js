var myModule = (function ($) {
  return {
    init: function(selector) {
      var $selector = $(selector);
      if ($selector) {
        $selector.find("a").bind( "click", function() {
          var $parent = $(this).parent();
          if ($parent.hasClass("parent-link")) {
              if ($parent.hasClass("expanded")) {
                $parent.removeClass("expanded");
                $parent.addClass("collapsed");
              }
              else {
                $parent.removeClass("collapsed");
                $parent.addClass("expanded");
              }
          }

        });

      }
    }
  }

})(jQuery);

jQuery(document).ready(function() {
  myModule.init("#database-filter-widget");
})
