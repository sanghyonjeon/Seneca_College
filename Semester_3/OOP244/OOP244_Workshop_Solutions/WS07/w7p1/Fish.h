/*
*****************************************************************************
                          Workshop - #7 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 113552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_FISH_H_
#define SDDS_FISH_H_
#include "Pet.h"

namespace sdds {
    class Fish : public Pet {
    public:
        Fish(const char* name, int age = 0);

        void feed();
        void reSpawn();
        Fish& operator++(int num);
        Fish& operator=(const Fish& rhs);
    };

    std::ostream& operator<<(std::ostream& os, Fish& fish);
}
#endif // !SDDS_FISH_H_