(function($) {
  Drupal.behaviors.ubn_startpage_equal_heights = {
    attach: function(context, settings) {
      if ($.fn.matchHeight) {
        $('.blurb', context).matchHeight();
      }

       // mouse enter on promoted story
      $('div.story-promoted-container').on('mouseenter',function(){
      	$(this).css('cursor', 'pointer');
      	$(this).find('a').css('text-decoration', 'underline');
  		});
  		// mouse leave on promoted story
  		$('div.story-promoted-container').on('mouseleave',function(){
      	$(this).css('cursor', 'default');
      	$(this).find('a').css('text-decoration', 'none');

  		});

  		$('div.story-promoted-container').on('click',function(){
  			let url = $(this).find('a').attr("href");
        window.location.href = url;
  		});
    }
  };
})(jQuery);
