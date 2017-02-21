	<div class="homepageSlideshowWrapper">
		<div class="homepageSlideshow cycle-slideshow" 
    			data-cycle-fx="fade"
    			data-cycle-pause-on-hover="true"
    			data-cycle-speed="1000"
    			data-cycle-slides="> div.slide"
    			data-timeout="3000"
    			data-cycle-prev="div.homepageSlideshowNavigation a.prev"
    			data-cycle-next="div.homepageSlideshowNavigation a.next"
    			>
			<?php foreach ($page->homepage_carousel as $slide): ?>
				<div class="slide">
					
					<?php if ($slide->slide_link == ""): ?>
						<img src="<?= $slide->homepage_slide_image->getCrop("homepage-slideshow-size")->url ?>" alt="<?= $slide->homepage_slide_image->description?>">
						<span><?= $slide->homepage_slide_image->description?></span>
					<?php else: ?>
						<a href="<?= $slide->slide_link?>">
							<img src="<?= $slide->homepage_slide_image->getCrop("homepage-slideshow-size")->url?>" alt="<?= $slide->homepage_slide_image->description?>">
							<span><?= $slide->homepage_slide_image->description?></span>
						</a>
					<?php endif ?>

					
				</div>
			<?php endforeach ?>
		</div>
		<!-- /.homepageSlideshow -->
		<div class="homepageSlideshowNavigation">
		  <a class="btn prev"><</a>
		  <a class="btn next">></a>
		</div>
		<!-- /.customNavigation -->
	</div>
	<!-- /.homepageSlideshowWrapper -->