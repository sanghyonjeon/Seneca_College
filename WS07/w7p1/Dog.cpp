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
#include "Dog.h"

using namespace std;

namespace sdds {
    Dog::Dog(const char* name, int age)
        : Pet(name, age, 0), m_numWalks(0) {
    }

    void Dog::feed() {
        Pet::feed();
        if (isAlive()) {
            addCharge(0.25);
        }
    }

    void Dog::walk() {
        if (isAlive()) {
            m_numWalks++;
        }
    }

    void Dog::reSpawn() {
        Pet::reSpawn();
        addCharge(1.0);
        m_numWalks = 0;
    }

    Dog& Dog::operator++(int num) {
        if (isAlive()) {
            double healthDelta = 0;
            healthDelta += 0.15 * (getHugs() - 1);
            healthDelta += 0.10 * (getFeeds() - 2);
            healthDelta += 0.10 * (getGrooms() - 1);
            healthDelta += 0.20 * (m_numWalks - 2);

            applyHealthDelta(healthDelta);
            Pet::operator++(0);
            m_numWalks = 0;
        }

        return *this;
    }

    Dog& Dog::operator=(const Dog& rhs) {
        if (this != &rhs) {
            Pet::operator=(rhs);
            m_numWalks = rhs.m_numWalks;
            addCharge(2 * 4.0);
        }

        return *this;
    }

    int Dog::getNumWalks() const {
        return m_numWalks;
    }

    std::ostream& operator<<(std::ostream& os, Dog& dog) {
        os << "** Generic Dog **" << std::endl;
        os << "   Walks: " << dog.getNumWalks() << std::endl;
        dog.outputData(os);

        return os;
    }
}