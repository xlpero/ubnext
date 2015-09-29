(function($, maps) {

Drupal.gmap_tools.behaviors.clustered = function(options) {

  var options = options || {};

  this.init = function(gmap_tools) {

    var cm_options = options.cm_options || {
      gridSize : 50,
      maxZoom : 7
    };
 
    var clusterer = new MarkerClusterer(gmap_tools.gmap, [], cm_options);

    gmap_tools.add_markers = function(markers) {
      clusterer.addMarkers(markers);
    };

    gmap_tools.remove_marker = function(marker) {
      clusterer.remove_marker(marker); 
    };

    gmap_tools.clear_markers = function() {
      clusterer.clearMarkers(); 
    };

    var parent_update_view = gmap_tools.update_view;

    gmap_tools.update_view = function() {
      parent_update_view.apply(this);
      clusterer.redraw();
    }
  }

};
})(jQuery, google.maps);
