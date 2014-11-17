(function ($) {
    //add drupal 7 code
    Drupal.behaviors.myfunction = {
        attach: function(context, settings) {

		//some jquery goodness here...
			$("#menu-toggler-btn").bind( "click", function() {
				var itemToDisplay = $(".secondary-navigation");
				itemToDisplay.toggle();
			});
	 	 }
 	 }
})(jQuery);