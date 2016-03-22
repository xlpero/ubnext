Drupal.behaviors.entityForm = {
  attach: function (context, settings) {
    if (jQuery("#issue-entityform-edit-form-10460").length) {
      alert("exist");
      jQuery("#" + Drupal.settings.ubn_entityform.formId).css("border", "1px solid red");
    }
    jQuery("#" + Drupal.settings.ubn_entityform.formId).submit(function(e) {
      alert("#" + Drupal.settings.ubn_entityform.formId);
        var url = Drupal.settings.ubn_entityform.postPath; // the script where you handle the form input.
        $.ajax({
               type: "POST",
               url: url,
               data: $(Drupal.settings.ubn_entityform.formId).serialize(), // serializes the form's elements.
               success: function(data)
               {
                loadHTMLFragment(data);
                toggleLoader();
               }
             });
        e.preventDefault(); // avoid to execute the actual submit of the form.
    });
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
