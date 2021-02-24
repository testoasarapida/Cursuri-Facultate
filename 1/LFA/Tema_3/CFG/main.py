import random as alegere    #este folosita libraria random


def creeazacuvant(generare):
    for element in generare: # se itereaza prin productie (poate fi cea de inceput sau oricare alta, este o funnctie recursiva)
        if element in gramatica:    #daca vreun element apare in gramatica (face parte din multimea simbolurilor neterminale)
            generare[generare.index(element)] = alegere.choice(gramatica[element])  #in locul din productie unde era retinut elementul este aleasa o valoare aleatorie din productia acelui element
        rezultat = []
        for x in generare:  #se itereaza prin productie
            if isinstance(x, str):  #daca elementul este de tip string
                rezultat.append(x)  #este adaugat la rezultat
            if isinstance(x, list): #daca elementul este o lista
                for y in x:
                    rezultat.append(y)  #fiecare element al listei este adaugat la rezultat
    for x in rezultat:  #se itereaza prin rezultat
        if not isinstance(x, list): #daca elementul nu este lista
            if x in gramatica:  #daca elementul se afla in gramatica
                rezultat = creeazacuvant(rezultat)  #se apeleaza recursiv, din nou, functia
    return rezultat


gramatica = {
    "start": "S",   #simbolul de start
    "S": [["A", "B"]],  # S-> AB
    "A": [["aa", "A", "ccc"],["aaccc"]],    # A-> aaAccc | aaccc
    "B": [["b", "B"],["b"]] #B-> bB | b
}
cuvant = "aaaaccccccbbbb"
i = 0
while i < 10000:    #orice cuvant am incercat, nu a trecut niciodata de ~1000, deci 10000 ar fi o cifra comoda
    cuvant_generat = []
    cuvant_generat.append(gramatica["start"]) #cuvantul este initializat cu simbolul de inceput din gramatica
    cuvant_generat = creeazacuvant(cuvant_generat)  #functia creeaza cuvant genereaza un cuvant random
    sir = ''.join(cuvant_generat) #cuvantul (memorat ca lista) este convertit in string
    if cuvant == sir:
        print("da") #daca este gasit cuvantul, se afiseaza da
        i = 10001
    i = i + 1
if i == 10000:  #daca while-ul esueaza, se afiseaza nu
    print("nu")