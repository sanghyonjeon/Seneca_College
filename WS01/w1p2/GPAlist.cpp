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
        struct GPA gptr[MAX_RECORDS] = { {0} };
        double gpaInput;
        int numRecords;
        int i;
        int j;
        int flag = 0;
        char operationInput;
        char confirmExit;
        
        numRecords = loadData(filename, gptr, MAX_RECORDS);
        sortDataAscend(gptr, numRecords);

        if (numRecords) {
            displayPromptMessage();

            do {
                j = 0;
                cout << "? ";
                cin >> operationInput;

                switch (operationInput) {
                case '<':
                    cin >> gpaInput;
                    for (i = 0; i < numRecords; i++) {
                        if (gptr[i].gpa < gpaInput) {
                            j++;
                            printf("[%d] %d: %.1lf (%s)\n", j, gptr[i].stno, gptr[i].gpa, gptr[i].name);
                        }
                    }
                    break;
                case '>':
                    cin >> gpaInput;
                    for (i = 0; i < numRecords; i++) {
                        if (gptr[i].gpa > gpaInput) {
                            j++;
                            printf("[%d] %d: %.1lf (%s)\n", j, gptr[i].stno, gptr[i].gpa, gptr[i].name);
                        }
                    }
                    break;
                case '~':
                    cin >> gpaInput;
                    for (i = 0; i < numRecords; i++) {
                        if (gpaInput - 0.05 < gptr[i].gpa && gpaInput + 0.05 > gptr[i].gpa) {
                            j++;
                            printf("[%d] %d: %.1lf (%s)\n", j, gptr[i].stno, gptr[i].gpa, gptr[i].name);
                        }
                    }
                    break;
                case '!':
                    clearInputBuffer();
                    printf("Exit the program? (Y)es/(N)o: ");
                    cin >> confirmExit;
                    
                    if (confirmExit == 'y' || confirmExit == 'Y') {
                        flag = 1;
                    }
                    break;
                default:
                    clearInputBuffer();
                    displayErrorMessage();
                }
            } while (flag == 0);
        }

        return numRecords;
    }



}