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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Bus.h"

using namespace std;

namespace sdds {
    // Constructor
    Bus::Bus(int seats, int passengers) {
        bool validSeats = (seats % 2 == 0 && seats >= 10 && seats <= 40);
        bool validPassengers = (passengers >= 0 && passengers <= seats);

        if (validSeats && validPassengers) {
            m_seats = seats;
            m_passengers = passengers;
        }
        else {
            setOutOfService();
        }
    }

    // Member Functions
    bool Bus::isOutOfService(int m_seats, int m_passengers) const {
        bool serviceStatus = (m_seats == -1 && m_passengers == -1);

        return serviceStatus;
    }

    int Bus::getPassengers() const {
        return m_passengers;
    }

    int Bus::getSeats() const {
        return m_seats;
    }

    void Bus::setOutOfService() {
        m_seats = -1;
        m_passengers = -1;
    }

    std::ostream& Bus::display(std::ostream& ostr) const {
        if (isOutOfService(m_seats, m_passengers)) {
            ostr << "Out of service!" << std::endl;
        }
        else {
            voiddrawBus(m_seats, m_passengers, ostr);
        }
        return ostr;
    }

    void Bus::voiddrawBus(int seats, int noOfPassengers, std::ostream& ostr) const {
        int i, p;
        ostr.fill('_');
        ostr.width((seats / 2) * 3 + 4);
        ostr << "_";
        ostr << endl << "| ";
        for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
        ostr << "|_\\_" << endl;
        ostr << "| ";
        ostr.fill(' ');
        ostr.width(((seats / 2) * 3 - 14) / 2);
        ostr << " " << "Seneca College";
        ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
        ostr << " " << "    )" << endl;
        ostr << "`---OO";
        ostr.fill('-');
        ostr.width((seats / 2) * 3 - 5);
        ostr << "-" << "O---'" << endl;
    }

    std::istream& Bus::read(std::istream& istr) {
        int seats;
        int passengers;
        bool flag = false;

        istr >> seats;
        if (seats % 2 == 0 && seats >= 10 && seats <= 40) {
            m_seats = seats;
        }
        else {
            flag = true;
        }
        istr.ignore(1);

        istr >> passengers;
        if (passengers >= 0 && passengers <= seats) {
            m_passengers = passengers;
        }
        else {
            flag = true;
        }

        if (flag) {
            setOutOfService();
        }

        return istr;
    }

    // Type Conversion Operator Overloads
    Bus::operator bool() const {
        return !isOutOfService(m_seats, m_passengers);
    }

    Bus::operator int() const {
        return (bool(*this)) ? m_passengers : -1;
    }

    Bus::operator double() const {
        return (bool(*this)) ? (m_passengers * TicketPrice) : -1.0;
    }

    // Unary Operator Overloads
    bool Bus::operator--() {
        bool flag = false;
        
        if (bool(*this)) {
            m_passengers--;
            flag = true;
        }

        return flag;
    }

    bool Bus::operator++() {
        bool flag = false;

        if (bool(*this) && m_passengers < m_seats) {
            m_passengers++;
            flag = true;
        }

        return flag;
    }

    bool Bus::operator--(int) {
        bool flag = false;

        if (bool(*this)) {
            m_passengers--;
            flag = true;
        }

        return flag;
    }

    bool Bus::operator++(int) {
        bool flag = false;

        if (bool(*this) && m_passengers < m_seats) {
            m_passengers++;
            flag = true;
        }

        return flag;
    }

    // Binary Member Operators
    Bus& Bus::operator=(int value) {
        m_passengers = value;

        if (m_passengers > m_seats) {
            setOutOfService();
        }

        return *this;
    }

    Bus& Bus::operator+=(int value) {
        if (bool(*this)) {
            m_passengers += value;
        }

        if (m_passengers > m_seats) {
            setOutOfService();
        }

        return *this;
    }

    Bus& Bus::operator+=(Bus& right) {
        if (bool(*this) && bool(right)) {
            int emptySpots = m_seats - m_passengers;

            if (emptySpots >= right.m_passengers) {
                m_passengers += right.m_passengers;
                right.m_passengers = 0;
            }
            else {
                m_passengers = m_seats;
                right.m_passengers -= emptySpots;
            }
        }

        return *this;
    }

    bool Bus::operator==(const Bus& right) const {
        bool flag = false;
        
        if (bool(*this) && bool(right) && m_passengers == right.m_passengers) {
            flag = true;
        }

        return flag;
    }

    int operator+(int left, const Bus& right) {
        return left + (right.isOutOfService(right.getSeats(), right.getPassengers()) ? 0 : right.getPassengers());
    }

    std::ostream& operator<<(std::ostream& ostr, const Bus& right) {
        right.display(ostr);

        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Bus& right) {
        right.read(istr);

        return istr;
    }
}