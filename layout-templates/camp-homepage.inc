<div class="contentOuterWrapper klqRetreatBg">
<div class="contentWrapper">
	
	<?php include($config->paths->templates."includes/main-menu.inc") ?>

	<?php include($config->paths->templates."includes/homepage-slideshow.inc"); ?>

	<div class="homepageText">
		<h1><?= $page->get("headline|title");?></h1>	
		<?= $page->body?>
	</div>
	<!-- /.homepageText -->
	
	<div class="homePageRightColumn">

		<div class="campCountdownWrapper">
			<p class="countDown">
			<?php
				$calculation = (($page->countdown_date - time('void'))/3600);
				$hours = (int)$calculation;
				$days  = (int)($hours/24);
				if ($days >= 0) { echo $days ; }else{echo "0";}
			?>
			<?= $days==1 ? "day" : "days" ?><span><br />to camp opening</span></p>
		</div>
		<div class="clear"></div>
		<div class="retreatHomepageMiniSlideshowWrapper">

			<?php include($config->paths->templates."includes/homepage-mini-slideshow.inc"); ?>

			<div class="homepageMiniSlideshowNavigation">
			  <a class="btn prev"><</a>
			  <a class="btn next">></a>
			</div>
			<!-- /.customNavigation -->
		</div>
		<!-- /.homepageSlideshowWrapper -->
	</div>
	<!-- end .homePageRightColumn -->
	
</div>
<!-- /.contentWrapper -->
</div>
<!-- /.contentOuterWrapper -->