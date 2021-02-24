#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <string>
using namespace std;

ifstream f("file.txt");

struct automat
{
    list<int> Q, F;
    list<char> Sigma;
    int q0;
    map<pair<int, char>, int> delta;
    int minimizat_de_tot = 0;
};

automat citire(automat M)
{
    int i;

    int nr_stari;
    f>>nr_stari;
    for(i = 0; i < nr_stari; i++)
    {
        int q;
        f>>q;
        M.Q.push_back(q);
    }

    int nr_litere;
    f>>nr_litere;
    for(i = 0; i < nr_litere; i++)
    {
        char a;
        f>>a;
        M.Sigma.push_back(a);
    }

    int nr_tranzitii;
    f>>nr_tranzitii;
    for(i = 0; i < nr_tranzitii; i++)
    {
        int p, u;
        char a;
        f>>p>>a>>u;
        M.delta[{p, a}]=u;
    }

    f>>M.q0;

    int nr_finale;
    f>>nr_finale;
    for(i = 0; i < nr_finale; i++)
    {
        int q;
        f>>q;
        M.F.push_back(q);
    }

    return M;
}

int deltastar(automat M, int q, string cuv)
{
    if(cuv.length() == 1)
    {
        return M.delta[{q, (char)cuv[0]}];
    }
    else
    {
        int nou = M.delta[{q, (char)cuv[0]}];
        cuv.erase(0, 1);
        return deltastar(M, nou, cuv);
    }
}

int verifica(automat M, int stare)
{
    int ok = 0;
    for(auto i = M.F.cbegin(); i != M.F.cend(); i++)
        if(stare == *i)
            ok = 1;
    if(ok==0)
        return 0;
    return 1;
}

automat minimizeaza(automat M)
{
    int de_sters[100];
    int contor = 0;
    int k = M.Sigma.size();
    map<pair<int, char>, int>::iterator i = M.delta.begin();
    while(i != M.delta.end())
    {
        int l = 0, nr = 0;
        map<pair<int, char>, int>::iterator j = i;
        while(l < k)
        {
            nr = nr * 10 + j->second;
            l++;
            advance(j,1);
        }
        j = i;
        advance(j,k);
        while(j != M.delta.end())
        {
            l = 0;
            int nr1 = 0;
            map<pair<int, char>, int>::iterator m = j;
            while(l < k)
            {
                nr1 = nr1 * 10 + m->second;
                l++;
                advance(m,1);
            }
            if(nr == nr1 && verifica(M,i->first.first) == 0 && verifica(M,j->first.first) == 0)
            {
                de_sters[contor++] = j->first.first;
                M.minimizat_de_tot = 1;
                cout<<"Starea "<<i->first.first<<" este identica cu starea "<<j->first.first<<"."<<endl;
                map<pair<int, char>, int>::iterator m;
                for(m = M.delta.begin(); m != M.delta.end(); m++)
                    if(m->second == j->first.first)
                        m->second = i->first.first;
            }
            advance(j,k);
        }
        advance(i,k);
    }
    list<char>::iterator m;
    for(m = M.Sigma.begin(); m != M.Sigma.end(); m++)
        for(int n = 0; n < contor; n++)
            M.delta.erase({de_sters[n],*m});
    //for(i = M.delta.begin(); i != M.delta.end(); i++)
    //cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
    return M;
}

automat minimizeaza_si_finale(automat M)
{
    int de_sters[100];
    int contor = 0;
    int k = M.Sigma.size();
    map<pair<int, char>, int>::iterator i = M.delta.begin();
    while(i != M.delta.end())
    {
        int l = 0, nr = 0;
        map<pair<int, char>, int>::iterator j = i;
        while(l < k)
        {
            nr = nr * 10 + j->second;
            l++;
            advance(j,1);
        }
        j = i;
        advance(j,k);
        while(j != M.delta.end())
        {
            l = 0;
            int nr1 = 0;
            map<pair<int, char>, int>::iterator m = j;
            while(l < k)
            {
                nr1 = nr1 * 10 + m->second;
                l++;
                advance(m,1);
            }
            if(nr == nr1 && verifica(M,i->first.first) == 1 && verifica(M,j->first.first) == 1)
            {
                de_sters[contor++] = j->first.first;
                M.minimizat_de_tot = 1;
                cout<<"Starea "<<i->first.first<<" este identica cu starea "<<j->first.first<<"."<<endl;
                map<pair<int, char>, int>::iterator m;
                for(m = M.delta.begin(); m != M.delta.end(); m++)
                    if(m->second == j->first.first)
                        m->second = i->first.first;
            }
            advance(j,k);
        }
        advance(i,k);
    }
    list<char>::iterator m;
    for(m = M.Sigma.begin(); m != M.Sigma.end(); m++)
        for(int n = 0; n < contor; n++)
            M.delta.erase({de_sters[n],*m});
    //for(i = M.delta.begin(); i != M.delta.end(); i++)
    //cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
    return M;
}

int main()
{
    int ok, spune = 1;
    automat M;
    M = citire(M);
    int stare;
    while(true)
    {
        M = minimizeaza(M);
        if(M.minimizat_de_tot == 1)
        {
            M.minimizat_de_tot = 0;
        }
        else
        {
            cout<<"Starile duplicate au fost eliminate (Elminati // de la liniile 138 & 139 pentru a vedea starile ramase)."<<endl;
            break;
        }
    }
    while(true)
    {
        M = minimizeaza_si_finale(M);
        if(M.minimizat_de_tot == 1)
        {
            M.minimizat_de_tot = 0;
        }
        else
        {
            cout<<"Starile finale duplicate au fost eliminate (Elminati // de la liniile 190 & 191 pentru a vedea starile ramase)."<<endl;
            break;
        }
    }
    stare = deltastar(M, M.q0, "ab");
    ok = verifica(M, stare);
    if(ok)
        cout<<endl<<"Cuvant acceptat";
    else
        cout<<endl<<"Cuvant neacceptat";
    return 0;
}