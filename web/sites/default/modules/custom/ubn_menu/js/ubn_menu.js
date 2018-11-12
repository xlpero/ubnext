(function ($) {

  Drupal.behaviors.ubn_menu = {
    attach: function(context, settings) {
      $("#toggle-menu-btn, #menu-btn-close", context).on("click", function() {
      	if (!$("#toggle-menu-btn", context).hasClass("open")) {
      		$("#toggle-menu-btn", context).addClass("open");
      		$(".ubn-mobile-menu", context).show();
      	}
      	else {
      		$("#toggle-menu-btn", context).removeClass("open");
      		$(".ubn-mobile-menu", context).hide();
      	}
      });
      $(".ubn-mobile-menu", context).hide();
        


    }
  }
})(jQuery);
