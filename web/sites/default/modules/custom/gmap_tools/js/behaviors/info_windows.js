(function($, maps) {
Drupal.gmap_tools.behaviors.info_windows = function() {
  var _info_windows = {};
  //Keep state of open info windows? 
  var _open_info_windows = {};

  function _close_all_info_windows() {
    for(key in _open_info_windows) {
      _close_info_window(key);
    }
  }

  function _close_info_window(key) {
    _info_windows[key].close();
    if(key in _open_info_windows) {
      delete _open_info_windows[key];
    }
  }

  function _open_info_window(key) {
    _info_windows[key].open();
  }

  function _info_window_on_click(gmap, item) {
    return function(e) {
      var info_window;
      if(!(item._key in _info_windows)) {
        _info_windows[item._key] = new maps.InfoWindow({
            'content' : item.content,
            'position' : item._marker.getPosition()
          }
        );
      }
      info_window = _info_windows[item._key];
      _close_all_info_windows();
      info_window.open(gmap, item._marker);
      _open_info_windows[item._key] = info_window;
    }
  }

  this.init = function(gmap_tools_gmap) {

    maps.event.addListener(gmap_tools_gmap.gmap, 'gmap_tools_item_added', function(item) {
        //TODO: add to item?
        // Remove this listener in item_removed?
        maps.event.addListener(item._marker, 'click', _info_window_on_click(gmap_tools_gmap.gmap, item));
      }
    );

    maps.event.addListener(gmap_tools_gmap.gmap, 'gmap_tools_item_removed', function(item) {
        _close_info_window(item._key);
        delete _info_windows[item.key];
      }
    );

    gmap_tools_gmap.get_info_window = function(key) {
      return _info_windows[key];
    }

    gmap_tools_gmap.close_all_info_windows = _close_all_info_windows;

  }
};
})(jQuery, google.maps);
