# variabile.aleatoare
#
# This is a package that implements different functions regarding
# continous random variables
#
# You can learn more about package authoring with RStudio at:
#
#   http://r-pkgs.had.co.nz/
#
# Some useful keyboard shortcuts for package authoring:
#
#   Install Package:           'Ctrl + Shift + B'
#   Check Package:             'Ctrl + Shift + E'
#   Test Package:              'Ctrl + Shift + T'

# Proiect de Andrei Mihailescu si David Bucur

constantaNormalizare <- function(f) {
  area = integrate(f,-Inf,Inf)$value #compute the area under the curve
  1/area
}

marginalX <- function(f, x) {
  ff <- function(val){f(x,val)} #helper function
  integrate(Vectorize(ff),-Inf,Inf)$value
}

marginalY <- function(f, y) {
  ff <- function(val){f(val,y)} #helper function
  integrate(Vectorize(ff),-Inf,Inf)$value
}

conditionalXY <- function(f,x,y){
  tem <- marginalY(f,y)
  if(tem==0){
    0 #undefined
  }
  else{
    f(x,y)/tem #return the computed conditional
  }
}

conditionalYX <- function(f,x,y){
  tem <- marginalX(f,x)
  if(tem==0){
    0 #undefined
  }
  else{
    f(x,y)/tem #return the computed conditional
  }
}

addXY <- function (f,s){
  fh <- function(x){ #helper function implementing the convolution
    marginalX(f,x) * marginalY(f,s-x)
  }
  integrate(Vectorize(fh),-Inf,Inf)$value #return the integral
}

diffXY <- function (f,d){
  fh <- function(x){ #helper function implementing the convolution
    marginalX(f,x) * marginalY(f,d+x)
  }
  integrate(Vectorize(fh),-Inf,Inf)$value #return the integral
}

medie <- function(f){
  fh <- function(x){ #helper function
    x * f(x)
  }
  integrate(Vectorize(fh),-Inf,Inf)$value #return the integral
}

dispersie <- function(f){
  med = medie(f)
  fh <- function(x){ #helper function
    ((x-med)^2) * f(x)
  }
  integrate(Vectorize(fh),-Inf,Inf)$value #return the integral
}

momentInitial1 <- function(f){
  fh <- function(x){ #helper function
    x * f(x)
  }
  integrate(Vectorize(fh),-Inf,Inf)$value #return the integral
}

momentInitial2 <- function(f){
  fh <- function(x){ #helper function
    (x^2) * f(x)
  }
  integrate(Vectorize(fh),-Inf,Inf)$value #return the integral
}

momentInitial3 <- function(f){
  fh <- function(x){ #helper function
    (x^3) * f(x)
  }
  integrate(Vectorize(fh),-Inf,Inf)$value #return the integral
}

momentInitial4 <- function(f){
  fh <- function(x){ #helper function
    (x^4) * f(x)
  }
  integrate(Vectorize(fh),-Inf,Inf)$value #return the integral
}

momentCentrat1 <- function(f){
  med = medie(f)
  fh <- function(x){ #helper function
    (x-med) * f(x)
  }
  integrate(Vectorize(fh),-Inf,Inf)$value #return the integral
}

momentCentrat2 <- function(f){
  med = medie(f)
  fh <- function(x){ #helper function
    ((x-med)^2) * f(x)
  }
  integrate(Vectorize(fh),-Inf,Inf)$value #return the integral
}

momentCentrat3 <- function(f){
  med = medie(f)
  fh <- function(x){ #helper function
    ((x-med)^3) * f(x)
  }
  integrate(Vectorize(fh),-Inf,Inf)$value #return the integral
}

momentCentrat4 <- function(f){
  med = medie(f)
  fh <- function(x){ #helper function
    ((x-med)^4) * f(x)
  }
  integrate(Vectorize(fh),-Inf,Inf)$value #return the integral
}


# ex2

verifica_densitate <- function(l, r, ecuatie) #se trasnmite intervalul si functia
{
  z = NULL

  #se incearca integrarea functiei date
  tryCatch(z <- integrate(f = functie, -Inf, Inf), warning = function(w) {return(FALSE)}, error = function(e) {return(FALSE)})
  
  if(!(is.numeric(z$value)) || z$value != 1) #se verifica daca rezultatul integralei este 1
  { 
    return(FALSE)
  }
  
  while (l <= r)
  {
    if(functie(l) < 0) #se verifica daca functia este pozitiva pe intervalul dat
    {
      return(FALSE)
    }
    l <- l + 0.01
  }
  
  return(TRUE)
}

# ex4

calcul_densitate <- function(l, r, dim, parametri) #se transmite intervalul si dimensiunea variabilei aleatoare impreuna cu lista de parametri
{
  probab <- integer(r - l + 1)
  probabilitate <- integer(r - l + 1)
  densitate <- integer(length(parametri)) #se creeaza vectorii care vor stoca probabilitatile
  j <- 1
  
  valori <- sample(l:r, dim) #se creeaza variabila aleatoare
  for (i in valori)
  {
    probab[i] <- probab[i] + 1
  }
  for (i in probab)
  {  
    probabilitate[j] <- i / (r - l + 1) #se creeaza vectorul de probabilitati asociat variabilei
    j <- j + 1
  }
  
  j <- 1

  while (j <= length(parametri))
  {
    i <- 1
    while(i <= dim)
    {
      if(parametri[j] == valori[i]) # se calculeaza densitatea parameterilor in variabila aleatoare
      {
        densitate[j] <- probabilitate[valori[i]]
      }
      i <- i + 1
    }
    
    j <- j + 1
  }
  
  plot(parametri, densitate, "b", col = "red") # se deseneaza graficul
}

# ex6

calcul_medie_dispersie <- function(l, r, dim, ecuatie)#se transmite intervalul si dimensiunea variabilei aleatoare impreuna cu ecuatia(functie)
{
  suma <- 0
  suma_patrate <- 0 #sunt initializate sumele
  
  z <- sample(l:r, dim) #se creeaza variabila aleatoare

  for (i in z)
  {
    suma <- suma + ecuatie(i)
    suma_patrate <- suma_patrate + ecuatie(i) * ecuatie(i)
  }
  
  media <- suma / dim
  dispersia <- suma_patrate / dim - media * media # se efectueaza calculul mediei si al dispersiei
  print(media)
  print(dispersia)
}


