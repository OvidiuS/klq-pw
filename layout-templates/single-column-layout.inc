<div class="contentOuterWrapper">
<div class="contentWrapper">
	
	<?php include($config->paths->templates."includes/main-menu.inc") ?>


	<div class="mainContentWrapper singleColumn">
		<h1 class="mainHeading"><?php echo $page->get("headline|title"); ?></h1>		
		<?php include($contentTemplateName); ?>
		
	</div>
	<!-- /.mainContentWrapper -->
	
</div>
<!-- /.contentWrapper -->
</div>
<!-- /.contentOuterWrapper -->