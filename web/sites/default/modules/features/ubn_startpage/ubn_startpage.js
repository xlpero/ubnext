(function($) {
  Drupal.behaviors.ubn_startpage_equal_heights = {
    attach: function(context, settings) {
      if ($.fn.matchHeight) {
        $('.blurb', context).matchHeight();
      }
    }
  };

  Drupal.behaviors.ubn_startpage_blurb_mouse = {
    attach: function(context, settings) {
      $('.promoted-wrapper').on('mouseenter mouseleave', function(){
      	let el = $(this);
      	el.toggleClass('active');
      	 let img = el.find('.image-placeholder');
        if(img){
          img.toggleClass('active');
        }
      });

      $('.promoted-wrapper').on('click', function(){
      	let url = $(this).find('a').attr("href");
        window.location.href = url;
      });
    }
  };

  Drupal.behaviors.ubn_startpage_main_blurb_mouse = {
    attach: function(context, settings) {
      $('.blurb-wrapper').on('mouseenter mouseleave', function(){
        let el = $(this);
        el.toggleClass('active');
         let img = el.find('.image-placeholder');
        if(img){
          img.toggleClass('active');
        }
      });

      $('.blurb-wrapper').on('click', function(){
        let url = $(this).find('a').attr("href");
        window.location.href = url;
      });
    }
  };
})(jQuery);
