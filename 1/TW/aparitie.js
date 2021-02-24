let text = 'Ferma de sturioni';
let inceput = 0;
let sfarsit = text.length - 1;
let titlu = document.createElement('h1');

window.onload = function()
{
    var divi = document.getElementById("aiciapare");
    divi.appendChild(titlu);
    scrie();
};

function scrie()
{
    console.log(titlu.textContent.substring(0,titlu.textContent.length/2), text.charAt(inceput), text.charAt(sfarsit), titlu.textContent.substring(titlu.textContent.length/2, titlu.textContent.length));
    titlu.textContent = titlu.textContent.substring(0,titlu.textContent.length/2) + text.charAt(inceput) + text.charAt(sfarsit) + titlu.textContent.substring(titlu.textContent.length/2, titlu.textContent.length);
    inceput = inceput + 1;
    sfarsit = sfarsit - 1;
    if (inceput <= sfarsit)
        window.setTimeout(scrie, 100);
}