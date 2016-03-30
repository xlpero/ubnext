Drupal.behaviors.entityForm = {
  attach: function (context, settº»ings) {
    var form_id = "#" + Drupal.settings.ubn_entityform.formId;
    var anonymousCheckbox = form_id + " #edit-field-anonymus-und";
    var nameId = form_id + " #edit-field-full-name";
    var emailId = form_id + " #edit-field-email";
    var that = this;

   /* jQuery(document).on("change", anonymousCheckbox, function() {
      if (jQuery(this).prop("checked")) {
        jQuery(nameId + " input[type='text']").val("Anonymous");
        jQuery(nameId + " input[type='text']").prop('type', 'hidden');
        jQuery(nameId + " label").hide();
       
        jQuery(emailId + " input[type='text']").val("anonymous@anonymous.se");
        jQuery(emailId + " input[type='text']").prop('type', 'hidden');
        jQuery(emailId + " label").hide();
      }
      else {
        jQuery(nameId + " input[type='hidden']").val("");
        jQuery(nameId + " input[type='hidden']").prop('type', 'text');
        jQuery(nameId + " label").show()

        jQuery(emailId + " input[type='hidden']").val("");
        jQuery(emailId + " input[type='hidden']").prop('type', 'text');
        jQuery(emailId + " label").show();
      }
    });*/

    
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
