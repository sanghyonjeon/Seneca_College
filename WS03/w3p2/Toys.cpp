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
#include "Toys.h"

using namespace std;

namespace sdds {
    Toys::Toys() {
        m_tname[0] = '\0';
        m_sku = 0;
        m_price = 0;
        m_age = 0;
        m_onSale = false;
    }

    void Toys::addToys(const char* tname, int sku, double price, int age) {
        if (tname != nullptr
            && sku >= 10000000 
            && sku <= 99999999 
            && price >= 0 
            && age >= 0){
            strcpy(m_tname, tname);
            m_sku = sku;
            m_price = price;
            m_age = age;
            m_onSale = false;
        }
        else {
            m_tname[0] = '\0';
            m_sku = 0;
            m_price = 0;
            m_age = 0;
            m_onSale = false;
        }
    }

    void Toys::isSale(bool sale) {
        m_onSale = sale;
    }

    void Toys::calSale() {
        if (m_onSale) {
            m_price *= 0.8;
        }
    }

    void Toys::display() const {
        if (m_tname[0] == '\0') {
            cout << "Invalid Toy" << endl;
        }
        else {
            cout.width(15);
            cout.setf(ios::left);
            cout << m_tname;
            cout.unsetf(ios::left);
            cout.width(10);
            cout << m_sku;
            cout.width(6);
            cout << m_age;
            cout.width(12);
            cout.precision(4);
            cout << m_price;
            if (m_onSale) {
                cout.width(11);
                cout << "On Sale " << endl;
            }
            else {
                cout.width(8);
                cout << " " << endl;
            }
        }
    }

    int Toys::getSku() const {
        return m_sku;
    }

    bool Toys::setOnSale(bool onSale) {
        return m_onSale = onSale;
    }
}