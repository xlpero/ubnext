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
  


/*var myModule = (function ($) {
  function toggleLoader() {
    var height = $(".main").height();
    if ($("body").hasClass("loading")) {
      // remove it
      $(".main-inner").hide();
      $(".facet-filter").fadeTo("fast", 1);
      $(".main-inner").fadeIn();
      $("body").removeClass("loading");
      $(".main").height("auto");
    }
    else {
      // add it
      $(".main").height(height);
      $(".facet-filter").fadeTo("fast", 0.5);
      $(".main-inner").fadeOut();
      $("body").addClass("loading");
    }
  }
  function loadHTMLFragment(data) {
	$(".entityform").html($(data).find(".entityform").html());
  };



  return {

    init: function(selector) {
     // this is the id of the form
		$("#issue-entityform-edit-form-10460").submit(function(e) {
			toggleLoader();
		    var url = "/ubnext/web/en/libraries/art-library"; // the script where you handle the form input.
		    $.ajax({
		           type: "POST",
		           url: url,
		           data: $("#issue-entityform-edit-form-10460").serialize(), // serializes the form's elements.
		           success: function(data)
		           {
		           	loadHTMLFragment(data);
		           	toggleLoader();
		           }
		         });

		    e.preventDefault(); // avoid to execute the actual submit of the form.
		});
    }

  }

})(jQuery);

jQuery(document).ready(function() {
  myModule.init(".node-type-library");
})*/
