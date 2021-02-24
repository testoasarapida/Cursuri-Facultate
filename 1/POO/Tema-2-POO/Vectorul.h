#ifndef VECTORUL_H
#define VECTORUL_H
#include <iostream>
#include <vector>
using namespace std;

class Vectorul
{
    private:
        vector<int> v = {0};
    public:
        Vectorul();
        Vectorul(int, int*);
        virtual ~Vectorul();
        Vectorul(const Vectorul& other);

        Vectorul& operator = (const Vectorul&);
        int aduyayy(int);

        friend istream& operator >> (istream&, Vectorul&);
        friend ostream& operator << (ostream&, Vectorul&);

        friend class Matricea;
};

#endif // VECTORUL_H
