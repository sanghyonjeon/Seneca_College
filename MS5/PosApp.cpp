/* Citation and Sources...
Final Project Milestone 51
Module: PosApp
Filename: PosApp.cpp
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
#include <iomanip>
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

	void PosApp::run() {
		int choice;

		loadRecs();

		do {
			choice = menu();

			switch (choice) {
			case 1:
				listItems();
				break;
				/*
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
				*/
			}
		} while (choice != 0);

		saveRecs();

		cout << "Goodbye!" << endl;
	}

	void PosApp::printActionTitle(const char* title) const {
		const int width = 73;
		cout << ">>>> ";
		cout << left << setw(width) << setfill('.') << title;
		cout << endl;
	}

	void PosApp::loadRecs() {
		printActionTitle("Loading Items");
		ifstream input(m_filename);

		if (!input) {
			ofstream output(m_filename);
			output.close();
		}

		// Empty the PosApp class
		for (int i = 0; i < m_noOfItems; i++) {
			delete m_items[i];
			m_items[i] = nullptr;
		}
		m_noOfItems = 0;

		// Load records
		char itemType;
		while (input && m_noOfItems < MAX_NO_ITEMS) {
			input >> itemType;

			if (itemType == 'P') {
				m_items[m_noOfItems] = new Perishable();
			}
			else if (itemType == 'N') {
				m_items[m_noOfItems] = new NonPerishable();
			}

			if (m_items[m_noOfItems]) {
				input.ignore();
				input >> *m_items[m_noOfItems];
				m_noOfItems++;
			}
		}
		input.close();
	}

	void PosApp::saveRecs() {
		printActionTitle("Saving Data");
		ofstream output(m_filename);

		for (int i = 0; i < m_noOfItems; i++) {
			output << *m_items[i];
		}

		output.close();
	}

	bool compareItemsByName(const Item* a, const Item* b) {
		return strcmp(a->getName(), b->getName()) < 0;
	}

	void PosApp::listItems() {
		// Print the action title "Listing Items"
		printActionTitle("Listing Items");

		// Sort all the Items in m_items array based on their name in ascending order using selection sort
		for (int i = 0; i < m_noOfItems - 1; ++i) {
			int minIndex = i;
			for (int j = i + 1; j < m_noOfItems - 1; ++j) {
				if (compareItemsByName(m_items[j], m_items[minIndex])) {
					minIndex = j;
				}
			}
			if (minIndex != i) {
				Item* temp = m_items[i];
				m_items[i] = m_items[minIndex];
				m_items[minIndex] = temp;
			}
		}

		// Print the Title/Header of the list
		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |\n";
		cout << "-----|--------|--------------------|-------|---|----|---------|-------------|\n";

		// Loop through the items up to m_noOfItems and display the row and the Items in POS_LIST format
		double totalAsset = 0.0;
		for (int i = 0; i < m_noOfItems - 1; ++i) {
			cout << setw(4) << setfill(' ') << right << i + 1 << " | ";
			m_items[i]->write(cout);
			cout << endl;
			totalAsset += m_items[i]->cost() * m_items[i]->quantity();
		}

		// Print the footer and the total asset
		cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
		cout << setw(36) << right << "Total Asset: $  | " << setw(14) << right << fixed << setprecision(2) << totalAsset << "|" << endl;
		cout << "-----------------------------------------------^--------------^" << endl;
	}

	/*
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

void PosApp::POS() {
	cout << ">>>> Starting Point of Sale.................................................." << endl;
	cout << "Running POS()" << endl;
}
*/    
}