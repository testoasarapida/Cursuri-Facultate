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
    list<string> Sigma;
    int q0;
    map<pair<int, string>, int> delta;
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
        string a;
        f>>a;
        M.Sigma.push_back(a);
    }

    int nr_tranzitii;
    f>>nr_tranzitii;
    for(i = 0; i < nr_tranzitii; i++)
    {
        int p, u;
        string a;
        f>>p>>a>>u;
        M.delta[{p, a}] = u;
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
        string s(1,(cuv[0]));
        return M.delta[{q, s}];
    }
    else
    {
        string s(1,(cuv[0]));
        int nou = M.delta[{q, s}];
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

automat concateneaza(automat M)
{
    map<string, int> de_sters;
    map<pair<int, string>, int>::iterator i = M.delta.begin();
    while(i != M.delta.end())
    {
        if(i->first.first == i->second)
        {
            string sir = "(";
            sir = sir + i->first.second[0];
            for(int j = 1; j < i->first.second.size(); j++)
                sir = sir + "+" + i->first.second[j];
            sir = sir + ")*";
            M.delta[{i->first.first, sir}] = i->second;
            de_sters[i->first.second] = i->first.first;
        }
        if(i->first.first != i->second && i->first.second.size() > 1)
        {
            string sir = "(";
            sir = sir + i->first.second[0];
            for(int j = 1; j < i->first.second.size(); j++)
                sir = sir + "+" + i->first.second[j];
            sir = sir + ")";
            M.delta[{i->first.first, sir}] = i->second;
            de_sters[i->first.second] = i->first.first;
        }
        advance(i,1);
    }
    map<string, int>::iterator j;
    for(j = de_sters.begin(); j != de_sters.end(); j++)
        M.delta.erase({j->second, j->first});
    return M;
}

automat adauga_stari(automat M)
{
    int ok = 0;
    map<pair<int, string>, int>::iterator i;
    for(i = M.delta.begin(); i != M.delta.end(); i++)
        if(i->second == M.q0)
            ok = 1;
    if(ok)
    {
        M.delta[{M.Q.size(), "!"}] = M.q0;
        M.q0 = M.Q.size();
        M.Q.push_back(M.Q.size());
    }
    ok = 0;
    if(M.F.size() > 1)
    {
        int j = M.Q.size(), contor = 34;
        M.Q.push_back(M.Q.size());
        list<int>::iterator k;
        for(k = M.F.begin(); k != M.F.end(); k++)
        {
            string caracter(1, char(contor));
            M.delta[{*k, caracter}] = j;
            contor++;
        }
        M.F.clear();
        M.F.push_back(j);
    }
    return M;
}

automat reduce(automat M, int stare)
{
    cout<<"Reducere stare "<<stare<<endl;
    map<pair<int, string>, int> in,out,nou,de_sters;
    int ok = 0, prim;
    string sir_propriu;
    map<pair<int, string>, int>::iterator i,j;
    for(i = M.delta.begin(); i != M.delta.end(); i++)
    {
        if(i->second == i->first.first && i->second == stare)
        {
            ok = 1;
            sir_propriu = i->first.second;
            prim = i->first.first;
        }
        if(i->second == stare && i->first.first != stare)
        {
            in[{i->first.first, i->first.second}] = i->second;
        }
        else
        if(i->first.first == stare && i->second != stare)
        {
            out[{i->first.first, i->first.second}] = i->second;
        }
    }
    for(i = in.begin(); i != in.end(); i++)
        for(j = out.begin(); j != out.end(); j++)
        {
            string sir = "";
            if(!(i->first.second.size() == 1 && int(char(i->first.second[0])) >= 33 && int(char(i->first.second[0])) <= 47))
                sir = i->first.second;
            if(ok)
                if(sir_propriu.size() == 6)
                    sir = sir + sir_propriu;
                else
                    sir = sir + "[" + sir_propriu + "]*";
            if(!(j->first.second.size() == 1 && int(char(j->first.second[0])) >= 33 && int(char(j->first.second[0])) <= 47))
                sir = sir + j->first.second;
            nou[{i->first.first, sir}] = j->second;
        }
    for(i = in.begin(); i != in.end(); i++)
        M.delta.erase({i->first.first, i->first.second});
    for(j = out.begin(); j != out.end(); j++)
        M.delta.erase({j->first.first, j->first.second});
    if(ok)
        M.delta.erase({prim, sir_propriu});
    for(i = nou.begin(); i != nou.end(); i++)
    {
        M.delta[{i->first.first, i->first.second}] = i->second;
        cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
    }
    cout<<endl;
    return M;
}

automat rezolva(automat M)
{
    map<pair<int, string>, int> nou, de_sters;
    map<pair<int, string>, int>::iterator i,j;
    for(i = M.delta.begin(); i != M.delta.end(); i++)
    {
        map<pair<int, string>, int>::iterator k = i;
        advance(k,1);
        for(j = k; j != M.delta.end(); j++)
            if(i->first.first == j->first.first && i->second == j->second)
            {
                if(!(i->first.second.size() == 1 && int(char(i->first.second[0])) >= 33 && int(char(i->first.second[0])) <= 47) && !(j->first.second.size() == 1 && int(char(j->first.second[0])) >= 33 && int(char(j->first.second[0])) <= 47))
                    nou[{i->first.first, i->first.second + j->first.second}] = i->second;
                else
                if(i->first.second.size() == 1 && int(char(i->first.second[0])) >= 33 && int(char(i->first.second[0])) <= 47)
                    nou[{i->first.first, j->first.second}] = i->second;
                else
                if(j->first.second.size() == 1 && int(char(j->first.second[0])) >= 33 && int(char(j->first.second[0])) <= 47)
                    nou[{i->first.first, i->first.second}] = i->second;
                de_sters[{i->first.first, i->first.second}] = i->second;
                de_sters[{j->first.first, j->first.second}] = j->second;
            }
        advance(k,1);
        if(k == M.delta.end())
            break;
    }
    for(i = de_sters.begin(); i != de_sters.end(); i++)
        M.delta.erase({i->first.first, i->first.second});
    for(i = nou.begin(); i != nou.end(); i++)
        M.delta[{i->first.first, i->first.second}] = i->second;
    return M;
}

int main()
{
    int ok, lungime, l;
    automat M;
    M = citire(M);
    lungime = M.Q.size();
    M = concateneaza(M);
    M = adauga_stari(M);
    for(l = 0; l < lungime; l++)
    {
        cout<<endl;
        M = reduce(M,l);
        M = rezolva(M);
        map<pair<int, string>, int>::iterator i;
        cout<<"Stari ramase:"<<endl;
        for(i = M.delta.begin(); i != M.delta.end(); i++)
            cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
        cout<<endl;
    }
    return 0;
}