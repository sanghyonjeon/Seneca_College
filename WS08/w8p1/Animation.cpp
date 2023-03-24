/*
*****************************************************************************
                          Workshop - #8 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 113552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Animation.h"

using namespace std;

namespace sdds {
    Animation::Animation() : Video(), m_dimension(0) {}

    Animation::Animation(int length, int dimension)
        : Video(length) {
        if (length >= 0 && (dimension == 2 || dimension == 3)) {
            m_dimension = dimension;
        }
        else {
            m_dimension = 0;
        }
    }

    void Animation::load(std::istream& is) {
        Video::load(is);

        is.ignore(1000, '\n');

        if (m_dimension != 2 && m_dimension != 3) {
            m_dimension = 0;
        }
    }

    std::ostream& Animation::play(std::ostream& os) const {
        if (m_dimension != 0) {
            os << "Animation is in " << m_dimension << "-D" << endl;
            os << "Video Length = " << get();
        }
        return os;
    }
}