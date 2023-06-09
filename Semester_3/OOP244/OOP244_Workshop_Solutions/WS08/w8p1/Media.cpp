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
#include "Media.h"

using namespace std;

namespace sdds {
    std::ostream& operator<<(std::ostream& os, const Media& src) {
        return src.play(os);
    }

    std::istream& operator>>(std::istream& is, Media& src) {
        src.load(is);
        return is;
    }

    Media::~Media() {}
}