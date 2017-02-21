<!DOCTYPE html>
<html>
<head>
<!-- everything here is 100% free to use as you wish -->
<meta charset="utf-8">

<?php switch ($page->id) {
	case "1078":
		$logoImage = "klq-temp-logo.png";
		$campName  = "Camp Kulaqua";
		$campColor = "#acbc5f";
		$campDarkColor = "#829043";
		$backLinkTop = "121";
		$backLinkLeft = "55";
		$backLink = "1076";
		break;
	case "1683":
		$logoImage = "klq-temp-logo.png";
		$campName  = "Camp Kulaqua Summer Camp";
		$campColor = "#e3892a";
		$campDarkColor = "#b45e23";
		$backLinkTop = "121";
		$backLinkLeft = "55";
		$backLink = "1081";
		break;
	case "1274":
		$logoImage = "pine-lake-logo.png";
		$campName  = "Pine Lake Retreat";
		$campColor = "#7bb6c1";
		$campDarkColor = "#246166";
		$backLinkTop = "129";
		$backLinkLeft = "16";
		$backLink = "1082";
		break;
	case "1067":
		$logoImage = "stillwaters-logo.png";
		$campName  = "Stillwaters Lodge";
		$campColor = "#9d7091";
		$campDarkColor = "#472e57";
		$backLinkTop = "133";
		$backLinkLeft = "33";
		$backLink = "1083";
		break;
	default:
		# code...
		break;
} ?>

<title><?= $page->id ?><?= $campName ?> – Photo Gallery</title>

<!-- styles for this demo -->
<style>
html, body {
	/*background:#111 url(broken_noise.png);*/
	font:13px/1.3 arial, sans-serif;
	height: 100%;
	overflow:hidden;
	margin:0;
	padding:0;
}
html, body,.galleria-container{
	background-color: <?= $campDarkColor?>;
}
.galleria-thumbnails-list,.galleria-thumbnails {
	background-color: <?= $campColor ?>;
}
a {
	color:#823;
	text-decoration:none
}
#container {
	width:100%;
}
#gallery {
	width:100%;
	height:100%;
}
#galleria {
	width:100%;
	height:100%;
	background:#000
}
#loader {
	width:200px;
	height:100px;
	margin:-50px 0 0 -100px;
	position:absolute;
	left:50%;
	top:50%;
	color:#fff;
	text-align:center;
	z-index:4;
	display:none;
	/*background:#000 url('/site/templates/images/fsgallery/loader.gif') no-repeat 50% 25px;*/
	opacity:.8;
	line-height:150px;
	border-radius:6px
}
#menu {
	position:absolute;
	top: 20px;
	right: 10px;
	z-index: 11000;
	background:rgb(76, 110, 34);
	background:rgba(76, 110, 34, 0.61);
	padding: 5px 5px 4px;
	border-radius: 5px;
	border: 1px solid #fff;
}
#menu ul {
	list-style: none outside;
	margin:0;
	padding:0;
}
#menu ul a {
	display:block;
	padding: 6px;
	color: white;
}
#menu ul a:hover {
	background:#151515;
	background:#43601e;
	background:rgba(0, 0, 0, .1);
}
#menu a.active {
	background:#111;
	background:#43601e;
	background:rgba(0, 0, 0, .3);
	color:#fff
}
#menu p {
	color:white;
	width: 122px;
	margin:0;
	padding:3px 0px 0;
	cursor: pointer;
	text-align: center;
}
.logo {
	position:absolute;
	z-index:11200;
	top:10px;
	left:20px;
}
.logo img{
}
a.backToWebsite {
	position: absolute;
	top: <?= $backLinkTop?>px;
	left: <?= $backLinkLeft?>px;
	font-weight: bold;
	color: white;
	text-shadow: 1px 1px 1px black;
}
#playToggle {
	position:absolute;
	left:-70px;
	background:url('/site/templates/images/fsgallery/playPause.gif') no-repeat left top;
	text-align:center;
	width:57px;
	height: 57px;
	padding: 0 !important;
	text-indent: -999em;
	border-radius: 5px;
	top: 0;
}
#playToggle.play {
	background:url('/site/templates/images/fsgallery/playPause.gif') no-repeat left bottom;
}


</style>
<!-- load jQuery -->
<script src="http://ajax.googleapis.com/ajax/libs/jquery/1/jquery.min.js"></script>

<!-- load Galleria -->
<script src="<?= $config->urls->templates?>scripts/galleria-1.2.8.min.js"></script>

<!-- load flickr plugin -->
<script src="<?= $config->urls->templates?>scripts/plugins/flickr/galleria.flickr.min.js"></script>
</head>
<body>


<div class="logo"> <a href="<?= $pages->get($backLink)->url ?>"><img src="<?= $config->urls->templates?>images/logos/<?= $logoImage ?>" alt="<?= $campName ?>" /> </a><a href="<?= $pages->get($backLink)->url ?>" class="backToWebsite">&laquo; back to website</a> </div>
<!-- end logo-->
<div id="menu"> <a href="#" id="playToggle" class="pause">Pause Slide-Show</a>
	<p><img src="<?= $config->urls->templates?>images/fsgallery/selectGallery.gif" alt="Select Photo Gallery" /></p>
	<ul>
		<?php foreach ($page->fs_albums as $album): ?>
		<li><a href="<?= $album->flickr_url?>"><?= $album->title?></a></li>
		<?php endforeach ?>
		
	</ul>
	
</div>
<!-- end #menu-->
<div id="container">
	<div id="gallery">
		<div id="galleria"></div>
	</div>
</div>
<!-- end #container--> 
<script>

        // load the theme
        Galleria.loadTheme('/site/templates/scripts/js/themes/fullscreen/galleria.fullscreen.min.js');

        // create a flickr instance
        var flickr = new Galleria.Flickr();

        // cache the gallery
        var elem = $('#galleria');
        // create and append the loader growl
        var loader = $('<div>', {
            id: 'loader'
        }).appendTo('#gallery');

        // a local var used later
        var set;

        // set flickr to fetch description and increase the photo limit
        flickr.setOptions({
            max: 100,
            description: true
        });

        // attach event handler for the menu
        $('#menu ul a').click(function(e) {
				
        	Galleria.configure({
    			_hideDock: false,
    			transition: 'fade',
    			autoplay: 4000,
    			transitionSpeed: 1000,
    			pauseOnInteraction: true,
    			showInfo: false,
    			responsive: true,
    			initialTransition: 5000,
    			imageCrop: 'landscape'
			});
		
            e.preventDefault();

            // toggle active class
            $('#menu a').removeClass('active');
            $(this).addClass('active')
            $('#menu ul').slideUp();

            // extract the set id from the link href
            set = this.href.split('/');
            set = set[set.length-2];

            // add loader text and show
            loader.text('Loading '+$(this).text()).show();

            // load the set
            flickr.set(set, function(data) {

                // hide the loader
                loader.fadeOut('fast');

                // check if galleria has been initialized
                if (elem.data('galleria')) {

                    // load galleria with the new data
                    elem.data('galleria').load( data );

                // else initialize galleria (1st time)
                } else {
                    elem.galleria({

                        // add the data as dataSource
                        dataSource: data                
                    });
                }
            });
             
        });


		$('#menu p').click(function(){
			$('#menu ul').slideToggle();
		});
        // trigger a click onload so that the first gallery will be displayed when entering

            <?php if (isset($_GET['id']) && $_GET['id'] == 'alumni') : ?>
				$("#menu ul li a").each(function(){

			        if($(this).text().match("Alumni")){
			            $(this).click();
			        }
			    });
			<?php else: ?>

				$('#menu li:first a').click();
				
			<?php endif?>


        
        $('#menu ul').slideUp();
        
         var playing = true;
         
        $('#playToggle').click(function() {
			$(this).toggleClass("play");
        	if (playing == true) {
        		$(this).text("Play Slide-Show");
        		$('#galleria').data('galleria').pause();
        		playing = false;	
        	}else{
        		$(this).text("Pause Slide-Show");
        		$('#galleria').data('galleria').play();
        		playing = true;
        	};	
        	return false;
		});
		

		$(window).resize(function() {
    		 window.location.href = window.location.href;
		});
 
    </script>

</body>
</html>