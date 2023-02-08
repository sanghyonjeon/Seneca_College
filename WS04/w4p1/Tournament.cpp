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
#include "Tournament.h"

using namespace std;

namespace sdds {
    Tournament::Tournament() {
        setEmpty();
    }

    Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
            setTournament(name, noOfteam, soccer);
        
    }

    void Tournament::setTournament(const char* name, int noOfteams, const SoccerTeam* soccer) {
        bool valid = (name != nullptr && strlen(name) > 0 && noOfteams > 0 && soccer != nullptr);

        if (valid) {
            m_num = noOfteams;
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_soccer = new SoccerTeam[m_num];
            for (int i = 0; i < m_num; i++) {
                m_soccer[i].m_fines = soccer[i].m_fines;
                m_soccer[i].m_goals = soccer[i].m_goals;
                m_soccer[i].m_noFouls = soccer[i].m_noFouls;
                strcpy(m_soccer[i].m_teamName, soccer[i].m_teamName);
            }
        }
        else {
            setEmpty();
        }
    }

    void Tournament::setEmpty() {
        m_name = nullptr;
        m_soccer = nullptr;
        m_num = 0;
    }

    bool Tournament::isEmpty() const {
        bool valid = (m_name != nullptr && m_soccer != nullptr && m_num >= 0);

        return valid;
    }

    Tournament& Tournament::match(const SoccerTeam* ls) {
        

        for (int i = 0; i < m_num; i++) {
            for (int j = i + 1; j < m_num; j++) {
                int fouls1 = m_soccer[i].fouls();
                int fouls2 = m_soccer[j].fouls();

                if (m_soccer[i].m_goals < 0) {
                    m_soccer[i].m_goals = 0;
                }
                if (fouls1 < fouls2) {
                    m_soccer[j].m_noFouls = fouls2 * 2;
                    m_soccer[j].setFine(m_soccer[j].fine() * 1.2, fouls2 * 2);
                    m_soccer[i].m_goals++;
                    if (m_soccer[j].fouls() > MAX_FOUL) {
                        m_soccer[j].m_noFouls = -1;
                    }
                }
                else {
                    m_soccer[i].m_noFouls = fouls1 * 2;
                    m_soccer[i].setFine(m_soccer[i].fine() * 1.2, fouls1 * 2);
                    m_soccer[j].m_goals++;
                    if (m_soccer[i].fouls() > MAX_FOUL) {
                        m_soccer[i].m_noFouls = -1;
                    }
                }
            }
        }
        return *this;
    }

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
            for (int i = 0; i < m_num; i++) {
                m_soccer[i].display();
            }
        }
        else {
            cout << "Invalid Tournament";
        }
        return cout;
    }

    Tournament::~Tournament() {
        delete[] m_name;
        delete[] m_soccer;
    }
}