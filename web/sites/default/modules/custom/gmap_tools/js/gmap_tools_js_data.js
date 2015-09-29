(function($) {
  /*
  function construct(constructor, args) {
    function F() {
      return constructor.apply(this, args);
    }
    F.prototype = constructor.prototype;
    F.constructor = constructor;
    return new F();
  }
  */

  var create_function = (function() {
      function constructor(args) {
        return Function.apply(this, args);
      }
      return function(args) {
        var func = new constructor(args);
        func.constructor = Function;
        return func;
      }
    })();

  Drupal.gmap_tools_js_data_process = function(data) {
    //TODO: API
    if(data.type === 'string') {
      return data.value;
    }
    else if(data.type === 'integer') {
      //TODO: check if already integer, or assume string?
      return parseInt(data.value);
    }
    else if(data.type === 'float') {
      return parseFloat(data.value);
    }
    else if(data.type === 'boolean') {
      //check what
      if(typeof data.value !== 'boolean') {
        if (typeof data.value === 'string') {
          return data.value.toLowerCase() !== 'false' && parseInt(data) !== 0;
        }
        else if(typeof data.value == 'number') {
          return data.value !== 0;
        }
        else {
          //TODO: is this a good idea?
          return false;
        }
      }
      return data.value;
    }
    else if(data.type === 'function') {
      var args = data.value.arguments;
      args.push(data.value.body);
      var func = create_function(args);
      return func;
    }
    else {
      return false; //??
    }
  }
})(jQuery);
