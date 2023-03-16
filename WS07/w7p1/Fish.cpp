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
#define _CRT_SECURE_NO_WARNINGS
#include "Fish.h"

using namespace std;

namespace sdds {
    Fish::Fish(const char* name, int age)
        : Pet(name, age, 0) {
    }

    void Fish::feed() {
        Pet::feed();
        if (isAlive()) {
            addCharge(0.1);
        }
    }

    void Fish::reSpawn() {
        Pet::reSpawn();
        addCharge(0.5);
    }

    Fish& Fish::operator++(int num) {
        if (isAlive()) {
            double healthDelta = 0;
            healthDelta += 0.20 * (getFeeds() - 1);

            applyHealthDelta(healthDelta);
            Pet::operator++(0);
        }

        return *this;
    }

    Fish& Fish::operator=(const Fish& rhs) {
        if (this != &rhs) {
            Pet::operator=(rhs);
            addCharge(2 * 2.0);
        }

        return *this;
    }

    std::ostream& operator<<(std::ostream& os, Fish& fish) {
        os << "** Generic Fish **" << endl;
        fish.outputData(os);

        return os;
    }
}