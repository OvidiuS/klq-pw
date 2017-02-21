// $("ul.mainMenu li a span").vAlign();
$(document).ready(function() {

  // $(".homepageSlideshow").owlCarousel({
  // 	navigation : false, // Show next and prev buttons
  //   slideSpeed : 300,
  //   paginationSpeed : 400,
  //   singleItem:true,
  //   autoPlay: 3000,
  //   transitionStyle : "fade"
  // });
  //  // Custom Navigation Events
  // $(".homepageSlideshowNavigation .next").click(function(){
  //   $(".homepageSlideshow").trigger('owl.next');
  // })
  // $(".homepageSlideshowNavigation .prev").click(function(){
  //   $(".homepageSlideshow").trigger('owl.prev');
  // })
 
  // $(".homepageMiniSlideshow").owlCarousel({
  // 	navigation : false, // Show next and prev buttons
  //   slideSpeed : 300,
  //   paginationSpeed : 400,
  //   singleItem:true,
  //   autoPlay: 3000
  // });
  //  // Custom Navigation Events
  // $(".homepageMiniSlideshowNavigation .next").click(function(){
  //   $(".homepageMiniSlideshow").trigger('owl.next');
  // })
  // $(".homepageMiniSlideshowNavigation .prev").click(function(){
  //   $(".homepageMiniSlideshow").trigger('owl.prev');
  // })
});

/* map */

$(document).ready(function(){
	var settings = {
		'viewportWidth' : '100%',
		'viewportHeight' : '100%',
		'fitToViewportShortSide' : true,  
		'contentSizeOver100' : false,
		'startScale' : 0,
		'startX' : 0,
		'startY' : 0,
		'animTime' : 500,
		'draggInertia' : 10,
		'imgDir' : '/site/templates/images/map/',
		'mainImgWidth' : 1650,
		'mainImgHeight' : 2550,
		'intNavEnable' : true,
		'intNavPos' : 'B',
		'intNavAutoHide' : false,
		'intNavMoveDownBtt' : true,
		'intNavMoveUpBtt' : true,
		'intNavMoveRightBtt' : true,
		'intNavMoveLeftBtt' : true,
		'intNavZoomBtt' : true,
		'intNavUnzoomBtt' : true,
		'intNavFitToViewportBtt' : true,
		'intNavFullSizeBtt' : true,
		'intNavBttSizeRation' : 1,
		'mapEnable' : true,
		'mapPos' : 'BL',
		'popupShowAction' : 'click',
		'testMode' : false
	};
	
	$('#interactiveMap').lhpGigaImgViewer(settings, 'MyHotspots');
});

$(document).ready(function(){
	$(".mapPopup ul li img").click(function(){

			$( ".visibleSlide img" ).removeClass( "activeThumb" );
			$( ".visibleSlide .thumbs li img" ).addClass( "inactiveThumb" );
			var src = $(this).attr('data-bigImage');
			$(this).removeClass("inactiveThumb");
			$(this).addClass("activeThumb");
			$('.visibleSlide .mainImage img').attr("src", src);

		
	});
	$(".mapPopup .close").click(function(){
		$(".mapPopup").hide("slow");
		$( "div" ).removeClass( "visibleSlide" );
	});
});
$('.menuDropdown').click(function() {
	$('.subMenu').slideToggle();
});