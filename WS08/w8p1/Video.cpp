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
#include "Video.h"

using namespace std;

namespace sdds {
    int Video::get() const {
        return m_length;
    }

    Video::Video() {
        m_length = 0;
    }

    Video::Video(int length) {
        if (length >= 0) {
            m_length = length;
        }
        else {
            m_length = 0;
        }
    }

    void Video::load(std::istream& is) {
        char ch;
        is >> m_length >> ch;
    }
}