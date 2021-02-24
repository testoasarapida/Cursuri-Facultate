let express = require('express');
let bodyParser = require('body-parser');
let app = express();
let cors = require('cors');
let port = 3000;
//let crypto = require('crypto');

const fs = require('fs');

let rawData = fs.readFileSync('Data/bazadate.json');
let BDcastigator = JSON.parse(rawData);

function add_castigator(datebune)
{
    BDcastigator['castig'].push(datebune);
    let data = JSON.stringify(BDcastigator);
    fs.writeFileSync("Data/bazadate.json", data);
}

function delete_castig(datebune)
{
    BDcastigator['castig'].splice(datebune['acelcastigator'] - 1, 1);
    let data = JSON.stringify(BDcastigator);
    fs.writeFileSync("Data/bazadate.json", data);
}

function delete_all()
{
    BDcastigator['castig'] = [];
    let data = JSON.stringify(BDcastigator);
    fs.writeFileSync("Data/bazadate.json", data);
}

function delete_jucator(datebune)
{
    let vec = [];
    for (let cheie in BDcastigator.castig)
    {
        if( BDcastigator.castig[cheie]['nume'] == datebune['nume'] )
        {
            vec.push(cheie);
        }
    }
    vec = vec.reverse();
    vec.forEach(e => delete BDcastigator.castig[e]);
    BDcastigator.castig = BDcastigator.castig.filter(function (e1) {
        return e1 != null;
    });
    let data = JSON.stringify(BDcastigator);
    fs.writeFileSync("Data/bazadate.json", data);
    /*for (let cheie in BDcastigator.castig)
    {
        console.log("yes", cheie, BDcastigator.castig[cheie]['nume'], BDcastigator.castig[cheie]['data_adaugare']);
        if( BDcastigator.castig[cheie]['nume'] == datebune['nume'] )
        {
            console.log("yes", cheie, BDcastigator.castig[cheie]['nume'], BDcastigator.castig[cheie]['data_adaugare']);
            console.log("_______");
            BDcastigator['castig'].splice(parseInt(cheie), 1);
        }
    }*/
}

app.use(function (req, res, next)
{
    res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Headers", "Access-Control-Allow-Headers, Origin,Accept, X-Requested-With, Content-Type, Access-Control-Request-Method, Access-Control-Request-Headers, acces-control-allow-origin");
    next();
});

app.set('view engine', 'ejs');
app.use(bodyParser.urlencoded({ extended: false}));
app.use(bodyParser.json());
app.use(cors());

app.get('/', function (req, res)
{
   res.render('client.ejs', {root: __dirname});
});

app.get('/lista_castigatori', function (req, res)
{
    res.render('castigatori.ejs', {root: __dirname, BD:BDcastigator});
});

app.get('/castigatori', function (req, res)
{
    res.send(JSON.stringify(BDcastigator));
});

app.get('/adauga_castigator', function (req, res)
{
    res.render('adauga.ejs', {root: __dirname});
});

app.get('/reseteaza', function (req, res)
{
    res.render('reseteaza.ejs', {root: __dirname});
});

app.get('/sterge_jucator', function (req, res)
{
    res.render('sterge_jucator.ejs', {root: __dirname});
});

app.get('/Images/sturion_atlantic.png', function (req, res)
{
    res.sendFile('../Images/sturion_atlantic.png', {root: __dirname});
});

app.post('/adauga_castigator', function (req, res)
{
    add_castigator({
        ...req.body
    });
    res.render('castigatori.ejs', {root: __dirname});
});

app.post('/addCastigator', function (req, res)
{
    add_castigator({
        ...req.body
    });
    res.send(JSON.stringify({response: 'Succes!'}));
});

app.post('/lista_castigatori', function(req, res)
{
    delete_castig(req.body);
    res.render('client.ejs', {root: __dirname});
});

app.post('/sterge_jucator', function(req, res)
{
    delete_jucator(req.body);
    res.render('client.ejs', {root: __dirname});
});

app.post('/reseteaza', function(req, res)
{
    delete_all();
    res.render('client.ejs', {root: __dirname});
});

app.use(function(req, res)
{
   res.status(404).render('404.ejs', {root: __dirname});
});

app.listen(port, () =>
{
    console.log(`Server running at http://localhost:${port}/`);
});
