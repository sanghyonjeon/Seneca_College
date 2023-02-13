/*
*****************************************************************************
                          Workshop - #5 (Part-1)
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
#include <iostream>
#include "EggCarton.h"

using namespace std;

namespace sdds {
    EggCarton::EggCarton(int size, int noOfEggs, bool jumbo) {
        bool validSize = (size % 6 == 0 && size >= 6 && size <= 36);
        bool validNoOfEggs = (noOfEggs <= size && noOfEggs >= 0);

        if (validSize && validNoOfEggs) {
            m_size = size;
            m_noOfEggs = noOfEggs;
            m_jumbo = jumbo;
        }
        else {
            setBroken();
        }
    }

    void EggCarton::setBroken() {
        m_size = -1;
        m_noOfEggs = -1;
    }

    bool EggCarton::isBroken(int m_size, int m_noOfEggs) const {
        bool broken = (m_size == -1 && m_noOfEggs == -1);

        return broken;
    }
    
    std::ostream& EggCarton::display(std::ostream& ostr) const {
        if (isBroken(m_size, m_noOfEggs)) {
            ostr << "Broken Egg Carton!" << std::endl;
        }
        else {
            displayCarton(m_size, m_noOfEggs, m_jumbo, ostr);
        }
        return ostr;
    }
    
    std::ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, std::ostream& ostr)const {
        int cartonWidth = size == 6 ? 3 : 6;
        for (int i = 0; i < size; i++) {
            ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
            ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
        }
        return ostr;
    }
    
    std::istream& EggCarton::read(std::istream& istr) {
        char jumbo;
        int size;
        int noOfEggs;
        int flag = 0;

        istr >> jumbo;
        if (jumbo == 'j') {
            m_jumbo = true;
        }
        else {
            m_jumbo = false;
        }
        istr.ignore(1);

        istr >> size;
        if (size % 6 == 0 && size >= 6 && size <= 36) {
                m_size = size;
        } else {
            flag = 1;
        }
        istr.ignore(1);

        istr >> noOfEggs;
        if (noOfEggs <= size && noOfEggs >= 0) {
            m_noOfEggs = noOfEggs;
        } else {
            flag = 1;
        }

        if (flag) {
            setBroken();
        }

        return istr;
    }

    EggCarton::operator bool() const {
        return !isBroken(m_size, m_noOfEggs);
    }

    EggCarton::operator int() const {
        return (bool(*this)) ? m_noOfEggs : -1;
    }

    EggCarton::operator double() const {
        return (bool(*this)) ? (m_noOfEggs * ((m_jumbo) ? JumboEggWeight : RegularEggWeight) * GramsToKilos) : -1.0;
    }

    EggCarton& EggCarton::operator--() {
        if (bool(*this)) {
            m_noOfEggs--;
        }
        return *this;
    }

    EggCarton& EggCarton::operator++() {
        if (bool(*this)) {
            m_noOfEggs++;

            if (m_noOfEggs > m_size) {
                setBroken();
            }
        }

        return *this;
    }

    EggCarton EggCarton::operator--(int) {
        EggCarton copy = *this;
        --copy;

        return copy;
    }

    EggCarton EggCarton::operator++(int) {
        EggCarton copy = *this;
        ++(*this);

        return copy;
    }

    EggCarton& EggCarton::operator=(int value) {
        m_noOfEggs = value;
        if (m_noOfEggs > m_size) {
            setBroken();
        }

        return *this;
    }

    EggCarton& EggCarton::operator+=(int value) {
        m_noOfEggs += value;
        if (m_noOfEggs > m_size) {
            setBroken();
        }

        return *this;
    }

    EggCarton& EggCarton::operator+=(EggCarton& right) {
        if (bool(*this)) {
            int emptySpots = m_size - m_noOfEggs;

            if (emptySpots >= right.m_noOfEggs) {
                m_noOfEggs += right.m_noOfEggs;
                right.m_noOfEggs = 0;
            }
            else {
                m_noOfEggs = m_size;
                right.m_noOfEggs -= emptySpots;
            }
        }
        
        return *this;
    }

    bool EggCarton::operator==(const EggCarton& right) const {
        return abs(double(*this) - double(right)) <= 0.001;
    }

    int EggCarton::getNoOfEggs() const {
        return m_noOfEggs;
    }

    int operator+(int left, const EggCarton& right) {
        return (bool(right)) ? (left + right.getNoOfEggs()) : left;
    }

    std::ostream& operator<<(std::ostream& ostr, const EggCarton& right) {
        right.display(ostr);
        
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, EggCarton& right) {
        right.read(istr);

        return istr;
    }
}