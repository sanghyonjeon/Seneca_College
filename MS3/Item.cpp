/* Citation and Sources...
Final Project Milestone 3
Module: Item
Filename: Item.cpp
Version: 1.0
Author: Sang Hyon Jeon
Revision History
-----------------------------------------------------------
Date        Reason
2023/03/29  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"
#include <cstring>
#include <iomanip>

using namespace std;

namespace sdds {
	Item::Item() {
		m_sku[0] = '\0';
		m_itemName = nullptr;
		m_price = 0.0;
		m_taxed = false;
		m_quantity = 0;
		m_displayType = 0;
	}

	Item::Item(const Item& src) {
		*this = src;
	}

	Item& Item::operator=(const Item& src) {
		if (this != &src) {
			strncpy(m_sku, src.m_sku, MAX_SKU_LEN + 1);
			m_sku[MAX_SKU_LEN] = '\0';

			delete[] m_itemName;
			if (src.m_itemName) {
				m_itemName = new char[strlen(src.m_itemName) + 1];
				strcpy(m_itemName, src.m_itemName);
			}
			else {
				m_itemName = nullptr;
			}

			m_price = src.m_price;
			m_taxed = src.m_taxed;
			m_quantity = src.m_quantity;
			m_displayType = src.m_displayType;
			m_error = src.m_error;
		}
		return *this;
	}

	Item::~Item() {
		delete[] m_itemName;
	}

	bool Item::operator==(const char* sku) const {
		return strcmp(m_sku, sku) == 0;
	}

	bool Item::operator>(const Item& other) const {
		return strcmp(m_itemName, other.m_itemName) > 0;
	}

	int Item::operator+=(int quantity) {
		m_quantity += quantity;
		return m_quantity;
	}

	int Item::operator-=(int quantity) {
		m_quantity -= quantity;
		return m_quantity;
	}

	Item::operator bool() const {
		return m_error.isClear();
	}

	Item& Item::displayType(int type) {
		m_displayType = type;
		return *this;
	}

	double Item::cost() const {
		return m_taxed ? m_price * (1 + TAX) : m_price;
	}

	int Item::quantity() const {
		return m_quantity;
	}

	Item& Item::clear() {
		m_error.clear();
		return *this;
	}

	std::istream& Item::read(std::istream& is) {
		m_error.clear();

		char sku[MAX_SKU_LEN + 1];
		char name[MAX_NAME_LEN + 1];
		double price;
		char taxed;
		int quantity;

		// Read SKU
		cout << "Sku";
		do {
			cout << "\n> ";
			is.getline(sku, MAX_SKU_LEN + 2);
			if (strlen(sku) > MAX_SKU_LEN) {
				cout << "SKU too long";
			}
		} while (strlen(sku) > MAX_SKU_LEN);

		// Read Name
		cout << "Name";
		do {
			cout << "\n> ";
			is.getline(name, MAX_NAME_LEN + 2);
			if (strlen(name) > MAX_NAME_LEN) {
				cout << "Item name too long";
				is.clear();
				is.ignore(10000, '\n');

			}
		} while (strlen(name) > MAX_NAME_LEN);

		// Read Price
		cout << "Price";
		do {
			cout << "\n> ";
			is >> price;
			if (is.fail() || price < 0) {
				cout << "Invalid price value";
				is.clear();
				is.ignore(10000, '\n');
			}
		} while (!price || price < 0);

		is.ignore(); // Ignore the delimiter

		// Read Taxed
		cout << "Taxed?\n(Y)es/(N)o: ";
		do {
			is >> taxed;
			if (taxed != 'y' && taxed != 'Y' && taxed != 'n' && taxed != 'N') {
				cout << "Only 'y' and 'n' are acceptable: ";
				is.clear();
				is.ignore(10000, '\n');
			}
		} while (taxed != 'y' && taxed != 'Y' && taxed != 'n' && taxed != 'N');

		is.ignore(); // Ignore the delimiter

		// Read Quantity
		cout << "Quantity";
		do {
			cout << "\n> ";
			is >> quantity;
			if (is.fail() || quantity < 1 || quantity > 99) {
				cout << "Invalid quantity value";
				is.clear();
				is.ignore(10000, '\n');
			}
		} while (!quantity || quantity < 1 || quantity > 99);

		is.ignore(); // Ignore the delimiter

		// Assign values to data members
		strncpy(m_sku, sku, MAX_SKU_LEN);
		m_sku[MAX_SKU_LEN] = '\0';

		m_itemName = new char[MAX_NAME_LEN + 1];
		strncpy(m_itemName, name, MAX_NAME_LEN);
		m_itemName[MAX_NAME_LEN] = '\0';

		m_price = price;
		m_taxed = (taxed == 'y' || taxed == 'Y');
		m_quantity = quantity;

		return is;
	}

	std::ostream& Item::write(std::ostream& os) const {
		if (m_error.isClear()) {
			if (m_displayType == POS_LIST) {
				os << '|' << setw(20) << left << m_itemName;
				os << '|' << setw(7) << right << fixed << setprecision(2) << cost();
				os << '|' << setw(3) << right << (m_taxed ? "T" : " ") << '|';
				os << setw(4) << right << quantity() << '|';
				os << setw(9) << right << cost() << '|';
			}
			else if (m_displayType == POS_FORM) {
				os << "=============v" << endl;
				os << setw(12) << left << "Name:" << m_itemName << endl;
				os << setw(12) << left << "Sku:" << m_sku << endl;
				os << setw(12) << left << "Price:" << fixed << setprecision(2) << m_price << endl;

				if (m_taxed) {
					os << setw(12) << left << "Price + tax:" << fixed << setprecision(2) << cost() << endl;
				}
				else {
					os << setw(12) << left << "Price + tax:" << "N/A" << endl;
				}

				os << setw(12) << left << "Stock Qty:" << quantity() << endl;
			}
		}
		else {
			os << m_error;
		}
		return os;
	}

	std::ifstream& Item::load(std::ifstream& ifs) {
		char sku[MAX_SKU_LEN + 1];
		char* itemName = nullptr;
		double price;
		char taxedChar;
		bool taxed;
		int quantity;

		if (ifs.get(sku, MAX_SKU_LEN + 1, ',')) {
			ifs.ignore();
			itemName = new char[MAX_NAME_LEN + 1];
			ifs.getline(itemName, MAX_NAME_LEN, ',');
			ifs >> price;
			ifs.ignore();
			ifs >> taxedChar;
			taxed = (taxedChar == '1');
			ifs.ignore();
			ifs >> quantity;
			ifs.ignore();

			strncpy(m_sku, sku, MAX_SKU_LEN);
			m_sku[MAX_SKU_LEN] = '\0';

			delete[] m_itemName;
			m_itemName = itemName;

			m_price = price;
			m_taxed = taxed;
			m_quantity = quantity;
		}

		return ifs;
	}

	std::ofstream& Item::save(std::ofstream& ofs) const {
		if (m_error.isClear()) {
			ofs << itemType() << ',';
			ofs << m_sku << ',';
			ofs << m_itemName << ',';
			ofs << m_price << ',';
			ofs << (m_taxed ? "1" : "0") << ',';
			ofs << quantity();
		}
		else {
			std::cerr << m_error << endl;
		}
		return ofs;
	}

	std::ostream& Item::bprint(std::ostream& os) const {
		os << "| " << setw(20) << left << string(m_itemName).substr(0, 20)
			<< "| " << setw(9) << right << fixed << setprecision(2) << cost()
			<< "| " << setw(2) << (m_taxed ? "T" : " ") << "|"
			<< endl;
		return os;
	}

	double& operator+=(double& lhs, const Item& rhs) {
		lhs += rhs.cost();
		return lhs;
	}
}