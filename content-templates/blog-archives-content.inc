<?php 

/**
 * Archives template
 *
 */

/**
 * Get an array of archives, optionally by year and optionally including a few posts
 *
 * @param int $year Retrieve archives for a specific year (default=retrieve all years)
 * @param int $limit Max number of posts to show for each month, default=0 which means don't show any
 * @return array() in this format:
 *
 * array(
 * 	2012 => array( // year 2012
 *		1 => array( // month 1: January
 * 			'name' => 'January', 
 *			'url' => '/archives/2012/01/',
 *			'posts' => PageArray, // containing first few posts
 *			'total' => 5 // total # of posts in month
 *		),
 *		2 => array( // Month 2: February
 *			'name' => 'February',
 *			...and so on
 *		),
 *		...and so on
 * 	),
 * 
 * 	2011 => array( ... ), // year 2011
 *	...and so on
 * );
 *
 */


/**
 * Render archives returned by the getArchives() function
 *
 * Archives links include a year headline followed by a list of months in that year with posts,
 * and the number of posts in each month. 
 *
 * @param array $years as returned by the getArchives() function
 * @return string
 *
 */
function renderArchives(array $years) {
	$out = '';

	foreach($years as $year) {
		$t = new TemplateFile(wire('config')->paths->templates . 'markup/archives.php'); 
		$t->set('year', $year['name']); 
		$t->set('total', $year['total']); 
		$t->set('months', $year['months']); 
		$t->set('url', $year['url']); 
		$out .= $t->render();
	}

	return $out; 
}



/*******************************************************************/

include_once("./includes/blog.inc");

if($input->urlSegment1 && $input->urlSegment2) {
	// year and month
	$year = (int) $input->urlSegment1; 
	$month = (int) $input->urlSegment2; 
	$firstDate = strtotime("$year-$month-01");
	$lastDate = strtotime("+1 month", $firstDate);
	$selector = "template=blog-post, date>=$firstDate, date<$lastDate, sort=-date";
	$posts = $pages->find($selector);
	$headline = strftime("%B %Y", $firstDate);
	$content = renderPosts($posts, true);
	echo '<h1>Archives for '.$headline.' </h1>'.$content;
	$archives = getArchives();
	$yearsNav = array();
	$monthsNav = array();

	foreach($archives as $y) {
		$yearsNav[$y['url']] = $y['name'];
		if($y['name'] == $year) {
			foreach($y['months'] as $m) $monthsNav[$m['url']] = $m['name'];
		}
	}

	

} else if($input->urlSegment1) {
	echo "<h1>Archives</h2>";
	// year
	$year = (int) $input->urlSegment1; 
	$headline = $page->title;
	$archives = getArchives();
	$yearsNav = '';
	foreach($archives as $key => $y) {
		$yearsNav[$y['url']] = $y['name']; 
		if($key != $year) unset($archives[$key]); 
	}
	$content = renderArchives($archives); 
	echo $content;
} else {
	echo "<h1>Archives</h2>";
	// root, no date specified
	$headline = $page->title;
	$content = $page->body . renderArchives(getArchives()); 
	echo $content;
}

