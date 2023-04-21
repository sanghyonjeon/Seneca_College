/* Citation and Sources...
Final Project Milestone 4
Module: Item
Filename: Item.h
Version: 1.0
Author: Sang Hyon Jeon
Revision History
-----------------------------------------------------------
Date        Reason
2023/04/02  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
#include "POS.h"
#include "Error.h"
#include "PosIO.h"

namespace sdds {
	class Item : public PosIO {
		char m_sku[MAX_SKU_LEN + 1];
		char* m_itemName;
		double m_price;
		bool m_taxed;
		int m_quantity;
		
	protected:
		int m_displayType; 
		Error m_error;

	public:
		Item();
		Item(const Item& src);
		Item& operator=(const Item& src);
		~Item();

		bool operator==(const char* sku) const;
		bool operator>(const Item& other) const;
		int operator+=(int quantity);
		int operator-=(int quantity);

		operator bool() const;

		virtual char itemType() const = 0;
		Item& displayType(int type);
		
		double cost() const;
		int quantity() const;

		Item& clear();

		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os) const;
		std::ifstream& load(std::ifstream& ifs);
		std::ofstream& save(std::ofstream& ofs) const;
		std::ostream& bprint(std::ostream& os) const;
	};
	double& operator+=(double& lhs, const Item& rhs);
}
#endif // !SDDS_ITEM_H_