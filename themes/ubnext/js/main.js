(function ($) {
    //add drupal 7 code
    Drupal.behaviors.myfunction = {
        attach: function(context, settings) {

		//some jquery goodness here...
			$("#menu-toggler-btn").bind( "click", function() {
				var itemToDisplay = $(".mega-menu");
				itemToDisplay.animate({
		            height: "toggle",
		            opacity: "toggle"
		        }, 300, function() {
		        	itemToDisplay.css("overflow", "visible");
		        });
			});
	 	 }
 	 }
})(jQuery);