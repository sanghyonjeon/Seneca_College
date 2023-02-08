/*
*****************************************************************************
                          Workshop - #4 (Part-1)
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
#include "Soccer.h"

using namespace std;

namespace sdds {
    // Default constructor
    SoccerTeam::SoccerTeam() {
        setEmpty();
    }

    // Three argument constructor
    SoccerTeam::SoccerTeam(const char* tname, double fines, int foul) {
        bool valid = (strlen(tname) > 0 && fines >= 0 && foul >= 0);

        if (valid) {
            setName(tname);
            setFine(fines, foul);
            m_goals = 0;
        }
        else {
            setEmpty();
        }
    }

    // It will set the team name, fine and fouls of the team.
    void SoccerTeam::setTeam(const SoccerTeam& team) {
        setName(team.m_teamName);
        setFine(team.m_fines, team.m_noFouls);
    }

    // If the received name pointer is valid, it will copy the received name to the data member m_teamName
    void SoccerTeam::setName(const char* tname) {
        bool valid = (strlen(tname) > 0);

        if (valid)
        {
            strcpy(m_teamName, tname);
        }
    }

    // If received values are valid, it will set the values to the appropriate data members
    // Otherwise, it will set the soccerTeam object to an empty state
    void SoccerTeam::setFine(double fines, int foul) {
        bool valid = (fines >= 0 && foul >= 0);

        if (valid)
        {
            m_fines = fines;
            m_noFouls = foul;
        }
        else
        {
            setEmpty();
        }
    }

    // Sets the soccerTeam object to an Empty State
    void SoccerTeam::setEmpty() {
        m_teamName[0] = '\0';
        m_noFouls = -1;
        m_fines = -1;
        m_goals = 0;
    }

    // Returns true if m_teamName is not null, m_fines and m_noFouls is greater than or equal to 0
    bool SoccerTeam::isEmpty() const {
        bool valid = (m_teamName[0] != '\0' && m_fines >= 0 && m_noFouls >= 0);

        return (valid);
    }

    // This function will increases the fine by 20% of the old fine value.
    void SoccerTeam::calFines() {
        m_fines *= 1.2;
    }

    // It will return the m_noFoul
    int SoccerTeam::fouls() const {
        return m_noFouls;
    }

    // Displays information and stats about the team
    std::ostream& SoccerTeam::display() const {
        if (isEmpty()) {
            cout.width(30);
            cout.fill(' ');
            cout.setf(ios::left);
            cout<< m_teamName;
            cout.unsetf(ios::left);
            cout.width(6);
            cout.precision(2);
            cout.setf(ios::fixed);
            cout << m_fines;
            cout.unsetf(ios::fixed);
            cout.width(6);
            cout << m_noFouls;
            cout.width(10);
            cout << m_goals;
            if (m_goals > 0) {
                cout << "w" << endl;
            }
            else {
                cout << " " << endl;
            }
        }
        else {
            cout << "Invalid Team";
        }
        return cout;
    }

    // Destructor
    SoccerTeam::~SoccerTeam() {}
}