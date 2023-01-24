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
#include "UI.h"
#include "File.h"
using namespace std;

namespace sdds {
    void displayPromptMessage() {
        cout << "Enter GPA query..." << endl;
    }

    void displayErrorMessage() {
        cout << "Syntax error: ? [Op][value]<ENTER>" << endl;
        cout << "Op: [>,<,~,!]" << endl;
        cout << "value: GPA value" << endl;
        putchar('\n');
    }

    /*
    void promptUserInput() {
        double gpaInput;
        char optionInput;

        int flag = 0;

        do {
            cout << "? ";
            scanf("%c%lf", &optionInput, &gpaInput);

            if (optionInput == '>') {
                printf("%c%lf", optionInput, gpaInput);
            }
            else if (optionInput == '<') {
                printf("%c%lf", optionInput, gpaInput);
            }
            else if (optionInput == '~') {
                printf("%c%lf", optionInput, gpaInput);
            }
            else if (optionInput == '!') {
                flag = 1;
            }
            else {
                displayErrorMessage();
            }
        } while (!flag);
    }*/
}