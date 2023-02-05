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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Store.h"
#include "Toys.h"

using namespace std;

namespace sdds {
	Store::Store() {
		m_sName[0] = '\0';
		m_noOfToys = 0;
		m_addToys = 0;
	}

	void Store::setStore(const char* sName, int no) {
		if (sName != nullptr
			&& sName[0] != '\0'
			&& no >= 0) {
			strcpy(m_sName, sName);
			m_noOfToys = no;
			m_addToys = 0;
		}
		else {
			setEmpty();
		}
	}

	void Store::setToys(const char* tname, int sku, double price, int age) {
		if (m_addToys < m_noOfToys)
		{
			m_toy[m_addToys].addToys(tname, sku, price, age);
			m_addToys++;
		}
	}

	void Store::display() const {
		if (m_noOfToys > 0) {
			cout << setfill('*') << setw(60) << "*" << endl;
			cout << m_sName << endl;
			cout << setfill('*') << setw(60) << "*" << endl;
			cout << "list of the toys" << endl;
			cout << setfill(' ') << setw(30) << "SKU" << setw(10) << "Age" << setw(11) << "Price" << setw(10) << "Sale" << endl;
			for (int i = 0; i < m_noOfToys; i++) {
				m_toy[i].display();
			}
		}
		else {
			cout << "Invalid Store" << endl;
		}
	}

	void Store::find(int sku) {
		for (int i = 0; i < m_addToys; i++) {
			if (m_toy[i].m_sku == sku) {
				m_toy[i].m_onSale = true;
				m_toy[i].calSale();
			}
		}
	}

	void Store::setEmpty() {
		m_sName[0] = '\0';
		m_noOfToys = 0;
		m_addToys = 0;
	}
}