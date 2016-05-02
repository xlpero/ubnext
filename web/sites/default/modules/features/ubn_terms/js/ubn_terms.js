(function($) {
  Drupal.behaviors.ubn_terms = {
    attach : function(context, settings) {
      $collapsibles = $('.term-collapsible', context);
      $collapsibles.on('show.bs.collapse', function() {
        //Showing
        $(this).find('.fa').removeClass('fa-chevron-down').addClass('fa-chevron-up');
      });
      $collapsibles.on('hide.bs.collapse', function() {
        //Hiding
        $(this).find('.fa').removeClass('fa-chevron-up').addClass('fa-chevron-down');
      });
    }
  }
})(jQuery);
