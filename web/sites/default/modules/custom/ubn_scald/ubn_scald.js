(function ($) {
  Drupal.behaviors.ubn_scald = {
    attach: function(context, settings) {
      //TODO: make sure can be clicked only once
      $('.ubn-video-play-button', context).click(function(e) {
        $video = $(this).parents('.ubn-video');
        //TODO: attach behaviors thing (check scald)
        var wrapped_player = $('<div></div>').html($video.data('player-html'));
        Drupal.attachBehaviors(wrapped_player, settings);
        //$self.html(wrapped_player.contents());
        $video.html(wrapped_player.contents());
      });
    }
  }
})(jQuery);
