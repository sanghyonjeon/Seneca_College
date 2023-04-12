/* Citation and Sources...
Final Project Milestone 55
Module: Perishable
Filename: NonPerishable.h
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
#ifndef SDDS_NONPERISHABLE_H_
#define SDDS_NONPERISHABLE_H_
#include "Item.h"

namespace sdds {
    class NonPerishable : public Item {
    public:
        // Override the itemType function to return 'N'
        virtual char itemType() const;
        // Override the write function
        virtual std::ostream& write(std::ostream& os) const;
    };
}
#endif // !SDDS_NONPERISHABLE_H_