<div class="page">
	<!-- //////////// -->
	<!-- HEADER START -->
	<div class="boom_bar">
		<a href="http://www.kulaqua.com/" target="_blank">Click here for Kulaqua's Retreat and Conference Center</a>
	</div>
	<div class="headerOuterWrapper">
	<div class="headerWrapper">

		<a href="/" class="headerLogo">
		<?php if ($page->rootParent == "1" || $page->rootParent == "1010" || $page->rootParent == "1003"): ?>
			<img src="<?= $config->urls->templates?>images/logos/klq-temp-logo.png" alt="Christian Retreat and Conference Center" />
		<?php elseif ($page->rootParent == "1011"): ?>
			<img src="<?= $config->urls->templates?>images/logos/klq-temp-logo.png" alt="Florida summer camp" />
		<?php elseif ($page->rootParent == "1014"): ?>
			<img src="<?= $config->urls->templates?>images/logos/pine-lake-logo.png" alt="Pine Lake Retreat" />
		<?php elseif ($page->rootParent == "1013"): ?>
			<img src="<?= $config->urls->templates?>images/logos/stillwaters-logo-transparent.png" alt="Florida Conference Center" />
		<?php endif ?>

		</a>

		<div class="headerRight">

			<!-- NAVIGATION START -->
<?php $topMenuPages = $pages->get(1015)->top_menu_pages;?>
			<ul class="topMenu">

				<li id="retreats" ><a href="<?= $pages->get('/')->url ?>"><span>Kulaqua <br> Retreat Centers</span></a>
				</li>
				<li id="camp"><a href="<?= $pages->get('1011')->url ?>"><span>Kulaqua’s <br> Summer Camp</span></a></li>
				<li id="donate"><a href="<?= $pages->get('1031')->url ?>"><span>Make a <br> Donation</span></a></li>

			</ul>
			<!-- /.topMenu -->
			<div class="headerInfo">
				<p class="headerTagline">We provide the opportunities. <span class="headerTaglineItalics">You provide the memories.</span>
				<span class="headerTelNumber">Call us: 386.454.1351</span></p>
			</div>
			<!-- /.headerInfo -->
		</div>
		<!-- /.headerRight -->

		<!-- NAVIGATION END -->
		<!-- ////////////// -->



	</div>
	<!-- /. headerWrapper -->
	</div>
	<!-- /. headerOuterWrapper -->
	<!-- HEADER END -->
	<!-- ////////// -->
