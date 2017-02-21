
<div class="contentOuterWrapper">
<div class="contentWrapper">
	
		<div class="blogMainColumn">
		
		
			<?php require($contentTemplateName); ?>
			
		
		</div>
		<!--end blogMainColumn--> 

		<div class="blogSideBarColumn">
			<div class='widget'>
							<?php include_once($config->paths->templates.'includes/blog.inc');  ?>
							<?php $limit = 5; 
								$posts = $pages->find("template=blog-post, sort=-date, start=0, limit=$limit");	
								$parent = null;
								$out = '';
								
								foreach($posts as $item) {
									$date = date('d M',strtotime($item->date));
									$out .= "<li><span class='date'>$date</span> <a href='{$item->url}'>{$item->title}</a></li>";
									$parent = $item->parent; 
								}
								
								if($out) {
									$out = 	"<h4>Recent Posts</h4>" . 
										"<ul class='recent-posts links'>$out</ul>" . 
										"<p>" . 
										"<a class='more' href='{$parent->url}'>" . __('More') . "</a> " . 
										"<a class='rss' href='{$parent->url}rss/'>" . __('RSS') . "</a>" . 
										"</p>";
									echo $out; 
								} else {
									echo "<p>No recent posts</p>";
								} 
							?>
						</div>
						<!-- end widget recent posts-->

						<div class='widget'>
						<?php
							echo renderArchivesForSidebar(getArchives());
						?>
						</div>
						<!-- end widget archives-->

						<div class='widget'>
						<?php
							$blogposts = $pages->get( "/blog/posts/" )->children;

							$comments = array();
							
							foreach( $blogposts as $blogpost ) {
							
							    foreach($blogpost->blog_comments as $comment) {
							        if($comment->isApproved()) {
							
							            array_push($comments, array("comment"=>$comment, "post"=>$blogpost));
							
							        }
							    }
							}
							
							if($comments) {
							    $out = "<h4>Latest comments</h4>";
							    $out .= "<ul>";
							
							    arsort($comments);
							
							    $num_comments = 0;
							
							    foreach($comments as $comment) {
							        $cite = htmlentities($comment["comment"]->cite);
							        $text = $summary = strip_tags(substr(htmlentities($comment["comment"]->text), 0, 100)).'...';
							        $date = date("j M 'y ", $comment["comment"]->created);
							        $comment_parent_url = $comment["post"]->url . "#Comment" . $comment["comment"];
									$comment_parent_title = $pages->get($comment["post"]->url)->title;

							        $out .= "<li><span class='sidebarCommentDate'>{$date}</span><a href='{$comment_parent_url}'><span class='sidebarComentTitle'>{$comment_parent_title}</a>";
							        $out .= "<span class='sidebarCommentAuthor'><strong>{$cite}</strong> said: ";
							        $out .= "{$text}</span></li>";
							
							        $num_comments++;
							        if($num_comments == 3) break;
							    }
							
							    $out .= "</ul>";
							    echo $out;
							
							} else {
								echo "<h4>Latest comments</h4>";
							    echo "<p>No comments.</p>";
							}
						?>
						</div>
						<!-- end widget recent comments-->
		</div>
		<!-- /.blogSideBarColumn -->
	
</div>
<!-- /.contentWrapper -->
</div>
<!-- /.contentOuterWrapper -->