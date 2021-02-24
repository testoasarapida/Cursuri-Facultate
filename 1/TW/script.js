var x = 1;
function animatie() 
{
	if (x % 2 == 1)
	{
    var targetElement = document.getElementById("menu");
    targetElement.className = "grow1";
    var targetElement = document.getElementById("text");
    targetElement.className = "small1";
    var targetElement = document.getElementById("meniul");
    targetElement.className = "grow3";
    var targetElement = document.getElementById("stanga");
    targetElement.className = "grow4";
    var targetElement = document.getElementById("centru");
    targetElement.className = "grow5";
    var targetElement = document.getElementById("Contact");
    targetElement.className = "grow6";
    var targetElement = document.getElementById("Afla");
    targetElement.className = "grow6";
    var targetElement = document.getElementById("Deseneaza");
    targetElement.className = "grow6";
    var targetElement = document.getElementById("Pastruga");
    targetElement.className = "grow6";
    x = x + 1;
  }
  else
  {
    var targetElement = document.getElementById("menu");
    targetElement.className = "small2";
    var targetElement = document.getElementById("text");
    targetElement.className = "grow2";
    var targetElement = document.getElementById("meniul");
    targetElement.className = "small3";
    var targetElement = document.getElementById("stanga");
    targetElement.className = "small4";
    var targetElement = document.getElementById("centru");
    targetElement.className = "small5";
    var targetElement = document.getElementById("Contact");
    targetElement.className = "small6";
    var targetElement = document.getElementById("Afla");
    targetElement.className = "small6";
    var targetElement = document.getElementById("Deseneaza");
    targetElement.className = "small6";
    var targetElement = document.getElementById("Pastruga");
    targetElement.className = "small6";
    x = x + 1;
  }
}



function tictactoe()
{
  document.getElementById("XsiO").parentNode.removeChild(document.getElementById("XsiO"));
  document.getElementById("fofo2").parentNode.removeChild(document.getElementById("fofo2"));
}

idleTimer = null;
idleState = false;
idleWait = 4000;
let bila1x = 1;
let bila1y = 1;
let bila2x = 1;
let bila2y = 1;

(function ($) {

    $(document).ready(function ()
    {

        $('*').bind('mousemove keydown scroll', function ()
        {
            clearTimeout(idleTimer);
            if (idleState == true)
            {
                clearInterval(window.timpul);
                bila1x = 1;
                bila1y = 1;
                bila2x = 300;
                bila2y = 0;
                crearecareu();
            }
            idleState = false;
            idleTimer = setTimeout(function ()
            {
                crearecareu();
                idle_a_lot();
                idleState = true;
            }, idleWait);
        });
        $("body").trigger("mousemove");
    });
}) (jQuery);

function idle_a_lot()
{
    window.timpul = setInterval(idlescreen,10);
}

var dx1 = 5;
let dy1 = 5;
let dx2 = 10;
let dy2 = 10;
function idlescreen()
{
    crearecareu();
    var c = document.getElementById("myCanvas");
    var ctx = c.getContext("2d");

    ctx.beginPath();
    ctx.fillStyle = "#0000ff";
    ctx.arc(bila1x,bila1y,20,0,Math.PI*2,true);
    ctx.closePath();
    ctx.fill();
    if( bila2x<0 || bila2x>c.width)
        dx1=-dx1;
    if( bila2y<0 || bila2y>c.height)
        dy1=-dy1;
    bila1x = bila1x + dx1;
    bila1y = bila1y + dy1;

    ctx.beginPath();
    ctx.fillStyle = "#00ff00";
    ctx.arc(bila2x,bila2y,20,0,Math.PI*2,true);
    ctx.closePath();
    ctx.fill();
    if( bila2x<0 || bila2x>c.width)
        dx2 = -dx2;
    if( bila2y<0 || bila2y>c.height)
        dy2=-dy2;
    bila2x = bila2x + dx2;
    bila2y = bila2y + dy2;
}

var contor = 0;
var pesti = ["Cega", "Pastruga", "Viza", "Nisetru", "Morun", "Sipul"];
$(document).ready(function() 
  {
    $(document.getElementById("butonul")).click(function()
    {
      if (contor > 0)
      {
        alert(pesti[Math.floor(Math.random() * pesti.length)]);
      }
      contor++;
      schimbanume();
      crearecareu();
      $(document.getElementById("myCanvas")).on("mousedown",function()
      {
        incepelinie();
      });
      $(document.getElementById("myCanvas")).on("mouseup",function()
      {
        sfarsestelinie();
        $(document.getElementById("myCanvas")).off("mousemove");
      });
    });
  });

var truewidth, trueheight, vechix, vechiy, livex, livey, ok = 1, k = 0;
var valorilinii = [];
function crearecareu ()
{
  var c = document.getElementById("myCanvas");
  var ctx = c.getContext("2d");
  var div = document.getElementById("panza");
  c.width = $(parent).width();
  c.height = $(parent).height();
  truewidth = c.width/div.clientWidth;
  trueheight = c.height/div.clientHeight;
  ctx.clearRect(0, 0, c.width, c.height);
  valorilinii = [];
  k = 0;
}
function incepelinie ()
{
  vechix = intregOrizontal(transformareOrizontala(event.pageX));
  vechiy = intregVertical(transformareVerticala(event.pageY));
  $(document.getElementById("myCanvas")).on("mousemove",function()
  {
    var ctx = document.getElementById("myCanvas").getContext("2d");
    if(ok==1)
    {
      ctx.lineWidth = 6;
      ctx.beginPath();
      ctx.strokeStyle = "transparent";
      ctx.moveTo(vechix, vechiy);
      ctx.lineTo(livex, livey);
      ctx.stroke();
      ok = 0;
    }
    else
    {
      ctx.lineWidth = 6;
      ctx.beginPath();
      ctx.strokeStyle = "#FFFFFF";
      ctx.moveTo(vechix, vechiy);
      ctx.lineTo(livex, livey);
      ctx.stroke();
    }
    livex = intregOrizontal(transformareOrizontala(event.pageX));
    livey = intregVertical(transformareVerticala(event.pageY));
    ctx.beginPath();
    ctx.lineWidth = 5;
    ctx.lineCap = "round";
    ctx.strokeStyle = "#BEBEBE";
    ctx.moveTo(vechix, vechiy);
    ctx.lineTo(livex, livey);
    ctx.stroke();
  }); 
}

function sfarsestelinie ()
{
  var x = intregOrizontal(transformareOrizontala(event.pageX));
  var y = intregVertical(transformareVerticala(event.pageY));
  var ctx = document.getElementById("myCanvas").getContext("2d");
  ctx.lineWidth = 5;
  ctx.beginPath();
  ctx.lineCap = "round";
  ctx.strokeStyle = "orange";
  ctx.moveTo(vechix, vechiy);
  ctx.lineTo(x, y);
  ctx.stroke();
  ok = 1;
  valorilinii[k] = {xA: vechix, 
                    yA: vechiy, 
                    xB: x, 
                    yB: y};
  k++;
}

function redesenare ()
{
  var i;
  var ctx = document.getElementById("myCanvas").getContext("2d");
  for (i = 0; i <= valorilinii.length; i++)
  {
    ctx.lineWidth = 5;
    ctx.beginPath();
    ctx.lineCap = "round";
    ctx.strokeStyle = "orange";
    ctx.moveTo(valorilinii[i].xA, valorilinii[i].yA);
    ctx.lineTo(valorilinii[i].xB, valorilinii[i].yB);
    ctx.stroke();
  }
}
window.onload = function() 
{
  return setInterval(redesenare, 30);
}
function schimbanume ()
{
  document.getElementById("butonul").value = "Verifica!";
  document.getElementById("apasand").innerHTML = "Esti de acord ca noi sa pastram si sa utilizam desenele pe care le realizezi. Multumim!";
  document.getElementById("apasand").style.textDecoration = "underline";
}
function transformareOrizontala (x)
{
  var obj = document.getElementById("myCanvas");
  var objstanga = 0;
  while (obj.offsetParent)
  {
    objstanga = objstanga + obj.offsetLeft;
    obj = obj.offsetParent;
  }
  x = x - objstanga;
  return x;
}
function transformareVerticala (y)
{
  var obj = document.getElementById("myCanvas");
  var objsus = 0;
  while (obj.offsetParent)
  {
    objsus = objsus + obj.offsetTop;
    obj = obj.offsetParent;
  }
  y = y - objsus;
  return y;
}
function intregOrizontal (x)
{
  x = truewidth * x;
  x = Math.floor( x );
  return x;
}
function intregVertical (y)
{
    y = trueheight * y;
    y = Math.floor( y );
    return y;
}