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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "GPAlist.h"
#include "File.h"
#include "UI.h"
#define MAX_RECORDS 100
using namespace std;

namespace sdds {
    void clearInputBuffer(void)
    {
        while (getchar() != '\n');
    }

    bool gpaQuery(const char* filename) {
        int numRecords;
        struct GPA gptr[MAX_RECORDS] = { {0} };
        
        numRecords = loadData(filename, gptr, MAX_RECORDS);

        if (numRecords) {
            //Test purposes
            //printf("% s, % d, % lf\n", gptr[1].name, gptr[1].stno, gptr[1].gpa);
            displayPromptMessage();

            // THIS IS WHERE I SHOULD ASK FOR USER INPUTS: [OP][VALUE]
        }

        return numRecords;
    }



}