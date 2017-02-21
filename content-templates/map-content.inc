<div class="introduction">
<?= $page->summary; ?>
</div>


<div class="headerImageWrapper">
<div class="headerImageWrapper02">
<div class="headerImageWrapper03">
<div class="headerImageWrapper04">
	<!-- viewer container -->
	<div id="interactiveMap" style="width:100%; height:598px; overflow:hidden; border:solid 1px #a6a6a6; background:#000;"></div>

	<!-- hotspots container -->
	<div id="MyHotspots" style="display:none;">		
		<!-- hotspot -->

		<?php
		$locations  = $pages->find("template=map-location");
		foreach($locations as $map_objective): ?>
			<div class="lhp_giv_hotspot" data-x="<?= $map_objective->x_pos ?>" data-y="<?= $map_objective->y_pos ?>" data-visible-scale="0">
				<!-- marker -->
				<div class="lhp_giv_marker pos-BR">
					<div class="<?php 
						echo str_replace(" ", "_",preg_replace("/(?![-])\p{P}/u", "", $map_objective->title));
					?>">
						<div class="label"><?= $map_objective->title ?></div>
					</div>
				</div>
				<!-- pop-up -->
				<div class="lhp_giv_popup pos-R">
				</div>
			</div>
			<!-- end hotspot -->
		<? endforeach; ?>		
		
		
	<!-- hotspot -->
	</div>
</div></div></div></div>
<?php foreach($locations as $map_objective): ?>
<div id="<?php 
						echo str_replace(" ", "_",preg_replace("/(?![-])\p{P}/u", "", $map_objective->title));
					?>" style="display: none;" class="mapPopup">
	<div class="contentPopup">
		<div class="close"></div>
		<div class="mainImage">
				<img src="<?= $map_objective->objective_images->first() ? $map_objective->objective_images->first()->getCrop('main_image')->url : "http://placehold.it/400x400"; ?>"  alt="" />
				<div class="locationDescription">
						<h3><?= $map_objective->title ?></h3>
						<?= $map_objective->objective_description ?>
								
				</div>
		</div>
		<ul class="thumbs">
		<?php foreach($map_objective->objective_images as $objective_image): ?>	
				<li><img src="<?= $objective_image->getCrop('thumbnail')->url ?>" data-bigImage="<?=$objective_image->getCrop('main_image')->url ?>" alt="" />
				</li>
			<? endforeach; ?>				
			</ul>			
			<div style="clear: both;"></div>
	</div>
</div>

<? endforeach; ?>	