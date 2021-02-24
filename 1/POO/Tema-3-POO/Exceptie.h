#ifndef TEMA3POOV2_EXCEPTIE_H
#define TEMA3POOV2_EXCEPTIE_H
#include <exception>
using namespace std;

class Exceptie : public exception
{
    public:
        Exceptie () noexcept
        {

        }
        virtual ~Exceptie() noexcept = default;
        Exceptie (const Exceptie&) noexcept = default;
        Exceptie& operator = (const Exceptie&) noexcept = default;
        virtual const char* what() const noexcept
        {
            return "Animalul nu traieste!!! :(((";
        }
};


#endif
