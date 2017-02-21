<div class="contentOuterWrapper">
<div class="contentWrapper">
	<h1 class="landingPageTitle"><?= $page->headline ?></span></h1>
	<h2 class="landingPageSubTitle"><?= $page->headline_span ?></h2>
	<div class="landingPageIntro"><?= $page->homepage_summary ?>

	<p><?= $page->homepage_intro ?></p></div>
	<ul class="landingPageLocationLinks">
		<li class="campKulaqua">
			<a href="<?= $pages->get(1010)->url;?>">
			<img src="<?= $page->homepage_kulaqua_thumb->getCrop("thumbnail")->url ?>" alt="Camp Kulaqua"/>
				<span>Camp Kulaqua</span>
			</a>
		</li>
		<li class="campKulaquaSummerCamp">
			<a href="<?= $pages->get(1011)->url;?>">
				<img src="<?= $page->homepage_kulaqua_summercamp_thumb->getCrop("thumbnail")->url; ?>" alt="Camp Kulaqua's Summer Camp"/>
				<span>Camp Kulaqua’s Summer Camp</span>
			</a>
		</li>
		<li class="pineLakes">
			<a href="<?= $pages->get(1014)->url;?>">
				<img src="<?= $page->homepage_pine_lake_thumb->getCrop("thumbnail")->url; ?>" alt="Pine Lake Retreat"/>
				<span>Pine Lake Retreat</span>
			</a>
		</li>
		<li class="stillWatersLodge">
			<a href="<?= $pages->get(1013)->url;?>">
				<img src="<?= $page->homepage_stillwater_thumb->getCrop("thumbnail")->url; ?>" alt="Stillwaters Lodge"/>
				<span>Stillwaters Lodge</span>
			</a>
		</li>
		<li class="last riverRanchWaterPark">
			<a href="<?= $pages->get(1095)->url;?>">
				<img src="<?= $page->homepage_river_ranch_thumb->getCrop("thumbnail")->url; ?>" alt="River Ranch Water Park"/>
				<span>River Ranch Water Park</span>
			</a>
		</li>
	</ul>
	<div class="landingMapWrapper">
		<img src="<?= $config->urls->templates?>images/landingPage/landing-page-new-mapv1.jpg" alt="">
	</div>
	<!-- /.landingMapWrapper -->
</div>
<!-- /.contentWrapper -->
</div>
<!-- /.contentOuterWrapper -->