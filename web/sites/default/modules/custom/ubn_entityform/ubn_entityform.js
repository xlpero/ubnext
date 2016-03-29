Drupal.behaviors.entityForm = {
  attach: function (context, settings) {
    var form_id = "#" + Drupal.settings.ubn_entityform.formId;
    var that = this;
    jQuery(document).on("submit", form_id, context, function (e) {
        var url = Drupal.settings.ubn_entityform.postPath; // the script where you handle the form input.
        that.toggleLoading(form_id);
        jQuery.ajax({
               type: "POST",
               url: url,
               data: jQuery(form_id).serialize(), // serializes the form's elements.
               success: function(data)
               {
                that.replaceForm(form_id, data);
                that.toggleLoading(form_id);
               }
             });
        e.preventDefault(); // avoid to execute the actual submit of the form.
    })

  },
  replaceForm: function(formId, data) {
    jQuery(formId).html(jQuery(data).find(formId).html());
  
  },

  toggleLoading: function(id) {
    if (jQuery(id).hasClass("loading")) {
      jQuery(id).fadeTo("fast", 1);      
      jQuery(id).removeClass("loading");
    }
    else {
      jQuery(id).fadeTo("fast", 0.5);
      jQuery(id).find("#edit-submit").html(Drupal.settings.ubn_entityform.postingStr + " <i class='fa fa-circle-o-notch fa-spin'></i>");
      jQuery(id).addClass("loading");
    }

  }
};
