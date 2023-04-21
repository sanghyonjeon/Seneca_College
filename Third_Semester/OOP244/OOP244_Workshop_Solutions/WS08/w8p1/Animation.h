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
#ifndef SDDS_ANIMATION_H_
#define SDDS_ANIMATION_H_
#include "Video.h"

namespace sdds {
    class Animation : public Video {
        int m_dimension;

    public:
        Animation();
        Animation(int length, int dimension);

        void load(std::istream& is);
        std::ostream& play(std::ostream& os) const;
    };
}
#endif // !SDDS_ANIMATION_H_