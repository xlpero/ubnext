(function ($) {
Drupal.behaviors.entityForm = {
  attach: function (context, settings) {
    if("ubn_entityform" in Drupal.settings) {
      var that = this;
      for(i in Drupal.settings.ubn_entityform) {
        $form = $(Drupal.settings.ubn_entityform[i].formId, context);
        if($form.length) {
          $form.on("submit", Drupal.settings.ubn_entityform[i], function (e) {
            var form_settings = e.data;
            var $this = $(this);
            that.toggleLoading($this, form_settings.postingStr);
            $.ajax({
              type: "POST",
              url: form_settings.postPath, // the script where you handle the form input.
              data: $this.serialize(), // serializes the form's elements.
              success: function(data) {
                that.toggleLoading($this, form_settings.postingStr, function() {
                  var $new_form = that.replaceForm($this, form_settings.formId, data);
                  //TODO: consistant class names in tempalte, and change this:
                  if($('.ubn-form-status-messages', $new_form).length) {
                    //$new_form closest?
                    Drupal.ubnext.scrollTo($(form_settings.formId).closest('.content-sections-section-contacts-contact'));
                  }
                });
              }
            });
            e.preventDefault(); // avoid to execute the actual submit of the form.
          });
        }
      }
    }
  },
  replaceForm: function($old_form, formId, data){
    var $form_wrapped = $(data).find(formId).wrap('<div></div>').parent();
    Drupal.attachBehaviors($form_wrapped);
    var $new_form = $form_wrapped.contents();
    $old_form.replaceWith($new_form);
    return $new_form;
  },

  toggleLoading: function($form, posting_string, complete) {
    //Disable submit?
    if ($form.hasClass("loading")) {
      $form.fadeTo("fast", 1, function() {
        $form.removeClass("loading");
        complete();
      });
    }
    else {
      $form
        .addClass("loading")
        .fadeTo("fast", 0.5)
        //.find(':input')
        //.prop('disabled', true)
        //.end()
        .find(".form-submit")
        .prop('disabled', true)
        .html(posting_string + " <i class='fa fa-circle-o-notch fa-spin'></i>");
    }
  }
};
})(jQuery);