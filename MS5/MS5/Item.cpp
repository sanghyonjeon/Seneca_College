/* Citation and Sources...
Final Project Milestone 5
Module: Item
Filename: Item.cpp
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

		char sku[MAX_SKU_LEN + 2];
		char name[MAX_NAME_LEN + 2];
		double price;
		char taxed;
		int quantity;

		// Read SKU
		cout << "Sku";
		do {
			cout << "\n> ";
			is.getline(sku, MAX_SKU_LEN + 2);
			if (strlen(sku) > MAX_SKU_LEN) {
				cout << ERROR_POS_SKU;
			}
		} while (strlen(sku) > MAX_SKU_LEN);

		// Read Name
		cout << "Name";
		do {
			cout << "\n> ";
			is.getline(name, MAX_NAME_LEN + 2);
			if (strlen(name) > MAX_NAME_LEN) {
				cout << ERROR_POS_NAME;
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
				cout << ERROR_POS_PRICE;
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
				cout << ERROR_POS_QTY;
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
		char itemNameSubstring[21];
		strncpy(itemNameSubstring, m_itemName, 20);
		itemNameSubstring[20] = '\0';

		if (m_error.isClear()) {
			if (m_displayType == POS_LIST) {
				os << setfill(' ') << setw(7) << left << m_sku;
				os << '|' << setw(20) << left << itemNameSubstring;
				os << '|' << setw(7) << right << fixed << setprecision(2) << m_price;
				os << '|' << setw(3) << left << (m_taxed ? " X" : " ") << '|';
				os << setw(4) << right << quantity() << '|';
				os << setw(9) << right << cost() * quantity() << '|';
			}
			else if (m_displayType == POS_FORM) {
				os << setfill(' ') << "=============v" << endl;
				os << setw(13) << left << "Name:" << m_itemName << endl;
				os << setw(13) << left << "Sku:" << m_sku << endl;
				os << setw(13) << left << "Price:" << fixed << setprecision(2) << m_price << endl;

				if (m_taxed) {
					os << setw(13) << left << "Price + tax:" << fixed << setprecision(2) << cost() << endl;
				}
				else {
					os << setw(13) << left << "Price + tax:" << "N/A" << endl;
				}

				os << setw(13) << left << "Stock Qty:" << quantity() << endl;
			}
		}
		else {
			os << m_error;
		}
		return os;
	}

	std::ifstream& Item::load(std::ifstream& ifs) {
		m_error.clear();
		if (ifs) {
			char sku[MAX_SKU_LEN + 2]{};
			char name[MAX_NAME_LEN + 2]{};
			double price{};
			int qty{};
			bool tax{};

			ifs.get(sku, MAX_SKU_LEN + 2, ',');
			ifs.ignore(1000, ',');
			ifs.get(name, MAX_NAME_LEN + 2, ',');
			ifs.ignore(1000, ',');
			ifs >> price;
			ifs.ignore();
			ifs >> tax;
			ifs.ignore();
			ifs >> qty;

			if (ifs) {
				// Validate SKU
				if (strlen(sku) > MAX_SKU_LEN) {
					m_error = ERROR_POS_SKU;
				}
				// Validate Name
				else if (strlen(name) > MAX_NAME_LEN) {
					m_error = ERROR_POS_NAME;
				}
				// Validate Price
				else if (price < 0) {
					m_error = ERROR_POS_PRICE;
				}
				// Validate Quantity
				else if (qty < 1 || qty > 99) {
					m_error = ERROR_POS_QTY;
				}
				// If no validation errors, assign attributes
				else {
					strncpy(m_sku, sku, MAX_SKU_LEN);
					m_sku[MAX_SKU_LEN] = '\0';

					delete[] m_itemName;
					m_itemName = new char[MAX_NAME_LEN + 1];
					strncpy(m_itemName, name, MAX_NAME_LEN);
					m_itemName[MAX_NAME_LEN] = '\0';

					m_price = price;
					m_taxed = tax;
					m_quantity = qty;
				}
			}
		}
		return ifs;
	}

	std::ofstream& Item::save(std::ofstream& ofs) const {
		if (m_error.isClear()) {
			ofs << itemType() << ',';
			ofs << m_sku << ',';
			ofs << m_itemName << ',';
			ofs.setf(ios::fixed);
			ofs.precision(2);
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
		char itemNameSubstring[21];
		strncpy(itemNameSubstring, m_itemName, 20);
		itemNameSubstring[20] = '\0';

		os << setfill(' ') << "| " << setw(20) << left << itemNameSubstring
			<< "| " << setw(9) << right << fixed << setprecision(2) << cost() << " "
			<< "| " << setw(4) << (m_taxed ? "T  " : " ") << "|"
			<< endl;
		return os;
	}

	const char* Item::getName() const {
		return m_itemName;
	}

	const char* Item::getSku() const {
		return m_sku;
	}

	double& operator+=(double& lhs, const Item& rhs) {
		lhs += rhs.cost() * rhs.quantity();
		return lhs;
	}
}