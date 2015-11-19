(function ($) {
  Drupal.behaviors.ubn_scald = {
    attach: function(context, settings) {
      $('.ubn-video-play-button', context).click(function(e) {
        $video = $(this).parents('.ubn-video');
        var wrapped_player = $('<div></div>').html($video.data('player-html'));
        Drupal.attachBehaviors(wrapped_player, settings);
        $video.html(wrapped_player.contents());
      });
    }
  }
})(jQuery);
