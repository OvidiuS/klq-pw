<div class="contentWrapper">

	<div class="headerWrapper">
		<a href="/" class="logo">Camp Kulaqua</a>
		<p>Top Menu:</p>
		<?php $topMenuPages = $pages->get(1015)->top_menu_pages;?>
		<ul class="topMenu">
			
			<?php 
			foreach ($topMenuPages as $item) {

				
				$class = ( $item === $page || ($page->parents->has($item) &&  $item->id != 1) ) ?' class="active"' : "";
				
					
				echo "<li{$class}><a href='{$item->url}'>{$item->title}</a></li>";

			}?>
		</ul>
		<!-- /.topMenu -->
	</div>



	



	<div class="sidebarWrapper">
			<?php 
	$mainMenuItems = $page->rootParent->children();
	if (count($mainMenuItems) != 0 && $page->id != 1): ?>
		
	<p>Main Menu</p>
	<ul class="subMenu">
		<?php foreach ($mainMenuItems as $item) {
		 	$class = ($page->parents->has($item) || $page === $item) ? ' class="active"' : "";
			echo "<li{$class}><a href='{$item->url}'>{$item->title}</a></li>";
		} ?>
	</ul>
	<!-- /.mainMenu -->
	<?php endif ?>

	</div>
	<!-- /.sidebarWrapper -->


	<div class="mainContentWrapper">
		<h1 class="mainHeading"><?php echo $page->get("headline|title"); ?></h1>
		<?= $page->body ?>
	</div>
	<!-- /.mainContentWrapper -->

</div>
<!-- /.contentWrapper -->