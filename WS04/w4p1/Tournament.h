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
#ifndef SDDS_TOURNAMENT_H_
#define SDDS_TOURNAMENT_H_
#include <iostream>
#include "Soccer.h"

namespace sdds {
    class Tournament {
        // Member Variables
        char* m_name; // Points to a dynamically allocated Cstring
        int m_num; // Size of the dynamically allocated array of soccer team
        SoccerTeam* m_soccer = nullptr; // Pointer to the dynamically allocated array of soccerTeam 

    public:
        // Constructors & Destructor
        Tournament();
        Tournament(const char* name, int noOfteam, const SoccerTeam* soccer);
        ~Tournament();

        // Member Functions
        void setTournament(const char* name, int noOfteam, const SoccerTeam* soccer);
        void setEmpty();
        bool isEmpty() const;
        Tournament& match(const SoccerTeam* ls);

        std::ostream & display() const;
    };
}
#endif // !SDDS_TOURNAMENT_H_