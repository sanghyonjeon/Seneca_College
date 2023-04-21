/* Citation and Sources...
Final Project Milestone 1
Module: PosApp
Filename: PosApp.cpp
Version: 1.0
Author: Sang Hyon Jeon
Revision History
-----------------------------------------------------------
Date        Reason
2023/03/10  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "PosApp.h"

using namespace std;

namespace sdds {
	PosApp::PosApp(const char* filename) {
		strncpy(m_filename, filename, MAX_FILENAME_LENGTH);
		m_filename[MAX_FILENAME_LENGTH] = '\0';
	}

	int PosApp::menu() {
		int choice;
		bool valid = false;

		cout << "The Sene-Store" << endl;
		cout << "1- List items" << endl;
		cout << "2- Add item" << endl;
		cout << "3- Remove item" << endl;
		cout << "4- Stock item" << endl;
		cout << "5- Point of Sale" << endl;
		cout << "0- exit program" << endl;
		cout << "> ";

		do {
			cin >> choice;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Integer, try again: ";
			}
			else if (choice < 0 || choice > 5) {
				cout << "[0<=value<=5], retry: > ";
			}
			else {
				valid = true;
			}
		} while (!valid);

		return choice;
	}

	void PosApp::addItem() {
		cout << ">>>> Adding Item to the store................................................" << endl;
		cout << "Running addItem()" << endl;
	}

	void PosApp::removeItem() {
		cout << ">>>> Remove Item............................................................." << endl;
		cout << "Running removeItem()" << endl;
	}

	void PosApp::stockItem() {
		cout << ">>>> Select an item to stock................................................." << endl;
		cout << "Running stockItem()" << endl;
	}

	void PosApp::listItems() {
		cout << ">>>> Listing Items..........................................................." << endl;
		cout << "Running listItems()" << endl;
	}

	void PosApp::POS() {
		cout << ">>>> Starting Point of Sale.................................................." << endl;
		cout << "Running POS()" << endl;
	}

	void PosApp::saveRecs() {
		cout << ">>>> Saving Data............................................................." << endl;
		cout << "Saving data in " << m_filename << endl;
	}

	void PosApp::loadRecs() {
		cout << ">>>> Loading Items..........................................................." << endl;
		cout << "Loading data from " << m_filename << endl;
	}

	void PosApp::run() {
		int choice;

		loadRecs();

		do {
			choice = menu();

			switch (choice) {
			case 1:
				listItems();
				break;
			case 2:
				addItem();
				break;
			case 3:
				removeItem();
				break;
			case 4:
				stockItem();
				break;
			case 5:
				POS();
				break;
			}
		} while (choice != 0);

		saveRecs();

		cout << "Goodbye!" << endl;
	}
}