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
#ifndef SDDS_SOCCERTEAM_H_
#define SDDS_SOCCERTEAM_H_
#include <iostream>

namespace sdds {
    const int MAX_FOUL = 4; //maximum number of fouls

    struct SoccerTeam
    {
        SoccerTeam();
        SoccerTeam(const char* tname, double fines, int foul);

        void setTeam(const SoccerTeam& team);
        void setName(const char* tname);
        void setFine(double fines, int foul);
        void setEmpty();
        bool isEmpty() const;
        void calFines();
        int fouls() const;
        double fine() const;

        std::ostream& display()const;

        char m_teamName[41]; //a statically allocated Cstring with size 41
        int m_noFouls; //number of fouls
        double m_fines; //fines amount
        int m_goals; //number of goals
    };
}
#endif // !SDDS_SOCCERTEAM_H_