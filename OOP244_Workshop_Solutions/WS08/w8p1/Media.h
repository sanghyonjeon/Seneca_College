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
#ifndef SDDS_MEDIA_H_
#define SDDS_MEDIA_H_
#include <iostream>

namespace sdds {
    class Media {
    public:
        virtual std::ostream& play(std::ostream& os) const = 0;
        virtual void load(std::istream& is) = 0;
        virtual ~Media();
    };

    std::ostream& operator<<(std::ostream& os, const Media& src);
    std::istream& operator>>(std::istream& is, Media& src);
}
#endif // !SDDS_MEDIA_H_