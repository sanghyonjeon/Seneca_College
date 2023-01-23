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
#include <cstdio>
#include <cstring>
#include "File.h"
using namespace std;

namespace sdds {
    int readStudent(GPA* gptr, FILE* fptr) {
        return fscanf(fptr, "%[^,],%d,%lf\n", gptr->name, &gptr->stno, &gptr->gpa) == 3;
    }

    /*
    void prnStudent(const GPA* gptr, FILE* fptr) {
        fprintf(fptr, "%d: %0.1lf (%s)\n", gptr->stno, gptr->gpa, gptr->name);
    }
    */

    int openFile(const char* filename) {
        FILE* fptr;
        fptr = fopen(filename, "r");
        return bool(fptr);
    }
}