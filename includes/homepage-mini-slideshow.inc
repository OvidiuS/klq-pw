<div class="homepageMiniSlideshow cycle-slideshow" 
	data-cycle-fx="fade"
    			data-cycle-pause-on-hover="true"
    			data-cycle-speed="1000"
    			data-cycle-slides="> div.slide"
    			data-timeout="3000"
 	data-cycle-prev="div.homepageMiniSlideshowNavigation a.prev"
 	data-cycle-next="div.homepageMiniSlideshowNavigation a.next"
 >
<?php foreach ($page->homepage_mini_carousel as $slide): ?>
	<div class="slide">
					
		<?php if ($slide->slide_link == ""): ?>
			<img src="<?= $slide->homepage_slide_image->getCrop("homepage-mini-slideshow-size")->url ?>" alt="<?= $slide->homepage_slide_image->description?>">
			<span><?= $slide->homepage_slide_image->description?></span>
		<?php else: ?>
			<a href="<?= $slide->slide_link?>">
				<img src="<?= $slide->homepage_slide_image->getCrop("homepage-mini-slideshow-size")->url ?>" alt="<?= $slide->homepage_slide_image->description?>">
				<span><?= $slide->homepage_slide_image->description?></span>
			</a>
		<?php endif ?>

	</div>
<?php endforeach ?>
</div>
<!-- /.homepageMiniSlideshow -->