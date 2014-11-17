
$(function() {
	$("#menu-toggler-btn").bind( "click", function() {
		var itemToDisplay = $(".secondary-navigation");
		itemToDisplay.toggle();
	});
});