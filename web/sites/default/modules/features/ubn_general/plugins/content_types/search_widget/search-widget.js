(function($) {
  Drupal.behaviors.searchWidget = {
    attach: function(context, settings) {
      $('input[name="query"]', context).focus();
    }
  };
  // hijack form and redirect to Primo
  setTimeout(function() {
    $('body').on('click', '.search-widget-content-plate form button', function(e) {
      e.preventDefault();
      var lang = $('html').attr('lang');
      lang = lang == 'sv' ? 'sv_SE' : 'en_EN';
      var query = $('input[name="query"]').val();
      var url = 'https://gu-se-primo.hosted.exlibrisgroup.com/primo-explore/search?query=any,contains,' + query + '&vid=46GUB_VU1&search_scope=default_scope&sortby=rank&lang=' + lang;
      window.location.href = url;
    });

  }, 1);

})(jQuery);