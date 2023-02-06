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

    Tournament::Tournament(const char* tname, int noOfteam, const SoccerTeam* soccer)
    {
        setTournament(tname, noOfteam, soccer);
    }

    void Tournament::setTournament(const char* name, int noOfteams, const SoccerTeam* soccer) {
        if (name == nullptr || name[0] == '\0' || noOfteams <= 0 || soccer == nullptr) {
            setEmpty();
        }
        else {
            m_num = noOfteams;
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_soccer = new SoccerTeam[m_num];
            for (int i = 0; i < m_num; i++) {
                m_soccer[i] = soccer[i];
            }
        }
    }

    void Tournament::setEmpty() {
        m_name = nullptr;
        m_num = 0;
        m_soccer = nullptr;
    }

    bool Tournament::isEmpty() const {
        return m_name == nullptr || m_soccer == nullptr || m_num <= 0;
    }

    Tournament& Tournament::match(const SoccerTeam* ls) {
        for (int i = 0; i < m_num; i++) {
            for (int j = i + 1; j < m_num; j++) {
                int fouls1 = m_soccer[i].fouls();
                int fouls2 = m_soccer[j].fouls();
                if (fouls1 < fouls2) {
                    m_soccer[j].m_noFouls = fouls2;
                    m_soccer[j].setFine(m_soccer[j].fine() * 1.2, fouls2);
                    m_soccer[i].m_goals++;
                    if (m_soccer[j].fouls() > MAX_FOUL) {
                        m_soccer[j].m_noFouls = -1;
                    }
                }
                else {
                    m_soccer[i].m_noFouls = fouls1;
                    m_soccer[i].setFine(m_soccer[i].fine() * 1.2, fouls1);
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
            std::cout << "Invalid Tournament" << std::endl;
        }
        else {
            std::cout << "Tournament name: " << m_name << std::endl;
            std::cout << "list of the teams" << std::endl;
            std::cout.width(45);
            std::cout.fill(' ');
            std::cout << "Fines";
            std::cout.width(10);
            std::cout << "Fouls";
            std::cout.width(10);
            std::cout << "Goals" << std::endl;
            for (int i = 0; i < m_num; i++) {
                m_soccer[i].display();
            }
        }
        return std::cout;
    }

    Tournament::~Tournament() {
        delete[] m_name;
        delete[] m_soccer;
    }
}