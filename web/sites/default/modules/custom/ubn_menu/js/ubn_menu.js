(function ($) {
  Drupal.behaviors.ubn_menu = {
    attach: function(context, settings) {
      console.log('context', context);
      console.log('settings', settings);
      $(".ubn-mobile-menu").hide();
      $("#toggle-menu-btn").bind("click", function() {
      	if (!$("#toggle-menu-btn").hasClass("open")) {
      		$("#toggle-menu-btn").addClass("open");
      		$(".ubn-mobile-menu").slideDown(100);
      	}
      	else {
      		$("#toggle-menu-btn").removeClass("open");
      		$(".ubn-mobile-menu").slideUp(100);
      	}
      });
    }
  }
})(jQuery);
