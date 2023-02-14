/*
*****************************************************************************
                          Workshop - #5 (Part-2)
Full Name  : Sang Hyon Jeon
Student ID#: 1123552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_BUS_H_
#define SDDS_BUS_H_
#include <iostream>

namespace sdds {
    // Constant Values
    const double TicketPrice = 125.34;

    class Bus {
        // Member Variables
        int m_seats;
        int m_passengers;

        // Private Member Functions
        void setOutOfService();
        void voiddrawBus(int seats, int noOfPassengers, std::ostream& ostr) const;

        // Public Member Functions
    public:
        // Constructor
        Bus(int seats = 20, int passengers = 0);

        // Member Functions
        bool isOutOfService(int m_seats, int m_passengers) const;
        int getPassengers() const;
        int getSeats() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr = std::cin);

        // Type Conversion Operator Overloads
        operator bool() const;
        operator int() const;
        operator double() const;

        // Unary Operator Overloads
        bool operator--();
        bool operator++();
        bool operator--(int);
        bool operator++(int);

        // Binary Member Operators
        Bus& operator=(int value);
        Bus& operator+=(int value);
        Bus& operator+=(Bus& right);
        bool operator==(const Bus& right) const;
    };
    // Helper Binary Operator Overload
    int operator+(int left, const Bus& right);
    std::ostream& operator<<(std::ostream& ostr, const Bus& right);
    std::istream& operator>>(std::istream& istr, Bus& right);
}
#endif // !SDDS_BUS_H_