import Data.List

myInt = 555

double :: Integer->Integer 
double x = x+x

triple :: Integer->Integer
triple x=x+x+x

maxim :: Integer->Integer->Integer
maxim x y = 
  if (x>y) 
    then x 
    else y

maxim3 :: Integer->Integer->Integer->Integer
maxim3 x y z =
  let 
    u = maxim x y
  in 
    maxim u z

data Alegere
  = Piatra
  | Foarfeca
  | Hartie
  deriving (Eq, Show)

data Rezultat
  = Victorie
  | Infrangere
  | Egalitate
  deriving (Eq, Show)

partida :: Alegere->Alegere->Rezultat
partida Piatra Foarfeca = Victorie
partida Piatra Hartie = Infrangere
partida Foarfeca Piatra = Infrangere
partida Foarfeca Hartie = Victorie
partida Hartie Piatra = Victorie
partida Hartie Foarfeca = Infrangere
partida _ _ = Egalitate

