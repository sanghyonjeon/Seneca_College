/*
*****************************************************************************
                          Workshop - #4 (Part-2)
Full Name  : Sang Hyon Jeon
Student ID#: 113552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_
#include <iostream>

namespace sdds {
    const int MIN_NAME_LENGTH = 20;
    const int MAX_NAME_LENGTH = 40;

    class NameTag {
        // Member Variables
        char* m_name = nullptr;
        int m_extension;
        bool m_extension_exists;

    public:
        // Constructors & Destructor
        NameTag();
        NameTag(const char* name);
        NameTag(const char* name, int extension);
        ~NameTag();

        // Member Functions
        NameTag& read();
        void print() const;

        // Utility Functions
        void setEmpty();
        void emptyName();
        void emptyExtension();

        bool validName(const char* name);
        bool validExtension(int extension);

        void setName(const char* name);
        void setExtension(int extension);
    };
}
#endif // !SDDS_NAMETAG_H_