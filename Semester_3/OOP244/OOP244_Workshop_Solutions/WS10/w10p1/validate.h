/*
*****************************************************************************
                          Workshop - #10 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 113552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SICT_VALIDATE_H_
#define SICT_VALIDATE_H_

namespace sict {
    template <typename T>
    bool validate(const T& minValue, const T testValues[], int numElements, bool results[]) {
        bool allValid = true;

        for (int i = 0; i < numElements; i++) {
            if (testValues[i] >= minValue) {
                results[i] = true;
            }
            else {
                results[i] = false;
                allValid = false;
            }
        }
        return allValid;
    }
}
#endif // !SICT_VALIDATE_H_