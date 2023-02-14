/*
*****************************************************************************
                          Workshop - #5 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 1123552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_EGGCARTON_H_
#define SDDS_EGGCARTON_H_
#include <iostream>

namespace sdds {
    // Constant Values (Weights are in Grams)
    const int RegularEggWeight = 50;
    const int JumboEggWeight = 75;
    const double GramsToKilos = 0.001;

    class EggCarton {
        // Member variables
        int m_size;
        int m_noOfEggs;
        bool m_jumbo;

        // Private Member Functions
        void setBroken();
        std::ostream& displayCarton(int size, int noOfEggs, bool jumbo, std::ostream& ostr)const;

        // Public Member Functions
    public:
        // Constructor
        EggCarton(int size = 6, int noOfEggs = 0, bool jumbo = false);

        // Member Functions
        bool isBroken(int m_size, int m_noOfEggs) const;
        int getNoOfEggs() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr = std::cin);

        // Type Conversion Operator Overloads
        operator bool() const;
        operator int() const;
        operator double() const;

        // Unary Operator Overloads
        EggCarton& operator--();
        EggCarton& operator++();
        EggCarton operator--(int);
        EggCarton operator++(int);

        // Binary Member Operators
        EggCarton& operator=(int value);
        EggCarton& operator+=(int value);
        EggCarton& operator+=(EggCarton& right);
        bool operator==(const EggCarton& right) const;
    };
    // Helper Binary Operator Overload
    int operator+(int left, const EggCarton& right);
    std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);
    std::istream& operator>>(std::istream& istr, EggCarton& right);
}
#endif // !SDDS_EGGCARTON_H_

