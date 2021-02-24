#include <iostream>
#include <map>
#include <string>
#include <set>
#include <fstream>
using namespace std;

class NFA
{
	set<int> Q, F;
	set<char> Sigma;
	set<int> q0;
	map<pair<int, char>, set<int>> delta;

public:
	NFA()
	{
	    this->q0.insert(0);
    }
	NFA(set<int> Q, set<char> Sigma, map<pair<int, char>, set<int>> delta, set<int> q0, set<int> F)
	{
		this->Q = Q;
		this->Sigma = Sigma;
		this->delta = delta;
		this->q0 = q0;
		this->F = F;
	}
	set<int> getQ() const { return this->Q; }
	set<int> getF() const { return this->F; }
	set<char> getSigma() const { return this->Sigma; }
	set<int> getInitialState() const { return this->q0; }
	map<pair<int, char>, set<int>> getDelta() const { return this->delta; }

	friend istream& operator >> (istream&, NFA&);

	bool isFinalState(set<int>);
	set<int> deltaStar(set<int>, string);
};

bool NFA::isFinalState(set<int> q)
{
    for(int i: q)
    {
        const bool is_in = F.find(i) != F.end();
        if (is_in == false)
            return false;
    }
    return true;
}

set<int> NFA::deltaStar(set<int> s, string w)
{
    int n = w.length();
	set<int> localFinalStates;
	for (int i: s)
        for (int j: delta[{i, w[0]}])
        {
            localFinalStates.insert(j);
        }
    n--;
    if (n==0)
    {
        return localFinalStates;
    }
    int contor = 0;
    while(n)
    {
        set<int> auxiliar;
        for (int i: localFinalStates)
            for (int j: delta[{i, w[contor + 1]}])
                auxiliar.insert(j);
        n--;
        contor++;
        localFinalStates.clear();
        for (int i: auxiliar)
            localFinalStates.insert(i);
        auxiliar.clear();
    }
    return localFinalStates;
}

istream& operator >> (istream& f, NFA& M)
{
	int noOfStates;
	f >> noOfStates;
	for (int i = 0; i < noOfStates; ++i)
	{
		int q;
		f >> q;
		//cout << q;
		M.Q.insert(q);
	}

	int noOfLetters;
	f >> noOfLetters;
	for (int i = 0; i < noOfLetters; ++i)
	{
		char ch;
		f >> ch;
		M.Sigma.insert(ch);
	}

	int noOfTransitions;
	f >> noOfTransitions;
	for (int i = 0; i < noOfTransitions; ++i)
	{
		int s, noOfDestinations;
		char ch;
		f >> s >> ch >> noOfDestinations;
		for (int j = 0; j < noOfDestinations; ++j)
        {
            int d;
            f >> d;
            M.delta[{s, ch}].insert(d);
        }
	}

	int noOfInitialStates;
	f>> noOfInitialStates;
	for (int i = 0; i < noOfInitialStates; ++i)
    {
        int q;
        f >> q;
        M.q0.insert(q);
    }

	int noOfFinalStates;
	f >> noOfFinalStates;
	for (int i = 0; i < noOfFinalStates; ++i)
	{
		int q;
		f >> q;
		M.F.insert(q);
	}

	return f;
}

int main()
{
	NFA M;

	ifstream fin("nfa.txt");
	fin >> M;
	fin.close();

	set<int> lastStates = M.deltaStar(M.getInitialState(), "aaaaa");

	if (M.isFinalState(lastStates))
	{
		cout << "Cuvant acceptat";
	}
	else
	{
		cout << "Cuvant respins";
	}

	return 0;
}
