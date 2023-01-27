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
    

    // To Do: read functions (4 overloaded read functions)
    
    char* read(FILE* fp) {
        char* packageName = new char[60];
        fscanf(fp, "%60[^\n]\n", packageName);
        return packageName;
    }

    
    bool read(int &user_id, int &dayofyear, int &Fwifitime, int &Fctime, FILE* fp) {
        return fscanf(fp, "%d,%d,%d,%d", &user_id, &dayofyear, &Fwifitime, &Fctime) == 4;
    }

    double& read(double &timeinhours, FILE* fp) {
        fscanf(fp, "%lf,", &timeinhours);
        return timeinhours;
    }

    char& read(char &dayofweek, FILE* fp) {
        fscanf(fp, "%[^ \t\n\r\v\f,]%*c", &dayofweek);
        return dayofweek; 
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