<head>
	<meta http-equiv="content-type" content="text/html; charset=utf-8" />

	<?php if ($page->seo_pageTitle): ?>
<title><?= $page->seo_pageTitle ?></title>
	<?php else:  ?>
<title><?= $page->get("headline|title") ?> | Christian Retreat and Conference Center | North Florida</title>
	<?php endif ?>
	<?php if (isset($options['isFromHomePage']) && $options['isFromHomePage'] == true): ?>
		<link rel="canonical" href="<?= $pages->get('1010')->httpUrl ?>">
	<?php endif; ?>
	<?php

	function wordLimiter($str = '', $limit = 120, $endstr = '...'){

		if($str == '') return '';

		if(strlen($str) <= $limit) return $str;

		$out = substr($str, 0, $limit);
		$pos = strrpos($out, " ");
		if ($pos>0) {
			$out = substr($out, 0, $pos);
		}
		$out .= $endstr;
		return $out;

	}

	$autoMetaDesc = preg_replace('#<[^>]+>#', ' ', $page->get("body"));
	$autoMetaDesc = wordLimiter($autoMetaDesc, 160);
	// All two space-runs to single space runs
	$autoMetaDesc = preg_replace('/\s+/', ' ',$autoMetaDesc);
	// No leading or trailing spaces.
	$autoMetaDesc = trim( $autoMetaDesc );

	if ($page->seo_description != "") {
		echo '<meta name="description" content="'.$page->seo_description.'" />';
	}else{
		echo '<meta name="description" content="'.$autoMetaDesc.'" />';
	}

	?>

	<?= $page->seo_keywords != "" ? '<meta name="keywords" content="'.$page->seo_keywords.'" />' : "" ?>

	<meta name="p:domain_verify" content="326d06d5d8854b9ac52da03afdb604d6"/>
	<meta name="generator" content="ProcessWire <?= $config->version; ?>" />
	<meta name="viewport" content="width=device-width, maximum-scale=1.0, initial-scale=1,  user-scalable=1"/>

	<link rel="apple-touch-icon" href="kulaqua-touch-icon-iphone.png" />
	<link rel="apple-touch-icon" sizes="76x76" href="kulaqua-touch-icon-ipad.png" />
	<link rel="apple-touch-icon" sizes="120x120" href="kulaqua-touch-icon-iphone-retina.png" />
	<link rel="apple-touch-icon" sizes="152x152" href="kulaqua-touch-icon-ipad-retina.png" />

	<link href='http://fonts.googleapis.com/css?family=Bree+Serif' rel='stylesheet' type='text/css'>
	<link href='http://fonts.googleapis.com/css?family=Open+Sans' rel='stylesheet' type='text/css'>
	<!-- <link href='http://fonts.googleapis.com/css?family=Montserrat' rel='stylesheet' type='text/css'> -->

	<link rel="stylesheet" href="<?= $config->urls->templates?>plugins/owl-carousel/owl.carousel.css">
	<link rel="stylesheet" href="<?= $config->urls->templates?>plugins/owl-carousel/owl.theme.css">

	<link rel="stylesheet" type="text/css" href="<?= $config->urls->templates?>styles/giv/main.css" />
	<!-- ColorBox css -->
	<link rel="stylesheet" type="text/css" href="<?= $config->urls->templates?>styles/giv/colorbox.css" />
	<!-- jQuery ThemeRoller -->
	<link rel="stylesheet" type="text/css" href="<?= $config->urls->templates?>styles/giv/custom-theme/jquery-ui-1.10.3.custom.css" />
	<!-- lhpGigaImgViewer plugin css -->
	<link rel="stylesheet" type="text/css" href="<?= $config->urls->templates?>styles/giv/lhp_giv.css" />

	<link rel="stylesheet" type="text/css" href="<?= $config->urls->templates?>styles/main.css" />

	<style>

		.general-section .contentOuterWrapper{
			background-image: url('<?= $pages->get("/")->general_bg->url ?>');
		}
		.campKulaqua-section .contentOuterWrapper{
			background-image: url('<?= $pages->get("/")->bg_kulaqua->url ?>');
		}
		.kulaquaSummerCamp-section .contentOuterWrapper{
			background-image: url('<?= $pages->get("/")->bg_kulaqua_summercamp->url ?>');
		}
		.pineLake-section .contentOuterWrapper{
			background-image: url('<?= $pages->get("/")->bg_pine_lake->url ?>');
		}
		.stillWaters-section .contentOuterWrapper{
			background-image: url('<?= $pages->get("/")->bg_stillwaters->url ?>');
		}
	</style>

</head>
