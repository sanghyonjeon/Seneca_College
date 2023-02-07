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
#include "SoccerTeam.h"

using namespace std;

namespace sdds {
    SoccerTeam::SoccerTeam()
    {
        setEmpty();
    }

    SoccerTeam::SoccerTeam(const char* tname, double fines, int foul)
    {
        setFine(fines, foul);
        setName(tname);
    }

    void SoccerTeam::setTeam(const SoccerTeam& team)
    {
        setFine(team.m_fines, team.m_noFouls);
        setName(team.m_teamName);
    }

    void SoccerTeam::setName(const char* tname)
    {
        if (tname != nullptr && m_teamName[0] != '\0')
        {
            strncpy(m_teamName, tname, 41);
            m_teamName[40] = '\0';
        }
        else
        {
            setEmpty();
        }
    }

    void SoccerTeam::setFine(double fines, int foul)
    {
        if (fines >= 0 && foul >= 0)
        {
            m_fines = fines;
            m_noFouls = foul;
        }
        else
        {
            setEmpty();
        }
    }

    void SoccerTeam::setEmpty()
    {
        m_teamName[0] = '\0';
        m_noFouls = -1;
        m_fines = -1;
        m_goals = 0;
    }

    bool SoccerTeam::isEmpty() const
    {
        return (m_teamName[0] != '\0' && m_fines >= 0 && m_noFouls >= 0);
    }

    void SoccerTeam::calFines()
    {
        m_fines *= 1.2;
    }

    int SoccerTeam::fouls() const
    {
        return m_noFouls;
    }

    double SoccerTeam::fine() const
    {
        return m_fines;
    }

    std::ostream& SoccerTeam::display() const {
        if (isEmpty()) {
            cout.width(30);
            cout.fill(' ');
            cout.setf(ios::left);
            cout<< m_teamName;
            cout.unsetf(ios::left);
            cout.width(15);
            cout.precision(2);
            cout.setf(ios::fixed);
            cout << m_fines;
            cout.unsetf(ios::fixed);
            cout.width(6);
            cout << m_noFouls;
            cout.width(10);
            cout << m_goals;
            if (m_goals > 0) {
                cout << "w";
            }
            cout << endl;
        }
        else {
            cout << "Invalid Team";
        }
        return cout;
    }

    SoccerTeam::~SoccerTeam() {

    }
}