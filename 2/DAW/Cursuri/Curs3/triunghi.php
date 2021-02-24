<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
	<title>Triunghi</title>
</head>
<body>

<?php 
	$nr = $_POST["numar"];
	if($nr <= 0 || is_numeric($nr) != 1)
		echo "nevalid";
	else
	{	
		$contor = 1;
		$cc = 1;
		while ($cc <= $nr)
		{
			for ($j = 1; $j <= $contor && $cc <= $nr; $j++)
			{
				echo $cc." ";
				$cc++;
			}
			echo '<br>';
			$contor++;
		}
	}
?>

</body>
</html>
