/*
*****************************************************************************
                          Workshop - #4 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 113552194
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
#include "Tournament.h"

using namespace std;

namespace sdds {
    // Default constructor
    Tournament::Tournament() {
        setEmpty();
    }

    // Three argument constructor
    Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
            setTournament(name, noOfteam, soccer);
    }

    // If all the received arguments are valid, this function will set the values to the
    // appropriate data members. Otherwise, it will set the Tournament to an empty state
    void Tournament::setTournament(const char* name, int noOfteams, const SoccerTeam* soccer) {
        bool valid = (name != nullptr && strlen(name) > 0 && noOfteams > 0 && soccer != nullptr);

        if (valid) {
            m_num = noOfteams;
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_soccer = new SoccerTeam[m_num];
            for (int i = 0; i < m_num; i++) {
                m_soccer[i].setTeam(soccer[i]);
                m_soccer[i].m_goals = soccer[i].m_goals;
            }
        }
        else {
            setEmpty();
        }
    }

    // Sets the Tournamnet object to an Empty State
    void Tournament::setEmpty() {
        m_name = nullptr;
        m_soccer = nullptr;
        m_num = 0;
    }

    // Returns true if m_name and m_soccer is not null and m_num is greater than or equal to 0
    bool Tournament::isEmpty() const {
        bool valid = (m_name != nullptr && m_soccer != nullptr && m_num >= 0);

        return valid;
    }

    // This function will find out the winner between 2 soccer teams by having matches.
    Tournament& Tournament::match(const SoccerTeam* ls) {
        for (int i = 0; i < 1; i++) {
            if (m_soccer[i].fouls() < m_soccer[i + 1].fouls()) {
                m_soccer[i + 1].m_noFouls *= 2;
                m_soccer[i + 1].calFines();
                m_soccer[i].m_goals++;
                if (m_soccer[i + 1].m_noFouls > MAX_FOUL) {
                    m_soccer[i + 1].m_noFouls = -1;
                }
            }
        }
        return *this;
    }

    // Displays information about the tournament outcome
    std::ostream& Tournament::display() const {
        if (isEmpty()) {
            cout << "Tournament name: " << m_name << endl;
            cout << "list of the teams" << endl;
            cout.width(45);
            cout.fill(' ');
            cout << "Fines";
            cout.width(10);
            cout << "Fouls";
            cout.width(10);
            cout << "Goals" << endl;
            for (int i = 0; i < m_num; i++) {\
                cout << "Team[" << i + 1 << "] :";
                m_soccer[i].display();
            }
        }
        else {
            cout << "Invalid Tournament";
        }
        return cout;
    }

    // Destructor to deallocate the memory allocated by m_name and m_soccer.
    Tournament::~Tournament() {
        delete[] m_name;
        delete[] m_soccer;
    }
}