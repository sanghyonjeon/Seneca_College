/*
*****************************************************************************
                          Workshop - #2 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 1123552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Tools.h"
#include "Package.h"

FILE* fp;

namespace sdds {
    int openFile_r(const char filename[]) { // Fully provided
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }
    int noOfTraces() {  // Fully provided
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');
        }
        rewind(fp);
        return noOfTraces;
    }

    // Return a Cstring argument to send back the name of the Package.
    int read(char Package_Name[]) {
        return fscanf(fp, "%60[^\n]\n", Package_Name) == 1;
    }

    // Return a reference argument to an int to pass back the user_id, dayofyear, Fwifitime and Fctime.
    int read(int& int_number) {
        return fscanf(fp, "%d,", &int_number) == 1;
    }

    // Return a reference argument to a double to pass back the timeinhours.
    int read(double& timeinhours) {
        return fscanf(fp, "%lf,", &timeinhours) == 1;
    }

    // Return a reference argument to a char to pass back the dayofweek.
    int read(char& dayofweek) {
        return fscanf(fp, "%[^ \t\n\r\v\f,]%*c", &dayofweek);
    }

    void closefile() { // Fully provided
        if (fp) fclose(fp);
    }
    
    void strCpy(char* str1, const char* str2) { // Fully provided 
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) {  // Fully provided
        int i = -1;
        while (str[++i]);
        return i;
    }
}