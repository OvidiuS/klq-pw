					<?php include_once("./includes/blog.inc");  ?>

					<h1><?= $page->get("headline|title");?></h1>
					<?php $posts = $pages->get("1692")->children; 	 ?>

						<?= renderPosts($posts,true); ?>
					


					