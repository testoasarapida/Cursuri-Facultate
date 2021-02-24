idleTimer = null;
idleState = false;
idleWait = 10000;
tiempo = 0;

(function ($) {

    $(document).ready(function ()
    {

        $('*').bind('mousemove keydown scroll', function ()
        {
            clearTimeout(idleTimer);
            if (idleState == true)
            {
                clearInterval(window.idleInterval);
                window.negru.remove();
                tiempo = 0;
            }
            idleState = false;
            idleTimer = setTimeout(function ()
            {
                window.negru = document.createElement('div');
                negru.style.cssText = 'position:absolute;width:99%;height:100%;z-index:100;background:#000000;">';
                document.body.appendChild(window.negru);
                window.scris = document.createElement('p');
                window.scris.style.cssText = 'color:white;';
                window.negru.appendChild(window.scris);

                window.idleInterval = setInterval(function () {
                    tiempo = tiempo + 1;
                    window.scris.textContent = 'Ai fost inactiv '+ tiempo +'  secunde.';
                }, 1000);
                idleState = true;
            }, idleWait);
        });
        $("body").trigger("mousemove");
    });
}) (jQuery);
