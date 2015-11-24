(function ($) {
  Drupal.behaviors.searchWidget = {
    attach: function (context, settings) {
   		$('input[name="q"]', context).focus();
    }
  };
})(jQuery);