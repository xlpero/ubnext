(function ($) {

    Drupal.behaviors.ubMap = {
        attach: function(context, settings) {
			console.log(settings.ubMap);

			var myLatlng = new google.maps.LatLng(57.697925,11.961829);
			var mapOptions = {
			  center: myLatlng,
			  zoom: 15
			};
			var map = new google.maps.Map(document.getElementById('ub-map-canvas'),
			mapOptions);

			var marker = new google.maps.Marker({
			  position: myLatlng,
			  map: map,
			  title: 'Samhällsvetenskapliga'
			});

    	}
    }
})(jQuery);
