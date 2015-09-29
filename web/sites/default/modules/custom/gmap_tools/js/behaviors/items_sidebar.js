(function($, maps) {

Drupal.gmap_tools.behaviors.items_sidebar = function(options) {

  var options = options || {};
  
  //Default options
  options = $.extend({'bounce' : true}, options);
  
  this.init = function(gmap_tools) {

    function _marker_start_bounce(e) {
      var id = $(this).data('gmap_tools_item_id');
      var marker = gmap_tools.get_marker(id);
      marker.setAnimation(maps.Animation.BOUNCE);
    }

    function _marker_stop_bounce(e) {
      var id = $(this).data('gmap_tools_item_id');
      var marker = gmap_tools.get_marker(id);
      marker.setAnimation(null);
    }

    var $items_sidebar_div = $('<div id="gmap-tools-items-sidebar"></div>');

    if(typeof options.wrapper !== 'undefined') {
      $(options.wrapper).html($items_sidebar_div);
    }
    else {
      var div = gmap_tools.gmap.getDiv();
      $items_sidebar_div.insertAfter(div);
    }

    //TODO: bit hackish
    var add_listener = true;

    function refresh_items_sidebar() {
      var visible_items;
      var i;
      var $sidebar_item;

      function sidebar_item_click_handler(item_marker) {
        return function(e) {
          maps.event.trigger(item_marker, 'click');
        };
      }

      if(add_listener) {
        add_listener = false;
        maps.event.addListenerOnce(gmap_tools.gmap, 'idle', function() {

            //TODO: fix this shit
            var limit = options.limit || 25;

            //TODO: repace with custom filter?
            visible_items = typeof options.items_filter === 'undefined' ?
              gmap_tools.get_visible_items(limit) :
              gmap_tools.get_visible_items(limit, options.items_filter); 

            $items_sidebar_div.empty();

            if(visible_items !== false) {
              for(i in visible_items) {
                $item = $(Drupal.theme('gmap_tools_items_sidebar_item', visible_items[i]));
                $item.data('gmap_tools_item_id', visible_items[i]._key); 

                if(options.bounce) {
                  $item.hover(_marker_start_bounce, _marker_stop_bounce);
                }

                $item.click(sidebar_item_click_handler(visible_items[i].marker))
                .appendTo($items_sidebar_div);

                maps.event.trigger(gmap_tools.gmap, 'gmap_tools_sidebar_item_added', $item);
              }
              $(':first-child', $items_sidebar_div).addClass('first');
              $(':last-child', $items_sidebar_div).addClass('last');
              $($items_sidebar_div).children(':even').addClass('even');
              $($items_sidebar_div).children(':odd').addClass('odd');
            }
            add_listener = true;
          }
        );
      }
    }
    maps.event.addListener(gmap_tools.gmap, 'dragend', refresh_items_sidebar);
    maps.event.addListener(gmap_tools.gmap, 'zoom_changed', refresh_items_sidebar);
  }

};

//TODO: check drupal js
Drupal.theme.prototype.gmap_tools_items_sidebar_item = function(item) {
  return [
    '<div class="gmap-tools-sidebar-item"><a href="javascript:void(0)" class="clearfix"><span class="title">',
    item.title,
    '</span></a></div>'
  ].join('');
};

})(jQuery, google.maps);
