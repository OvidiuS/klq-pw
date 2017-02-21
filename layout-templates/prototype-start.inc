<div class="contentWrapper">

<?php 
$pageLevel = count($page->parents);
if ($pageLevel >= 2 && $page->numChildren(true)): ?>

	<div class="sidebarWrapper">
		<p>Sub-pages:</p>
		<?php
			
			if ($pageLevel == 2) {
				$sideMenuParent = $page;
			}elseif($pageLevel == 3){
				$sideMenuParent = $page->parent;
			}

			$subMenuOptions = array(
				'outer_tpl' => '<ul class="subMenu">||</ul>',
				'current_class' => 'active',
				'inner_tpl' => '<ul class="subMenuSecondLvl">||</ul>',
				'item_tpl' => '<a href="{custom_url|url}">{title}</a>'
				);
			$subMenu = $modules->get("MarkupSimpleNavigation"); // load the module
			echo $subMenu->render($subMenuOptions, null, $sideMenuParent); // render default menu
		?>
		<!-- /.subMenu -->

	</div>
	<!-- /.sidebarWrapper -->
<?php endif ?>

	<div class="mainContentWrapper">
		<h1 class="mainHeading"><?php echo $page->get("headline|title"); ?></h1>
		
		<?php if ($page->body != ""): ?>
		<?= $page->body ?>
		<?php else :?>
		<p><strong>This page has yet to have any content added. When you add some it will be displayed here. Meanwhile, here is some placeholder text.</strong></p>

		<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. In feugiat consectetur metus, eget ultricies tellus consequat vitae. Etiam dui libero, euismod vel nisl a, placerat elementum nisi. Aliquam erat volutpat.</p> 

		<p>Sed dolor orci, luctus at blandit id, sagittis ac nibh. Suspendisse et adipiscing velit, eu sodales ante. Vestibulum purus sapien, lacinia ac iaculis sed, ultricies et magna. Vivamus auctor enim vitae purus viverra, ac aliquet mauris tempor. Ut a adipiscing tellus, ac consectetur tortor. Mauris mattis, est at tincidunt rutrum, arcu justo interdum mi, sed posuere leo elit eu erat.</p> 

		<p>Suspendisse enim lacus, vehicula vel ante id, consequat auctor neque. Vestibulum in magna eu arcu euismod semper. Fusce ultricies sit amet nulla id varius.</p>
		<?php endif ?>
		
	</div>
	<!-- /.mainContentWrapper -->

</div>
<!-- /.contentWrapper -->