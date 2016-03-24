(function ($) {
  Drupal.behaviors.ubn_menu = {
    attach: function(context, settings) {
      $(".ubn-mobile-menu", context).hide();
      $("#toggle-menu-btn", context).bind("click", function() {
      	if (!$("#toggle-menu-btn", context).hasClass("open")) {
      		$("#toggle-menu-btn", context).addClass("open");
      		$(".ubn-mobile-menu", context).slideDown(100);
      	}
      	else {
      		$("#toggle-menu-btn", context).removeClass("open");
      		$(".ubn-mobile-menu", context).slideUp(100);
      	}
      });
    }
  }
})(jQuery);
