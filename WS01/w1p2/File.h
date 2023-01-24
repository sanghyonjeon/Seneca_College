/***********************************************************************
                          Workshop - #1 (Part-2)
// Full Name  : Sang Hyon Jeon
// Student ID#: 1123552194
// Email      : shjeon5@myseneca.ca
// Section    : NBB
// Date       : January 23, 2023
//
// Authenticity Declaration:
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include "GPA.h"

namespace sdds {
    /*
    struct FileData {
        double gpa;
        int stno;
        char name[116];
    };
    */

    int readRecord(FILE* fptr, GPA* gptr, int numRecords);
    //void prnStudent(const GPA* gptr, FILE* fptr);
    int loadData(const char* filename, struct GPA* gptr, int numRecords);
}
#endif