/*
*****************************************************************************
                          Workshop - #9 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 113552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_CONTACT_H_
#define SDDS_CONTACT_H_

#include "Person.h"

namespace sdds {
    const int MAX_PROVINCE_LENGTH = 2;
    const int MAX_POSTALCODE_LENGTH = 6;

    class Contact : public Person {
        char* m_address{};
        char* m_city{};
        char m_province[MAX_PROVINCE_LENGTH + 1]{};
        char m_postalCode[MAX_POSTALCODE_LENGTH + 2]{};

        void setAddress(const char* address);
        void setCity(const char* city);
        void setProvince(const char* province);
        void setPostalCode(const char* postalCode);

    public:
        Contact();
        Contact(const Contact& src);
        Contact& operator=(const Contact& src);
        ~Contact();

        std::istream& read(std::istream& is);
        std::ostream& write(std::ostream& os) const;
        // returns true if the contact is valid; 
        // a valid contact has an address, city, province,
        // and postal code, and they are not empty
        operator bool()const;
        // deallocates the dynamic memory
        void operator~();

        std::istream& readName(std::istream& is);
        std::istream& readAddress(std::istream& is);
    };
}
#endif // !SDDS_CONTACT_H_