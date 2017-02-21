
<div class="footerOuterWrapper">
<div class="footerInnerWrapper">
<div class="footerWrapper">

	<div class="footerLeft">
		<p class="footerTitle">Get <span>In Touch</span></p>
		<p class="footerAddress">23400 NW 212 Ave. | High Springs, FL 32643 </p>
		<p class="footerPhone">Phone: 386.454.1351</p>
		
		 <!-- (facebook, twitter, Youtube, Vimeo) -  they will not all be visible for all sections: 1 - FB+Blog+Vimeo; 2 - FB,Twitter,YT;  3 - FB+Blog; 4 - Nothing. </p> -->
		
		<p>
			<?php if ($page->rootParent == "1011" || $page->rootParent == "1010" || $page->id == 1): ?>
				<img src="<?= $config->urls->templates?>images/aca_logo.png" alt="ACA Logo"/>
			<?php endif ?>
			<img src="<?= $config->urls->templates?>images/footer/aacp-logo-white.png" alt="AACP logo"/>
		</p>

	</div>
	<!-- /.footerLeft -->
	
	<div class="footerCenter">
		<p class="footerTitle">Subscribe to <span>Our Newsletter</span></p>
		<div class="newsletterFormOuterWrapper">
			
			<div class="newsletterFormWrapper">
				
				<div class="newsletterForm">
				<p>Click on the button below to subscribe to our newsletter.</p>
				<!-- 	<form action="#">
						<label for="email">
							<input type="text" name="email" id="email_field"/>
						</label>
						<button type="submit" class="submitBtn">Subscribe</button>
					</form> -->
					<a href="https://secure.campaigner.com/CSB/Public/Form.aspx?fid=656315" class="submitBtn">Subscribe</a>
				</div>
				<!-- /.newsletterForm -->

			</div>
			<!-- /.newsletterFormWrapper -->

		</div>
		<!-- /.newsletterFormOuterWrapper -->
	</div>
	<!-- /.footerCenter -->

	<div class="footerRight">
		<p class="footerTitle">Site <span>Map</span></p>
		<ul class="footerMenu">
			
			<?php foreach ($topMenuPages as $item) {
			 	$class = ($page->parents->has($item) || $page === $item) ? ' class="active"' : "";
				echo "<li{$class} id='footer-page-{$item->id}'><a href='{$item->url}'>{$item->title}</a></li>";
			} ?>
		</ul>

	</div>
	<!-- /.footerRight -->

		<?php 

		// If the page is editable, then output a link that takes us straight to the page edit screen:
		if($page->editable()) {
			echo "<a style='position:absolute;top:3px;left:3px;' id='editpage' href='{$config->urls->admin}page/edit/?id={$page->id}'>Edit</a>"; 
		}

		?>
</div>
<!-- /.footerWrapper -->
</div>
<!-- /.footerInnerWrapper -->
</div>
<!-- /.footerOuterWrapper -->
<div class="footerBottomOuter">
<div class="footerBottom">
	<p class="footerCopyright">Copyright &copy; <?= date("Y");?> Camp Kulaqua - Camp & Retreat Center<!--<a href="#">Terms & Conditions</a>   |   <a href="#">Privacy Statement</a>--><?= $page->rootParent->id == "1011" ? ' | <a href="#">Alumni</a>' : ''?><br/><a href="http://www.dvscampwebsites.com/">Camp website by DVS Camp Websites</a></p>

	<div class="socialMediaWrapper">
		<p>
		<?php if($page->id == "1" || $page->rootParent == "1003"): // home page ?>
		<a href="https://www.facebook.com/campkulaqua" class="facebook">Facebook</a>
		<a href="https://twitter.com/SeeuatKulaqua" class="twitter">Twitter</a>
		<a href="https://www.youtube.com/user/TheTheresaification" class="youtube">YouTube</a>
		<a href="https://vimeo.com/user16465596" class="vimeo">Vimeo</a>
		<?php elseif($page->rootParent->id == "1010"): // 1st section ?>
		<a href="https://vimeo.com/user16465596" class="vimeo">Vimeo</a>
		<a href="https://www.facebook.com/campkulaqua" class="facebook">Facebook</a>
		<a href="<?= $pages->get("1003")->url ?>" class="blog">Blog</a>
		<?php elseif($page->rootParent->id == "1011"):// 2nd section ?>
		<a href="https://www.facebook.com/campkulaqua" class="facebook">Facebook</a>
		<a href="https://twitter.com/SeeuatKulaqua" class="twitter">Twitter</a>
		<a href="https://www.youtube.com/user/TheTheresaification" class="youtube">YouTube</a>
		<?php elseif($page->rootParent->id == "1014"):// 3rd section ?>
		<a href="<?= $pages->get("1003")->url ?>" class="blog">Blog</a>
		<a href="https://www.facebook.com/campkulaqua" class="facebook">Facebook</a>
		
		<?php elseif($page->rootParent->id == "1013"):// 4th section ?>
		
		<?php endif; ?>
		</p>
		<p style="clear:both">Camp Kulaqua Retreat Center</p>
	</div>
	<!-- /.socialMediaWrapper -->
	<div class="clear"></div>

	

</div>
<!-- /.footerBottom -->
</div>
<!-- /.footerBottomOuter -->
</div>
<!-- /.page -->

<script src="<?= $config->urls->templates?>scripts/jquery-1.9.1.min.js"></script>

<!-- giv js files -->
		<script src="<?php echo $config->urls->templates?>scripts/jquery.fancybox.pack.js"></script>
        <script src="<?php echo $config->urls->templates?>scripts/jquery.fancybox-media.js"></script>
		<!-- jQuery ui -->
		<script src="<?= $config->urls->templates?>scripts/giv/jquery-ui-1.10.3.custom.min.js"></script>
		<!-- jQuery easing plugin-->
		<script src="<?= $config->urls->templates?>scripts/giv/jquery.easing.1.3.js"></script>
		<!-- jQuery mousewheel plugin-->
		<script src="<?= $config->urls->templates?>scripts/giv/jquery.mousewheel.min.js"></script>
		<!-- lhpGigaImgViewer plugin -->
		<script  src="<?= $config->urls->templates?>scripts/giv/jquery.lhpGigaImgViewer.js"></script>
		<!-- swfobject -->
		<script  src="<?= $config->urls->templates?>scripts/giv/swfobject.js"></script>
		<!-- preview js code
		<script type="text/javascript" src="'. $config->urls->templates.'js/giv/preview1.js"></script> -->

<script src="<?= $config->urls->templates?>scripts/jquery.cycle2.min.js"></script>
<script src="<?= $config->urls->templates?>scripts/plugins.js"></script>
<script src="<?= $config->urls->templates?>scripts/scripts.js"></script>


<script>

	(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){

	(i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),

	m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)

	})(window,document,'script','//www.google-analytics.com/analytics.js','ga');

	ga('create', 'UA-53389817-1', 'auto');

	ga('send', 'pageview');

</script>

<!-- Please call pinit.js only once per page -->
<script type="text/javascript" async  data-pin-color="red" data-pin-height="28" data-pin-hover="true" src="//assets.pinterest.com/js/pinit.js"></script>


<!-- Google Code for Remarketing Tag -->

<script type="text/javascript">

/* <![CDATA[ */

var google_conversion_id = 977070022;

var google_custom_params = window.google_tag_params;

var google_remarketing_only = true;

/* ]]> */

</script>

<script type="text/javascript" src="//www.googleadservices.com/pagead/conversion.js">

</script>

<noscript>

<div style="display:inline;">

<img height="1" width="1" style="border-style:none;" alt="" src="//googleads.g.doubleclick.net/pagead/viewthroughconversion/977070022/?value=0&guid=ON&script=0"/>

</div>

</noscript>

<?php if ($page->id == "1651" || $page->id == "1652" ): ?>
<!-- Google Code for Conversion Conversion Page -->

<script type="text/javascript">

/* <![CDATA[ */

var google_conversion_id = 977070022;

var google_conversion_language = "en";

var google_conversion_format = "3";

var google_conversion_color = "ffffff";

var google_conversion_label = "c8okCLqzzgoQxs_z0QM";

var google_remarketing_only = false;

/* ]]> */

</script>

<script type="text/javascript" src="//www.googleadservices.com/pagead/conversion.js">

</script>

<noscript>

<div style="display:inline;">

<img height="1" width="1" style="border-style:none;" alt="" src="//www.googleadservices.com/pagead/conversion/977070022/?label=c8okCLqzzgoQxs_z0QM&guid=ON&script=0"/>

</div>

</noscript>
<?php endif ?>

<?php if ($pages->get("1")->fb_pixel != ""): ?>
	<?= $pages->get("1")->fb_pixel ?>
<?php endif ?>