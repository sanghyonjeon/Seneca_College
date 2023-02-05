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
            cout << left << setw(15) << m_tname;
            cout << setw(10) << m_sku;
            cout << setw(6) << m_age;
            cout << fixed << setprecision(2) << setw(12) << m_price;
            if (m_onSale) {
                cout << setw(10) << "On Sale" << endl;
            }
            else {
                cout << setw(8) << endl;
            }
        }
    }

    int Toys::getSku() const {
        return m_sku;
    }
}