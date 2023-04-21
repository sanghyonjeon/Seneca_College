/***********************************************************************
                          Workshop - #1 (Part-2)
// Full Name  : Sang Hyon Jeon
// Student ID#: 113552194
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
    int readRecord(FILE* fptr, GPA* gptr, int numRecords) {
        int i = 0;
        int rc = 0;

        do {
            rc = fscanf(fptr, "%[^,],%d,%lf\n", gptr[i].name, &gptr[i].stno, &gptr[i].gpa);
            
            if (rc > 0) {
                i++;
            }
        } while (rc > 0 && i < numRecords);

        return i;
    }

    int loadData(const char* filename, struct GPA* gptr, int numRecords) {
        FILE* fptr;
        int i = 0;

        fptr = fopen(filename, "r");

        if (fptr) {
            i = readRecord(fptr, gptr, numRecords);
            fclose(fptr);
        }

        return i;
    }

    void sortDataAscend(struct GPA* gptr, int numRecords) {
        int i, j;
        struct GPA temp[100] = { {0} };

        for (i = 0; i < numRecords - 1; i++) {
            for (j = 0; j < numRecords - 1; j++) {
                if (gptr[j].stno > gptr[j + 1].stno) {
                    temp[j] = gptr[j];
                    gptr[j] = gptr[j + 1];
                    gptr[j + 1] = temp[j];
                }
            }
        }
    }
}