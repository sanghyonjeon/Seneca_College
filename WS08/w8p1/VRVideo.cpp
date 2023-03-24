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
#include "VRVideo.h"
#include <cstring>

using namespace std;

namespace sdds {
    VRVideo::VRVideo() : Video(), m_equipment(nullptr) {}

    VRVideo::VRVideo(int length, const char* equipment) : Video(length), m_equipment(nullptr) {
        if (length < 0 || !equipment || strlen(equipment) == 0) {
            delete[] m_equipment;
            m_equipment = nullptr;
        }
        else {
            m_equipment = new char[strlen(equipment) + 1];
            strcpy(m_equipment, equipment);
        }
    }

    VRVideo::~VRVideo() {
        delete[] m_equipment;
    }

    void VRVideo::load(std::istream& is) {
        const int bufferSize = 256;

        Video::load(is);

        char equipment[bufferSize];
        is.getline(equipment, bufferSize);

        delete[] m_equipment;
        m_equipment = new char[strlen(equipment) + 1];
        strcpy(m_equipment, equipment);
    }

    std::ostream& VRVideo::play(std::ostream& os) const {
        if (m_equipment != nullptr) {
            os << "VRVideo requires " << m_equipment << std::endl;
            os << "Video Length = " << Video::get();
        }
        return os;
    }
}