/*
*****************************************************************************
                          Workshop - #2 (Part-2)
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
#include <iostream>
#include "Tools.h"

namespace sdds {
   void strCpy(char* str1, const char* str2) {
      while(*str2) {
         *str1++ = *str2++;
      }
      *str1 = 0;
   }

   void clearInputBuffer(void) {
       while (getchar() != '\n');
   }
}
