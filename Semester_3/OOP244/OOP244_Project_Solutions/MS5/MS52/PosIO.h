/* Citation and Sources...
Final Project Milestone 52
Module: PosIO
Filename: PosIO.h
Version: 1.0
Author: Sang Hyon Jeon
Revision History
-----------------------------------------------------------
Date        Reason
2023/04/16  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_POSIO_H_
#define SDDS_POSIO_H_
#include <iostream>
#include <fstream>

namespace sdds {
	class PosIO {
    public:
        // Pure virtual functions for reading and writing
        virtual std::istream& read(std::istream& is) = 0;
        virtual std::ostream& write(std::ostream& os) const = 0;
        // Pure virtual functions for loading and saving data from files
        virtual std::ifstream& load(std::ifstream& ifs) = 0;
        virtual std::ofstream& save(std::ofstream& ofs) const = 0;

        // Virtual empty destructor
        virtual ~PosIO() {};
	};

    // Insertion operator overloads
    std::ostream& operator<<(std::ostream& os, const PosIO& src);
    std::ofstream& operator<<(std::ofstream& ofs, const PosIO& src);
    // Extraction operator overloads
    std::istream& operator>>(std::istream& is, PosIO& src);
    std::ifstream& operator>>(std::ifstream& ifs, PosIO& src);
}
#endif // !SDDS_POSIO_H_