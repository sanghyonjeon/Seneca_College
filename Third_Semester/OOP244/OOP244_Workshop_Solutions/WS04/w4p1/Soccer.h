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
#ifndef SDDS_SOCCER_H_
#define SDDS_SOCCER_H_
#include <iostream>

namespace sdds {
    const int MAX_FOUL = 4; // Maximum number of fouls

    struct SoccerTeam {
        // Member Variables
        char m_teamName[41]; // A statically allocated Cstring with size 41
        int m_noFouls; // Number of fouls
        double m_fines; // Amount of fines in dollars
        int m_goals; // Number of goals

        // Constructors & Destructor
        SoccerTeam();
        SoccerTeam(const char* tname, double fines, int foul);
        ~SoccerTeam();

        // Member Functions
        void setTeam(const SoccerTeam& team);
        void setName(const char* tname);
        void setFine(double fines, int foul);
        void setEmpty();
        bool isEmpty() const;
        void calFines();
        int fouls() const;

        std::ostream& display()const;
    };
}
#endif // !SDDS_SOCCER_H_