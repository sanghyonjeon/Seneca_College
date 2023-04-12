/* Citation and Sources...
Final Project Milestone 54
Module: Perishable
Filename: Perishable.cpp
Version: 1.0
Author: Sang Hyon Jeon
Revision History
-----------------------------------------------------------
Date        Reason
2023/04/16  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Perishable.h"

using namespace std;

namespace sdds {
    // Override the itemType function to return 'P'
    char Perishable::itemType() const {
        return 'P';
    }

    // Override the read function
    std::istream& Perishable::read(std::istream& is) {
        bool inputValid = true;

        // Invoke the read of the Base class
        Item::read(is);

        if (is && !is.fail()) {
            Date date;
            cout << "Expiry date (YYYY/MM/DD)" << endl;
            cout << "> ";
            if (!(is >> date)) {
                inputValid = false;
            }

            if (inputValid) {
                m_expiryDate = date;
            }
            else {
                m_error = date.error();
            }
        }

        return is;
    }

    // Override the write function
    std::ostream& Perishable::write(std::ostream& os) const {
        // Invoke the write of the base class
        Item::write(os);

        if (os && !os.fail()) {
            // If the display type is LIST
            if (m_displayType == POS_LIST) {
                os << ' ' << ' ' << m_expiryDate << ' ' << '|' << left;
            }
            // If the display type is FORM
            else if (m_displayType == POS_FORM) {
                os << "Expiry date: " << m_expiryDate << endl;
                os << "=============^" << endl << left;
            }
        }

        return os;
    }

    // Override the load function
    std::ifstream& Perishable::load(std::ifstream& ifs) {
        // Invoke the load of the Base class
        Item::load(ifs);

        bool inputValid = true;

        if (ifs && !ifs.fail()) {
            Date date;
            ifs.ignore();
            if (!(ifs >> date)) {
                inputValid = false;
            }

            if (inputValid) {
                m_expiryDate = date;
            }
            else {
                m_error = date.error();
            }
        }

        return ifs;
    }

    // Override the save function
    std::ofstream& Perishable::save(std::ofstream& ofs) const {
        // Invoke the save of the Base class
        Item::save(ofs);

        if (ofs) {
            ofs << ',' << m_expiryDate;
        }

        return ofs;
    }
}