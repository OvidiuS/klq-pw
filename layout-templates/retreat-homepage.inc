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
		<div class="retreatHomepageMiniSlideshowWrapper">
			
			<?php include($config->paths->templates."includes/homepage-mini-slideshow.inc"); ?>
			
			<div class="homepageMiniSlideshowNavigation">
			  <a class="btn prev"><</a>
			  <a class="btn next">></a>
			</div>
			<!-- /.customNavigation -->
		</div>
		<!-- /.homepageSlideshowWrapper -->
		
		<div class="retreatHomepageBlogFeed">
			<h2>What's <span>New?</span></h2>
			
			<?php foreach ($pages->find("parent=1692,limit=2,sort=-date") as $blogPost): ?>
			<div class="newsItem">
				<?php if ($blogPost->blog_featured_image): ?>
					<a href="<?= $blogPost->url ?>">
					<img src="<?= $blogPost->blog_featured_image->getCrop("thumbnail")->url ?>" alt="$blogPost->blog_featured_image->description" />
					</a>
				<?php else: ?>
					<a href="<?= $blogPost->url ?>"><img src="http://placehold.it/89x83" alt="" /></a>
				<?php endif ?>
				
				<div class="newsItemContent">
					<h3><a href="<?= $blogPost->url ?>"><?= date("F jS",$blogPost->getUnformatted('date')) ?> - <?= $blogPost->title ?></a></h3>
					<p><?= $blogPost->summary ?></p>
				</div>
				<!-- /.newsItemContent -->
			</div>
			<!-- /.newsItem -->
			<?php endforeach ?>

		</div>
		<!-- /.retreatHomepageBlogFeed -->
	</div>
	<!-- end .homePageRightColumn -->
	
</div>
<!-- /.contentWrapper -->
</div>
<!-- /.contentOuterWrapper -->