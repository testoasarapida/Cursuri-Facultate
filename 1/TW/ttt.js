var x=0;
var y=0;
localStorage.setItem("contor",0);
function selectfield(field)
{
	x=x+1;
	if (field.alt == "unselect")
	{
		nextplayer = document.getElementById("nextplayer").alt;
		if (nextplayer == "player1")
		{
			field.src = "Images/bigdaddy.png";
			field.alt = "player1";
			document.getElementById("nextplayer").src = "Images/littlesister.png";
			document.getElementById("nextplayer").alt = "player2";
		};
		if (nextplayer == "player2")
		{
			field.src = "Images/littlesister.png";
			field.alt = "player2";
			document.getElementById("nextplayer").src = "Images/bigdaddy.png";
			document.getElementById("nextplayer").alt = "player1";
		};
	}
	else
	{
		alert("This part of the sea is choosen by "+field.alt);
	};
	if(x>=5)
	{
		if(((document.getElementById("field11").alt==document.getElementById("field12").alt) && (document.getElementById("field12").alt==document.getElementById("field13").alt) && (document.getElementById("field13").alt=="player1")) || ((document.getElementById("field21").alt==document.getElementById("field22").alt) && (document.getElementById("field22").alt==document.getElementById("field23").alt) && (document.getElementById("field23").alt=="player1")) || ((document.getElementById("field31").alt==document.getElementById("field32").alt) && (document.getElementById("field32").alt==document.getElementById("field33").alt) && (document.getElementById("field33").alt=="player1")) || ((document.getElementById("field11").alt==document.getElementById("field21").alt) && (document.getElementById("field21").alt==document.getElementById("field31").alt) && (document.getElementById("field31").alt=="player1")) || ((document.getElementById("field12").alt==document.getElementById("field22").alt) && (document.getElementById("field22").alt==document.getElementById("field32").alt) && (document.getElementById("field32").alt=="player1")) || ((document.getElementById("field13").alt==document.getElementById("field23").alt) && (document.getElementById("field23").alt==document.getElementById("field33").alt) && (document.getElementById("field33").alt=="player1")) || ((document.getElementById("field11").alt==document.getElementById("field22").alt) && (document.getElementById("field22").alt==document.getElementById("field33").alt) && (document.getElementById("field33").alt=="player1")) || ((document.getElementById("field13").alt==document.getElementById("field22").alt) && (document.getElementById("field22").alt==document.getElementById("field31").alt) && (document.getElementById("field31").alt=="player1")))
		{
			alert("Jucatorul 1 castiga!");
		}
		else if(((document.getElementById("field11").alt==document.getElementById("field12").alt) && (document.getElementById("field12").alt==document.getElementById("field13").alt) && (document.getElementById("field13").alt=="player2")) || ((document.getElementById("field21").alt==document.getElementById("field22").alt) && (document.getElementById("field22").alt==document.getElementById("field23").alt) && (document.getElementById("field23").alt=="player2")) || ((document.getElementById("field31").alt==document.getElementById("field32").alt) && (document.getElementById("field32").alt==document.getElementById("field33").alt) && (document.getElementById("field33").alt=="player2")) || ((document.getElementById("field11").alt==document.getElementById("field21").alt) && (document.getElementById("field21").alt==document.getElementById("field31").alt) && (document.getElementById("field31").alt=="player2")) || ((document.getElementById("field12").alt==document.getElementById("field22").alt) && (document.getElementById("field22").alt==document.getElementById("field32").alt) && (document.getElementById("field32").alt=="player2")) || ((document.getElementById("field13").alt==document.getElementById("field23").alt) && (document.getElementById("field23").alt==document.getElementById("field33").alt) && (document.getElementById("field33").alt=="player2")) || ((document.getElementById("field11").alt==document.getElementById("field22").alt) && (document.getElementById("field22").alt==document.getElementById("field33").alt) && (document.getElementById("field33").alt=="player2")) || ((document.getElementById("field13").alt==document.getElementById("field22").alt) && (document.getElementById("field22").alt==document.getElementById("field31").alt) && (document.getElementById("field31").alt=="player2")))
		{
			alert("Jucatorul 2 castiga!");
		};
	}
	if(x==9)
	{
		alert("Egalitate");
	};
}
function vanish()
{
	document.getElementById("tictactoe").style.visibility = "hidden";
	document.getElementById("wow").style.visibility = "visible";
    document.getElementById("top").style.marginTop = "0%";
	document.getElementById("wow").innerHTML = "Pana acum au jucat " + localStorage.getItem("contor") + " persoane.";
	let elem = document.getElementsByClassName("eticheta");
	for(i = 0; i < elem.length; i++)
	{
        elem[i].style.visibility = "visible";
    }
    elem = document.getElementsByClassName("textbox");
    for(i = 0; i < elem.length; i++)
    {
        elem[i].style.visibility = "visible";
    }
}
function appear()
{
	document.getElementById("tictactoe").style.visibility = "visible";
	document.getElementById("top").style.marginTop = "-15%";
	localStorage.setItem("contor", parseInt(localStorage.getItem("contor")) + 1);
}
