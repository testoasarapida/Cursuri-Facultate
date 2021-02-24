<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
	<title>Cursuri</title>
</head>
<body>

<?php
$nr=100;
$cursuri=array();
$idurl=1700;

while($nr>1)
{

	$url = file_get_contents('https://moodle.unibuc.ro/course/index.php?categoryid='.$idurl.'&browse=courses&perpage=1000&');
	$contentcursuri=explode('<div class="coursename">',$url);
	echo count($contentcursuri).'<br/>';

	for($c=1; $c<count($contentcursuri); $c++)
	{
		$urls =explode('href="',$contentcursuri[$c]);

		$links=explode('">',$urls[1]);

		$titluri=explode('">',$contentcursuri[$c]);
		$titlu=explode('</a>',$titluri[1]);

		echo $links[0].' '.$titlu[0].'<br/>';

		$cursuri[count($cursuri)] = array($links[0], $titlu[0]);
		$nr--;
	}
	$idurl++;
}

?>

</body>
</html>