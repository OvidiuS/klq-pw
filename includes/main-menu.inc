<?php 
		$mainMenuItems = $page->rootParent->children();
		$mainMenuItems->prepend($page->rootParent);
		if (count($mainMenuItems) != 0 && $page->id != 1): ?>

		<div class="MainMenuWrapper">
			<ul class="mainMenu">

				<?php 
				$first = true;
				foreach ($mainMenuItems as $item) {
					if ($first) {
						$pageName = "Home";
						$first = false;
						$class = ($page === $item) ? ' class="active"' : "";
					}else{
						$pageName = $item->title;
						$class = ($page->parents->has($item) || $page === $item ) ? ' class="active"' : "";
					}
					echo "<li{$class} id='item-{$item->id}'><a href='{$item->url}'><span>{$pageName}</span></a></li>";
				} ?>
			</ul>
			<!-- /.mainMenu -->
			<div class="menuBannerLeft"></div>
			<div class="menuBannerRight"></div>
		</div>
		<!-- /.MainMenuWrapper -->
		<?php endif ?>