/*
*****************************************************************************
                          Workshop - #6 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 1123552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>

namespace sdds {
    class Numbers;
    const int MAX_FILENAME_LENGTH = 255;

    void sort(double* nums, unsigned int size);
    unsigned int countLines(const char* filename);

    std::ostream& operator<<(std::ostream& ostr, const sdds::Numbers& nums);
    std::istream& operator>>(std::istream& istr, sdds::Numbers& nums);

    class Numbers {
        double* m_collection = nullptr;
        char m_filename[MAX_FILENAME_LENGTH + 1] = { '\0' };
        unsigned int m_colSize = 0;
        bool m_original = false;
        bool m_added = false;
      
        void setEmpty();
        bool load(const char* filename);
        void save();
        double max() const;
        double min() const;
        double average() const;

   public:
       Numbers();
       Numbers(const char* filename);
       Numbers(const Numbers& src);
       ~Numbers();
       
       operator bool() const;
       void sort();
       
       Numbers& operator=(const Numbers& src);
       Numbers& operator+=(double value);
       
       std::ostream& display(std::ostream& ostr = std::cout) const;
   };
}
#endif // !SDDS_NUMBERS_H_