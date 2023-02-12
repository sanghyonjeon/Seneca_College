/*
*****************************************************************************
                          Workshop - #4 (Part-2)
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
#include <cstring>
#include "NameTag.h"

using namespace std;

namespace sdds {
    // Default constructor
    NameTag::NameTag() {
        setEmpty();
    }

    // One-argument constructor: name
    NameTag::NameTag(const char* name) {
        setEmpty();

        if (validName(name)) {
            setName(name);
        }
    }

    // Two-argument constructor: name and extension
    NameTag::NameTag(const char* name, int extension) {
        setEmpty();

        if (validName(name)) {
            if (validExtension(extension)) {
                setName(name);
                setExtension(extension);
            }
            //else {
                //emptyExtension();
                //m_extension = extension;
            //}
        }
    }

    // Destructor
    NameTag::~NameTag() {
        emptyName();
    }

    // Utility Functions
    void NameTag::setEmpty() {
        emptyName();
        emptyExtension();
    }

    void NameTag::emptyName() {
        if (validName(m_name)) {
            delete[] m_name;
            m_name = nullptr;
        }
    }

    void NameTag::emptyExtension() {
        m_extension = 0;
        m_extension_exists = false;
    }

    void NameTag::setName(const char* name) {
        int length = strlen(name);

        if (length > MAX_NAME_LENGTH)
        {
            length = MAX_NAME_LENGTH;
        }

        m_name = new char[length + 1];
        strncpy(m_name, name, length);
        m_name[length] = '\0';
    }

    void NameTag::setExtension(int extension) {
        m_extension = extension;
        m_extension_exists = true;
    }

    bool NameTag::validName(const char* name) {
        bool valid = (name != nullptr && strlen(name) > 0);

        return valid;
    }

    bool NameTag::validExtension(int extension) {
        bool valid = (extension >= 10000 && extension <= 99999);

        return valid;
    }

    // function to read name and extension from user input
    NameTag& NameTag::read() {
        char name[MAX_NAME_LENGTH + 1];
        char answer;

        cout << "Please enter the name: ";
        cin >> ws;
        cin.getline(name, MAX_NAME_LENGTH + 1);

        emptyName();
        setName(name);

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Would you like to enter an extension? (Y)es/(N)o: ";
        cin >> answer;

        while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Only (Y) or (N) are acceptable, try agin: ";
            cin >> answer;
        }

        if (answer == 'Y' || answer == 'y') {
            int extension = 0;

            cout << "Please enter a 5 digit phone extension: ";
            cin >> extension;

            while (extension > 99999 || extension < 10000) {
                if (cin.fail()) {
                    cout << "Bad integer value, try again: ";
                }
                else {
                    cout << "Invalid value [10000<=value<=99999]: ";
                }
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> extension;
            }

            m_extension = extension;
            m_extension_exists = true;
        }
        else {
            emptyExtension();
        }

        return *this;
    }

    // function to print name tag
    void NameTag::print() const {
        if (m_name == nullptr) {
            cout << "EMPTY NAMETAG!" << endl;
        }
        else {
            int nameLength = strlen(m_name);

            if (nameLength < MIN_NAME_LENGTH) {
                nameLength = MIN_NAME_LENGTH;
            }

            if (!m_extension_exists && (m_extension > 99999 || m_extension < 10000)) {

                cout << "+";
                cout.width(nameLength + 3);
                cout.fill('-');
                cout << "+" << endl;

                cout << "|";
                cout.width(nameLength + 3);
                cout.fill(' ');
                cout << "|" << endl;

                cout << "| ";
                cout.width(nameLength);
                cout.setf(ios::left);
                cout << m_name;
                cout.fill(' ');
                cout << " |" << endl;
                cout.unsetf(ios::left);

                cout << "|";
                cout.width(nameLength + 3);
                cout.fill(' ');
                cout << "|" << endl;

                cout << "| Extension: N/A";
                cout.width(nameLength - 12);
                cout.fill(' ');
                cout << "|" << endl;

                cout << "|";
                cout.width(nameLength + 3);
                cout.fill(' ');
                cout << "|" << endl;

                cout << "+";
                cout.width(nameLength + 3);
                cout.fill('-');
                cout << "+" << endl;
            }
            else {
                cout << "+";
                cout.width(nameLength + 3);
                cout.fill('-');
                cout << "+" << endl;

                cout << "|";
                cout.width(nameLength + 3);
                cout.fill(' ');
                cout << "|" << endl;

                cout << "| ";
                cout.width(nameLength);
                cout.setf(ios::left);
                cout << m_name;
                cout.fill(' ');
                cout << " |" << endl;
                cout.unsetf(ios::left);

                cout << "|";
                cout.width(nameLength + 3);
                cout.fill(' ');
                cout << "|" << endl;

                cout << "|";
                cout << " Extension: " << m_extension;
                cout.width(nameLength - 14);
                cout.fill(' ');
                cout << "|" << endl;

                cout << "|";
                cout.width(nameLength + 3);
                cout.fill(' ');
                cout << "|" << endl;

                cout << "+";
                cout.width(nameLength + 3);
                cout.fill('-');
                cout << "+" << endl;
            }
        }
    }

}