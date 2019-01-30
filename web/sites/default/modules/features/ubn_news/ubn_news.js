(function($) {
  Drupal.behaviors.ubn_news_equal_heights = {
    attach: function(context, settings) {
      if ($.fn.matchHeight) {
        $('.story-promoted', context).matchHeight();
      }
      // mouse enter on promoted story
      $('div.story-promoted').on('mouseenter',function(){
        var el = $(this);
      	el.css('cursor', 'pointer');
      	el.find('a').css('text-decoration', 'underline');

        var img = el.find('.image-placeholder');
        if(img){
          img.addClass('active');
        }

  		});
  		// mouse leave on promoted story
  		$('div.story-promoted').on('mouseleave',function(){
        var el = $(this);
      	el.css('cursor', 'default');
      	el.find('a').css('text-decoration', 'none');

        var img = el.find('.image-placeholder');
        if(img){
          img.removeClass('active');
        }

  		});

  		$('div.story-promoted-container').on('click',function(){
  			let url = $(this).find('a').attr("href");
        window.location.href = url;
  		});

    }
  };
})(jQuery);
