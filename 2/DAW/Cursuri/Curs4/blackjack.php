<?php
	session_start();


	if (!isset($_SESSION["pachet"]))
		$_SESSION["pachet"] = creeazapachet();

    if (!isset($_SESSION["runda"]))
        $_SESSION["runda"] = 1;
    else
        $_SESSION["cntr"]++;

	if (!isset($_SESSION["cntr"]))
		$_SESSION["cntr"] = 0;
	else
		++$_SESSION["cntr"];

	if (!isset($_SESSION["suma_user"]))
		$_SESSION["suma_user"] = 0;

    if (!isset($_SESSION["suma_ai"]))
        $_SESSION["suma_ai"] = 0;

    if (!isset($_SESSION["ok"]))
        $_SESSION["ok"] = 0;

    if (!isset($_SESSION["ok1"]))
        $_SESSION["ok1"] = 0;
?>

<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
<form method="post">
<?php
	function creeazapachet()
	{
		$array = array(	array('A_C', 11), array('A_D', 11), array('A_H', 11), array('A_S', 11),
						array('2_C',  2), array('2_D',  2), array('2_H',  2), array('2_S',  2),
						array('3_C',  3), array('3_D',  3), array('3_H',  3), array('3_S',  3),
						array('4_C',  4), array('4_D',  4), array('4_H',  4), array('4_S',  4),
						array('5_C',  5), array('5_D',  5), array('5_H',  5), array('5_S',  5),
						array('6_C',  6), array('6_D',  6), array('6_H',  6), array('6_S',  6),
						array('7_C',  7), array('7_D',  7), array('7_H',  7), array('7_S',  7),
						array('8_C',  8), array('8_D',  8), array('8_H',  8), array('8_S',  8),
						array('9_C',  9), array('9_D',  9), array('9_H',  9), array('9_S',  9),
						array('X_C', 10), array('X_D', 10), array('X_H', 10), array('X_S', 10),
						array('J_C', 10), array('J_D', 10), array('J_H', 10), array('J_S', 10),
						array('Q_C', 10), array('Q_D', 10), array('Q_H', 10), array('Q_S', 10),
						array('K_C', 10), array('K_D', 10), array('K_H', 10), array('K_S', 10));
		shuffle($array);
		return $array;
	}

	function afiseaza_carte()
	{
		$chr1 = substr($_SESSION["pachet"][$_SESSION["cntr"]][0], 0, 1);
		$chr2 = substr($_SESSION["pachet"][$_SESSION["cntr"]][0], 2, 3);
		if ($chr1 == "A")
			echo "Ace of ";
		else
			if ($chr1 == "X")
				echo "10 of ";
			else
				if ($chr1 == "J")
					echo "Jack of ";
				else
					if ($chr1 == "Q")
						echo "Queen of ";
					else
						if ($chr1 == "K")
							echo "King of ";
						else
							echo $chr1." of ";
		if ($chr2 == "C")
			echo "Clubs";
		else
			if ($chr2 == "D")
				echo "Diamonds";
			else
				if ($chr2 == "H")
					echo "Hearts";
				else
					echo "Spades"; 
	}

	function reinitializare()
	{
	    if ($_SESSION["ok1"] == 0)
	    {
            if ($_SESSION["suma_ai"] > $_SESSION["suma_user"])
                echo "Oponentul a castigat";
            else
                if ($_SESSION["suma_ai"] < $_SESSION["suma_user"])
                    echo "Ai castigat!";
                else
                    if ($_SESSION["suma_ai"] == $_SESSION["suma_user"])
                        echo "Egalitate";
        }
        else
            echo "Runda noua?";
		$_SESSION["cntr"] = null; 
		$_SESSION["pachet"] = null;
		$_SESSION["suma_user"] = null;
		$_SESSION["suma_ai"] = null;
        $_SESSION["ok"] = null;
        $_SESSION["ok1"] = null;
        $finish = 1;
	}

	function plusare()
    {
        echo "<br><br>";
        echo "Dvs:";
        echo "<br>";
        afiseaza_carte();
        echo "<br>";
        $_SESSION["suma_user"] = $_SESSION["suma_user"] + $_SESSION["pachet"][$_SESSION["cntr"]][1];
        echo "Suma dvs: ".$_SESSION["suma_user"];
    }

    function sansa_AI()
    {
        if ($_SESSION["suma_ai"] <= 14)
        {
            echo "<br>";
            echo "<br>";
            echo "AI:";
            echo "<br>";
            $_SESSION["cntr"] = $_SESSION["cntr"] + 1;
            afiseaza_carte();
            echo "<br>";
            $_SESSION["suma_ai"] = $_SESSION["suma_ai"] + $_SESSION["pachet"][$_SESSION["cntr"]][1];
            echo "Suma oponentului: ".$_SESSION["suma_ai"];
        }
        else
        {
            $r = rand(0,1);
            if ($r == 1 && $_SESSION["suma_ai"] <= 19)
            {
                echo "<br>";
                echo "<br>";
                echo "AI:";
                echo "<br>";
                $_SESSION["cntr"] = $_SESSION["cntr"] + 1;
                afiseaza_carte();
                echo "<br>";
                $_SESSION["suma_ai"] = $_SESSION["suma_ai"] + $_SESSION["pachet"][$_SESSION["cntr"]][1];
                echo "Suma oponentului: ".$_SESSION["suma_ai"];
            }
            else
            {
                echo "<br><br>";
                echo "AI:";
                echo "<br>";
                echo "Oponentul nu mai pluseaza.";
                echo "<br>";
                echo "Suma oponentului: ".$_SESSION["suma_ai"];
                $_SESSION["ok"] = 1;
            }
        }
    }

    $finish = null;
	$tip = null;
	if (isset($_POST['joaca']))
		$tip = $_POST['joaca'];
	if($tip == "Stop")
		reinitializare();
	if($tip == "Pluseaza")
	{
		echo "<br>";
		echo "Runda: ".$_SESSION["runda"];
        plusare();
        if ($_SESSION["ok"] == 0 && $_SESSION["suma_ai"] <= 19)
            sansa_AI();
        else
        {
            echo "<br><br>";
            echo "AI:";
            echo "<br>";
            echo "Oponentul nu mai pluseaza.";
            echo "<br>";
            echo "Suma oponentului: ".$_SESSION["suma_ai"];
        }

		if ($_SESSION["suma_user"] == 21 && $_SESSION["suma_ai"] == 21)
		{
			echo '<br>';
			echo "Egalitate";
            $_SESSION["ok1"] = 1;
			reinitializare();
		}
		else
			if ($_SESSION["suma_user"] == 21)
			{
				echo '<br>';
				echo "Ai castigat!";
                $_SESSION["ok1"] = 1;
				reinitializare();
			}
			else
                if ($_SESSION["suma_ai"] == 21)
                {
                    {
                        echo '<br>';
                        echo "Oponentul a castigat!";
                        $_SESSION["ok1"] = 1;
                        reinitializare();
                    }
                }
                else
                    if ($_SESSION["suma_ai"] > 21 && $_SESSION["suma_user"] > 21)
                    {
                        echo '<br>';
                        echo "Amandoi ati pierdut!";
                        $_SESSION["ok1"] = 1;
                        reinitializare();
                    }
                    else
                        if ($_SESSION["suma_ai"] > 21)
                        {
                            echo "<br>";
                            echo "Ai castigat!";
                            $_SESSION["ok1"] = 1;
                            reinitializare();
                        }
                        else
                            if ($_SESSION["suma_user"] > 21)
                            {
                                echo "<br>";
                                echo "Ai pierdut!";
                                $_SESSION["ok1"] = 1;
                                reinitializare();
                            }
		
	}
?>
    <br>
    <input type="submit" name="joaca" value="Pluseaza" <?php if ($finish != null) { $finish = null; ?> disabled <?php } ?> >
    <input type="submit" name="joaca" value="Stop">
	</form>
</body>
</html>