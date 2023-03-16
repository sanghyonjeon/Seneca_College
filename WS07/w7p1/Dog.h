/*
*****************************************************************************
                          Workshop - #7 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 1123552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_DOG_H_
#define SDDS_DOG_H_
#include "Pet.h"

namespace sdds {
    class Dog : public Pet {
        int m_numWalks;

    public:
        Dog(const char* name, int age = 0);

        void feed();
        void walk();
        void reSpawn();
        Dog& operator++(int num);
        Dog& operator=(const Dog& rhs);

        int getNumWalks() const;
    };

    std::ostream& operator<<(std::ostream& os, Dog& dog);
}
#endif // !SDDS_DOG_H_