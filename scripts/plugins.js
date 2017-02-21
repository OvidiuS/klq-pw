/////////////////////////
// clearing default values of fields
// to use this to align something vertially with its parent, you type: $("#idOrClassOfFiledIWantToClearTheDefaultValueFrom").vAlign(); 

(function($){
    $.fn.clearDefault = function(){
		this.css('color','#8e8d8d');
		return this.each(function(){
			var default_value = $(this).val();
			$(this).focus(function(){
				if ($(this).val() == default_value) $(this).val("").css('color','black');
			});
			$(this).blur(function(){
				if ($(this).val() == "") $(this).val(default_value).css('color','#8e8d8d');
			});
		});
	};
})(jQuery);

///////////////////////////////////////////
// vertical align
// to use this to align something vertially with its parent, you type: $("#idOrClassOfElementIWantToVerticalAlignWithItsParent").vAlign(); in the custom.js file

(function ($) {
// VERTICALLY ALIGN FUNCTION
$.fn.vAlign = function() {
	return this.each(function(i){
	var ah = $(this).height();
	var ph = $(this).parent().height();
	//alert ('this height: ' + ah +  ' parent height: ' + ph);
	var mh = Math.ceil((ph-ah) / 2);
	$(this).css('margin-top', mh);
	});
};
})(jQuery);



/*!
*  JqueryAsynchImageLoader (JAIL) : plugin for jQuery
*
* Developed by
* Sebastiano Armeli-Battana (@sebarmeli) - http://www.sebastianoarmelibattana.com
* Dual licensed under the MIT or GPL Version 3 licenses.
* @version 0.9.5
*/
;(function(a){var b=a(window);a.fn.asynchImageLoader=a.fn.jail=function(d){d=a.extend({timeout:10,effect:false,speed:400,selector:null,offset:0,event:"load+scroll",callback:jQuery.noop,callbackAfterEachImage:jQuery.noop,placeholder:false,container:window},d);var c=this;a.jail.initialStack=this;this.data("triggerEl",(d.selector)?a(d.selector):b);if(d.placeholder!==false){c.each(function(){a(this).attr("src",d.placeholder);});}if(/^load/.test(d.event)){a.asynchImageLoader.later.call(this,d);}else{a.asynchImageLoader.onEvent.call(this,d,c);}return this;};a.asynchImageLoader=a.jail={_purgeStack:function(c){var d=0;while(true){if(d===c.length){break;}else{if(c[d].getAttribute("data-href")){d++;}else{c.splice(d,1);}}}},_loadOnEvent:function(g){var f=a(this),d=g.data.options,c=g.data.images;a.asynchImageLoader._loadImage(d,f);f.unbind(d.event,a.asynchImageLoader._loadOnEvent);a.asynchImageLoader._purgeStack(c);if(!!d.callback){a.asynchImageLoader._purgeStack(a.jail.initialStack);a.asynchImageLoader._launchCallback(a.jail.initialStack,d);}},_bufferedEventListener:function(g){var c=g.data.images,d=g.data.options,f=c.data("triggerEl");clearTimeout(c.data("poller"));c.data("poller",setTimeout(function(){c.each(function e(){a.asynchImageLoader._loadImageIfVisible(d,this,f);});a.asynchImageLoader._purgeStack(c);if(!!d.callback){a.asynchImageLoader._purgeStack(a.jail.initialStack);a.asynchImageLoader._launchCallback(a.jail.initialStack,d);}},d.timeout));},onEvent:function(d,c){c=c||this;if(d.event==="scroll"||d.selector){var e=c.data("triggerEl");if(c.length>0){e.bind(d.event,{images:c,options:d},a.asynchImageLoader._bufferedEventListener);if(d.event==="scroll"||!d.selector){b.resize({images:c,options:d},a.asynchImageLoader._bufferedEventListener);}return;}else{if(!!e){e.unbind(d.event,a.asynchImageLoader._bufferedEventListener);}}}else{c.bind(d.event,{options:d,images:c},a.asynchImageLoader._loadOnEvent);}},later:function(d){var c=this;if(d.event==="load"){c.each(function(){a.asynchImageLoader._loadImageIfVisible(d,this,c.data("triggerEl"));});}a.asynchImageLoader._purgeStack(c);a.asynchImageLoader._launchCallback(c,d);setTimeout(function(){if(d.event==="load"){c.each(function(){a.asynchImageLoader._loadImage(d,a(this));});}else{c.each(function(){a.asynchImageLoader._loadImageIfVisible(d,this,c.data("triggerEl"));});}a.asynchImageLoader._purgeStack(c);a.asynchImageLoader._launchCallback(c,d);if(d.event==="load+scroll"){d.event="scroll";a.asynchImageLoader.onEvent(d,c);}},d.timeout);},_launchCallback:function(c,d){if(c.length===0&&!a.jail.isCallback){d.callback.call(this,d);a.jail.isCallback=true;}},_loadImageIfVisible:function(d,g,f){var e=a(g),c=(/scroll/i.test(d.event))?f:b;if(a.asynchImageLoader._isInTheScreen(c,e,d.offset)){a.asynchImageLoader._loadImage(d,e);}},_isInTheScreen:function(j,c,h){var f=j[0]===window,n=(f?{top:0,left:0}:j.offset()),g=n.top+(f?j.scrollTop():0),i=n.left+(f?j.scrollLeft():0),e=i+j.width(),k=g+j.height(),m=c.offset(),l=c.width(),d=c.height();return(g-h)<=(m.top+d)&&(k+h)>=m.top&&(i-h)<=(m.left+l)&&(e+h)>=m.left;},_loadImage:function(c,d){d.hide();d.attr("src",d.attr("data-href"));d.removeAttr("data-href");if(c.effect){if(c.speed){d[c.effect](c.speed);}else{d[c.effect]();}}else{d.show();}c.callbackAfterEachImage.call(this,c);}};}(jQuery));

