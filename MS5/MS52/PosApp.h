/* Citation and Sources...
Final Project Milestone 52
Module: PosApp
Filename: PosApp.h
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
#ifndef POSAPP_H
#define POSAPP_H

#include <iostream>
#include <fstream>
#include "Perishable.h"
#include "NonPerishable.h"
#include "POS.h"

namespace sdds {
    const int MAX_FILENAME_LENGTH = 128;

    class PosApp {
        char m_filename[MAX_FILENAME_LENGTH];
        Item* m_items[MAX_NO_ITEMS]; // Iptr
        int m_noOfItems; // nptr
        void printActionTitle(const char* title) const;

        void loadRecs();
        void saveRecs();
        void listItems();

        int menu();

        // MS52 *************************************************************************
        void addItem();
        //void removeItem();
        //void stockItem();
        //void POS();

    public:
        PosApp(const char* filename);
		PosApp(const PosApp& src) = delete;
		PosApp& operator=(const PosApp& src) = delete;
        ~PosApp();

		void run();
    };
}
#endif // !SDDS_POSAPP_H_