(function ($) {
  Drupal.behaviors.ubn_scald = {
    attach: function(context, settings) {
      //TODO: make sure can be clicked only once
      $('.ubn-video', context).click(function(e) {
        $self = $(this);
        //TODO: attach behaviors thing (check scald)
        var wrapped_player = $('<div></div>').html($self.data('player-html'));
        Drupal.attachBehaviors(wrapped_player, settings);
        //$self.html(wrapped_player.contents());
        $self.html(wrapped_player.contents());
      });
    }
  }
})(jQuery);
