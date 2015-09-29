(function($, maps) {
  Drupal.gmap_tools.behaviors.fit_items_bounds = function(conf) {
    var conf = conf || {};
    this.init = function(gmap_tools_gmap) {
      //listen to items added
      function fit_items_bounds() {
        //Any way of avoiding first zooming in, then out here?
        //min_zoom?
        gmap_tools_gmap.gmap.fitBounds(gmap_tools_gmap.get_items_bounds());
        //TODO: check so that min_zoom is not larger than max_zoom
        //TODO: Fix so that max_zoom is not set to NaN
        if ('max_zoom' in conf && conf.max_zoom) {
          //TODO: fix this
          conf.max_zoom = parseInt(conf.max_zoom);
          //addListerOnce?
          var listener = maps.event.addListener(gmap_tools_gmap.gmap, 'idle', function() {
              if (gmap_tools_gmap.gmap.getZoom() > conf.max_zoom) {
                gmap_tools_gmap.gmap.setZoom(conf.max_zoom);
              }
              maps.event.removeListener(listener);
            }
          );
        }
        if('min_zoom' in conf && conf.min_zoom) {
          //TODO: fix this
          conf.min_zoom = parseInt(conf.min_zoom);
          //addListerOnce?
          var listener = maps.event.addListener(gmap_tools_gmap.gmap, 'idle', function() {
              if (gmap_tools_gmap.gmap.getZoom() < conf.min_zoom) {
                gmap_tools_gmap.gmap.setZoom(conf.min_zoom);
              }
              maps.event.removeListener(listener);
            }
          );
        }
      }
      maps.event.addListener(gmap_tools_gmap.gmap, 'gmap_tools_items_added', fit_items_bounds);
      maps.event.addListener(gmap_tools_gmap.gmap, 'resize', fit_items_bounds);
    }
  };
})(jQuery, google.maps);
