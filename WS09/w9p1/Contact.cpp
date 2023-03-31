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
#define _CRT_SECURE_NO_WARNINGS

#include "Contact.h"
#include "Tools.h"

using namespace std;

namespace sdds {
    Contact::Contact() : Person() {}

    Contact::Contact(const Contact& src) : Person(src) {
        setAddress(src.m_address);
        setCity(src.m_city);
        setProvince(src.m_province);
        setPostalCode(src.m_postalCode);
    }

    Contact& Contact::operator=(const Contact& src) {
        if (this != &src) {
            Person::operator=(src);
            setAddress(src.m_address);
            setCity(src.m_city);
            setProvince(src.m_province);
            setPostalCode(src.m_postalCode);
        }
        return *this;
    }

    Contact::~Contact() {
        ~*this;
    }

    std::istream& Contact::read(std::istream& is) {
        operator~();
        readName(is);
        readAddress(is);
        return is;
    }

    std::ostream& Contact::write(std::ostream& os) const {
        if (*this) {
            Person::write(os);

            os << endl;

            char* fullAddress = new char[strLen(m_address) + strLen(m_city) + strLen(m_province) + strLen(m_postalCode) + 5];
            fullAddress[0] = '\0';
            strCat(fullAddress, m_address);
            strCat(fullAddress, "\n");
            strCat(fullAddress, m_city);
            strCat(fullAddress, " ");
            strCat(fullAddress, m_province);
            strCat(fullAddress, "\n");
            strCat(fullAddress, m_postalCode);
            strCat(fullAddress, "\n");

            os << fullAddress;

            delete[] fullAddress;
        }
        return os;
    }

    Contact::operator bool() const {
        return m_address && m_address[0]
            && m_city && m_city[0]
            && m_province && m_province[0]
            && m_postalCode && m_postalCode[0]
            && strLen(m_province) == MAX_PROVINCE_LENGTH
            && strLen(m_postalCode) == MAX_POSTALCODE_LENGTH + 1;
    }

    void Contact::operator~() {
        Person::operator~();
        delete[] m_address;
        delete[] m_city;
        m_address = m_city = nullptr;
        m_province[0] = '\0';
        m_postalCode[0] = '\0';
    }

    std::istream& Contact::readName(std::istream& is) {
        return Person::read(is);
    }

    std::istream& Contact::readAddress(std::istream& is) {
        char* address = nullptr;
        char* city = nullptr;
        char province[MAX_PROVINCE_LENGTH + 1];
        char postalCode[MAX_POSTALCODE_LENGTH + 1];

        address = dynRead(is, ',');
        city = dynRead(is, ',');
        is.getline(province, MAX_PROVINCE_LENGTH + 1, ',');
        is.getline(postalCode, MAX_POSTALCODE_LENGTH + 1, '\n');

        setAddress(address);
        setCity(city);
        setProvince(province);
        setPostalCode(postalCode);

        delete[] address;
        delete[] city;

        return is;
    }

    void Contact::setAddress(const char* address) {
        delAlloCopy(m_address, address);
    }

    void Contact::setCity(const char* city) {
        delAlloCopy(m_city, city);
    }

    void Contact::setProvince(const char* province) {
        if (province && strLen(province) == MAX_PROVINCE_LENGTH) {
            strCpy(m_province, province);
        }
        else {
            m_province[0] = '\0';
        }
    }

    void Contact::setPostalCode(const char* postalCode) {
        if (postalCode
            && (strLen(postalCode) == MAX_POSTALCODE_LENGTH
                || strLen(postalCode) == MAX_POSTALCODE_LENGTH + 1)) {
            char temp[MAX_POSTALCODE_LENGTH + 2];

            if (postalCode[3] == ' ') {
                strCpy(temp, postalCode);
            }
            else {
                strCpy(temp, postalCode);

                temp[7] = '\0';
                temp[6] = postalCode[5];
                temp[5] = postalCode[4];
                temp[4] = postalCode[3];
                temp[3] = ' ';
            }

            strCpy(m_postalCode, temp);
        }
        else {
            m_postalCode[0] = '\0';
        }
    }
}