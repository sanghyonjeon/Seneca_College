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
#ifndef SDDS_TOYS_H_
#define SDDS_TOYS_H_

namespace sdds {
    const int MAX_TNAME = 31; // The maximum length of a Toy name

    class Toys {
        char m_tname[MAX_TNAME]; // Toy name, up to MAX_TNAME size
        int m_sku; //SKU number, maximum 8 digits long
        double m_price; // Toy price
        int m_age; // Toy according to age group
        bool m_onSale; // Keep tracks of whether toys are on sale or not

    public:
        Toys();
        void addToys(const char* tname, int sku, double price, int age);
        void isSale(bool sale);
        void calSale();
        void display() const;

        int getSku() const;
    };
}

#endif // !SDDS_TOYS_H_