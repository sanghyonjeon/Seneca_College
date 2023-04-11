/* Citation and Sources...
Final Project Milestone 51
Module: Perishable
Filename: NonPerishable.cpp
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
#include "NonPerishable.h"

using namespace std;

namespace sdds {
    // Override the itemType function to return 'N'
    char NonPerishable::itemType() const {
        return 'N';
    }

    // Override the write function
    std::ostream& NonPerishable::write(std::ostream& os) const {
        // First, call the write function of the base class
        sdds::Item::write(os);

        // Check if the object is in a good state
        if (os) {
            // If the display type is LIST
            if (m_displayType == POS_LIST) {
                os << "     N / A   |" << left;
            }
            // If the display type is FORM
            else if (m_displayType == POS_FORM) {
                os << "=============^" << endl;
            }
        }

        return os;
    }
}