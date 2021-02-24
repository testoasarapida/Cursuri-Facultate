\name{verifica_densitate}
\alias{verifica_densitate}
\title{Verificarea daca o functie este densitate de probabilitate}
\usage{
verifica_densitate(l, r, ecuatie)
}
\description{
Primeste intervalul de lucru si functia pe care trebuie sa o verifice si returneaza TRUE/FALSE.
}
\examples{
verifica_densitate(1,10, function(x) sin(x) + cos(x))
}
