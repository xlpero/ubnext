//TODO: remove this file

(function($) {
    Drupal.behaviors.gmap_tools_views = {
      'attach' : function(context, settings) {
        if ('gmap_tools_views' in settings) {
          for (namespace in settings.gmap_tools_views) {
            var options = settings.gmap_tools_views[namespace];

            //TODO: ajax and attach behaviors? Will this work?
            if(!(namespace in settings.gmap_tools.maps)) {

              $map_container = $('#' + options.container_id, context);

              if($map_container.length) {
                //Build  conf
                //Clone?
                var gmap_conf = options.gmap_options;
                if('mapTypeId' in options.gmap_options) {
                  gmap_conf.mapTypeId = google.maps.MapTypeId[options.gmap_options.mapTypeId];
                }
                if('center' in options.gmap_options) {
                  gmap_conf.center = new google.maps.LatLng(
                    options.gmap_options.center.lat,
                    options.gmap_options.center.lng
                  );
                }

                //TODO: provide gmap_tools specific settings
                var conf = {
                  gmap_conf : gmap_conf
                };

                if ('items' in options) {
                  conf.items = options.items;
                }
                conf.behaviors = [];
                for (behavior in options.behaviors) {
                  if(behavior in Drupal.gmap_tools.behaviors) {
                    var behavior_options = options.behaviors[behavior];

                    //TODO: fix this kludy thing
                    for(var behavior_option in behavior_options) {
                      behavior_options[behavior_option] = Drupal.gmap_tools_js_data_process(behavior_options[behavior_option]);
                    }

                    conf.behaviors.push(new Drupal.gmap_tools.behaviors[behavior](behavior_options));
                  }
                  else {
                    //TODO
                    console.log('FAIL');
                  }
                }
                $map_container.gmap_tools_gmap(conf);
              }
            }
            else {

            }
            //Add items
          }
        }
      }
    };
})(jQuery);
