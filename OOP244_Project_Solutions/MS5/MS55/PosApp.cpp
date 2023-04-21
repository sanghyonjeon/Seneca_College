/* Citation and Sources...
Final Project Milestone 55
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
#include "Utils.h"
#include "Bill.h"

using namespace std;

namespace sdds {
	PosApp::PosApp(const char* filename) : m_noOfItems(0) {
		strncpy(m_filename, filename, MAX_FILENAME_LENGTH);
		m_filename[MAX_FILENAME_LENGTH - 1] = '\0';

		for (int i = 0; i < MAX_NO_ITEMS; ++i) {
			m_items[i] = nullptr;
		}
	}

	PosApp::~PosApp() {
		for (int i = 0; i < m_noOfItems; ++i) {
			delete m_items[i];
		}
	}

	int PosApp::menu() {
		int choice;
		bool valid = false;

		cout << "The Sene-Store" << endl;
		cout << "1- List items" << endl;
		cout << "2- Add item" << endl;
		cout << "3- Remove item" << endl;
		cout << "4- Stock item" << endl;
		cout << "5- POS" << endl;
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
			//MS52*********************************************************************
			case 2:
				addItem();
				break;
			//MS53*********************************************************************
			case 3:
				removeItem();
				break;
			//MS54*********************************************************************
			case 4:
				stockItem();
				break;
			//MS55*********************************************************************
			case 5:
				POS();
				break;
			}
		} while (choice != 0);

		saveRecs();

		cout << "Goodbye!" << endl;
	}

	void PosApp::printActionTitle(const char* title) const {
		const int width = 72;
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
		bool isReading = true;
		while (input && m_noOfItems < MAX_NO_ITEMS && isReading) {
			input >> itemType;

			if (!input) {
				isReading = false;
			}
			else {
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
		}
		
		input.close();
	}

	void PosApp::saveRecs() {
		printActionTitle("Saving Data");
		ofstream output(m_filename);

		for (int i = 0; i < m_noOfItems; i++) {
			output << *m_items[i] << endl;
		}

		output.close();
	}

	bool compareItemsByName(const Item* a, const Item* b) {
		return strcmp(a->getName(), b->getName()) < 0;
	}

	void PosApp::listItems(bool showTotalAsset) {
		// Print the action title "Listing Items"
		printActionTitle("Listing Items");

		// Sort all the Items in m_items array based on their name in ascending order using selection sort
		for (int i = 0; i < m_noOfItems - 1; i++) {
			int minIndex = i;
			for (int j = i + 1; j < m_noOfItems; j++) {
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
		for (int i = 0; i < m_noOfItems; ++i) {
			if (m_items[i] != nullptr) {
				cout << setw(4) << setfill(' ') << right << i + 1 << " | ";
				m_items[i]->displayType(POS_LIST);
				m_items[i]->write(cout);
				cout << endl;
				totalAsset += m_items[i]->cost() * m_items[i]->quantity();
			}
		}

		cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;

		// Print the footer and the total asset only if showTotalAsset is true
		if (showTotalAsset) {
			cout << setw(49) << setfill(' ') << right << "Total Asset: $  | " << setw(13) << right << fixed << setprecision(2) << totalAsset << "|" << endl;
			cout << "-----------------------------------------------^--------------^" << endl << endl;
		}
	}

	// MS52 *************************************************************************
	void PosApp::addItem() {
		printActionTitle("Adding Item to the store");

		if (m_noOfItems < MAX_NO_ITEMS) {
			char perishable;
			cout << "Is the Item perishable? (Y)es/(N)o: ";
			cin >> perishable;

			Item* newItem = nullptr;
			if (tolower(perishable) == 'y') {
				newItem = new Perishable();
			}
			else {
				newItem = new NonPerishable();
			}

			bool isValid = false;
			do {
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> *newItem;

				if (!(*newItem)) {
					newItem->write(cout);
					cout << ", try again..." << endl;
				}
				else {
					isValid = true;
				}
			} while (!isValid);

			m_items[m_noOfItems] = newItem;
			m_noOfItems++;

			printActionTitle("DONE!");
		}
		else {
			cout << "Inventory Full!" << endl;
		}

		return;
	}
	
	// MS53 *************************************************************************
	int PosApp::selectItem() {
		printActionTitle("Item Selection by row number");
		cout << "Press <ENTER> to start...." << endl;
		cin.ignore(1000, '\n');

		listItems(false); // Call listItems() without showing the total asset

		int rowNumber;
		bool valid = false;

		cout << "Enter the row number: ";

		do {
			cin >> rowNumber;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Integer, try again: ";
			}
			else if (rowNumber < 1 || rowNumber > m_noOfItems) {
				cout << "[1<=value<=" << m_noOfItems << "], retry: Enter the row number: ";
			}
			else {
				valid = true;
			}
		} while (!valid);

		return rowNumber;
	}

	void PosApp::removeItem() {
		int rowNumber;

		printActionTitle("Remove Item");
		rowNumber = selectItem(); // Get the row number of the item to be removed

		if (rowNumber > 0) {
			int index = rowNumber - 1; // Convert row number to index in the m_items array

			cout << "Removing...." << endl;
			m_items[index]->displayType(POS_FORM);
			m_items[index]->write(cout); // Show the item about to be removed in POS_FROM format

			// Deallocate and remove the item from the m_items array
			delete m_items[index];
			for (int i = index; i < m_noOfItems - 1; i++) {
				m_items[i] = m_items[i + 1];
			}
			m_items[m_noOfItems - 1] = nullptr;
			m_noOfItems--;

			printActionTitle("DONE!");
		}
	}

	// MS54 *************************************************************************
	void PosApp::stockItem() {
		int rowNumber;
		int quantityToAdd;

		printActionTitle("Select an item to stock");
		rowNumber = selectItem(); // Get the row number of the item to be stocked

		if (rowNumber > 0) {
			int index = rowNumber - 1; // Convert row number to index in the m_items array

			cout << "Selected Item:" << endl;
			m_items[index]->displayType(POS_FORM);
			m_items[index]->write(cout); // Display the selected item

			cout << "Enter quantity to add: ";
			// Get an integer (fool-proof) between 1 and current number of items minus the MAX_STOCK_NUMBER
			int minValue = 1;
			int maxValue = MAX_STOCK_NUMBER - m_items[index]->quantity();
			quantityToAdd = getInt(minValue, maxValue);

			// Add the quantity to the item
			*m_items[index] += quantityToAdd;

			printActionTitle("DONE!");
		}
	}

	int PosApp::getInt(int minValue, int maxValue) {
		int value;
		bool validInput = false;

		while (!validInput) {
			cin >> value;
			if (cin.fail()) {
				// Input is not an integer
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Integer, try again: ";
			}
			else if (value < minValue || value > maxValue) {
				// Input is outside the allowed range
				cout << "[" << minValue << "<=value<=" << maxValue << "], retry: Enter quantity to add: ";
			}
			else {
				validInput = true; // Input is a valid integer within the allowed range
			}
		}

		return value;
	}

	//MS55*********************************************************************
	Item* PosApp::search(const char* sku) {
		Item* foundItem = nullptr;

		for (int i = 0; i < m_noOfItems && !foundItem; i++) {
			if (strcmp(m_items[i]->getSku(), sku) == 0) {
				foundItem = m_items[i];
			}
		}
		return foundItem;
	}

	void PosApp::POS() {
		printActionTitle("Starting Point of Sale");

		Bill bill;
		char sku[MAX_SKU_LEN + 1];
		bool isSKUEmpty = false;

		cin.clear();
		cin.ignore(1000, '\n');

		while (!isSKUEmpty) {
			cout << "Enter SKU or <ENTER> only to end sale..." << endl;
			cout << "> ";
			cin.getline(sku, MAX_SKU_LEN + 1);

			if (cin.fail()) {
				cout << "SKU too long" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else {
				isSKUEmpty = (sku[0] == '\0');
				if (!isSKUEmpty) {
					Item* foundItem = search(sku);
					if (foundItem) {
						if (foundItem->quantity() > 0) {
							foundItem->operator-= (1);
							foundItem->displayType(POS_FORM);
							foundItem->write(cout);
							cout << endl << ">>>>> Added to bill" << endl;

							bill.add(foundItem);
							cout << ">>>>> Total: " << fixed << setprecision(2) << bill.total() << endl;
						}
						else {
							cout << ERROR_POS_STOCK << endl;
						}
					}
					else {
						cout << "!!!!! Item Not Found !!!!!" << endl;
					}
				}
			}
		}
		// Print the bill
		cout.fill(' ');
		bill.print(cout);
	}
}