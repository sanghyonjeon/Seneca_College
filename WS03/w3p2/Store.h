/*
*****************************************************************************
                          Workshop - #3 (Part-2)
Full Name  : Sang Hyon Jeon
Student ID#: 1123552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_STORE_H_
#define SDDS_STORE_H_

#include "Toys.h"

namespace sdds {
	const int MAX_NUM_TOYS = 10; // The maximum number of toys that could be added. 
	const int MAX_SNAME = 31; // The maximum length of a store name 

	class Store {
		Toys m_toy[MAX_NUM_TOYS]; // Static array of toys with size MAX_NUM_TOYS
		char m_sName[MAX_SNAME]; // Store name, up to MAX_SNAME size
		int m_noOfToys; //Number of toys
		int m_addToys; // Number of toys added

	public:
		Store();
		void setStore(const char* sName, int no);
		void setToys(const char* tname, int sku, double price, int age);
		void display() const;
		void find(int sku);
		void setEmpty();
	};
}

#endif // !SDDS_STORE_H_