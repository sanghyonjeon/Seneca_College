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
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include "Numbers.h"

using namespace std;

namespace sdds {
    void sort(double* nums, unsigned int size) {
        unsigned int i, j;
        double temp;
        for (i = size - 1; size && i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1]) {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }

    unsigned int countLines(const char* filename) { /**/
        unsigned int lines = 0u;
        ifstream nums(filename);
        while (nums) {
            lines += (nums.get() == '\n');
        }
        return lines;
    }

    std::ostream& operator<<(std::ostream& ostr, const Numbers& nums) {
        return nums.display(ostr);
    }

    std::istream& operator>>(std::istream& istr, Numbers& nums) {
        double value = 0;
        istr >> value;
        istr.ignore(1000, '\n');
        if (istr)
        {
            nums += value;
        }
        return istr;
    }

    void Numbers::setEmpty() {
        m_collection = nullptr;
        m_filename[MAX_FILENAME_LENGTH] = '\0';
        m_colSize = 0;
        m_original = false;
        m_added = false;
    }

    bool Numbers::load(const char* filename) {
        int numLines = countLines(filename);
        int i = 0;

        if (m_collection != nullptr) {
            delete[] m_collection;
            m_collection = nullptr;
        }

        if (numLines > 0) {
            m_collection = new double[numLines];
            std::ifstream file(filename);

            while (i < numLines && file >> m_collection[i]) {
                i++;
            }

            if (i != numLines) {
                delete[] m_collection;
                setEmpty();
            }
            else {
                m_colSize = numLines;
                m_original = true;
            }
        }
        return (numLines > 0);
    }

    void Numbers::save() {
        if (m_original && m_added) {
            std::ofstream file(m_filename);
            file.precision(2);
            file << std::fixed;
            for (unsigned int i = 0; i < m_colSize; i++) {
                file << m_collection[i] << endl;
            }
        }
    }

    double Numbers::max() const {
        double max = m_collection[0];

        for (unsigned int i = 1; i < m_colSize; i++) {
            if (m_collection[i] > max) {
                max = m_collection[i];
            }
        }
        return max;
    }

    double Numbers::min() const {
        double min = m_collection[0];

        for (unsigned int i = 1; i < m_colSize; i++) {
            if (m_collection[i] < min) {
                min = m_collection[i];
            }
        }
        return min;
    }

    double Numbers::average() const {
        double sum = 0;

        for (unsigned int i = 0; i < m_colSize; i++) {
            sum += m_collection[i];
        }

        return sum / m_colSize;
    }

    Numbers::Numbers() {
        setEmpty();
    }

    Numbers::Numbers(const char* filename) {
        strncpy(m_filename, filename, MAX_FILENAME_LENGTH + 1);
        m_filename[MAX_FILENAME_LENGTH] = '\0';
        load(filename);
    }

    Numbers::Numbers(const Numbers& src) {
        *this = src;
    }

    Numbers::~Numbers() {
        save();
        delete[] m_collection;
    }

    Numbers::operator bool() const {
        return m_collection != nullptr;
    }

    std::ostream& Numbers::display(std::ostream& ostr) const {
        if (m_colSize == 0) {
            ostr << "Empty list";
        }
        else {
            ostr.precision(2);
            ostr << fixed;

            if (!m_original) {
                ostr << "Copy of ";
            }

            ostr << m_filename << endl;

            for (unsigned int i = 0; i < m_colSize - 1; i++) {
                ostr << m_collection[i] << ", ";
            }

            ostr << m_collection[m_colSize - 1] << endl;

            for (int i = 0; i < 76; i++) {
                ostr << "-";
            }

            ostr << endl;

            ostr << "Total of " << m_colSize << " number(s), Largest: " << max() << ", Smallest: " << min() << ", Average: " << average() << endl;

            for (int i = 0; i < 76; i++) {
                ostr << "=";
            }
        }

        return ostr;
    }

    void Numbers::sort() {
        sdds::sort(m_collection, m_colSize);
    }

    Numbers& Numbers::operator=(const Numbers& src) {
        if (this != &src) {
            save();

            if (m_collection != nullptr) {
                delete[] m_collection;
                m_collection = nullptr;
            }

            setEmpty();

            m_colSize = src.m_colSize;

            if (src.m_colSize > 0) {
                strncpy(m_filename, src.m_filename, MAX_FILENAME_LENGTH);
                m_original = false;  
                m_collection = new double[m_colSize];
                for (unsigned int i = 0; i < m_colSize; i++) {
                    m_collection[i] = src.m_collection[i];
                }
            }
        }

        return *this;
    }

    Numbers& Numbers::operator+=(double value) {
        if (m_colSize > 0) {
            double* temp = new double[m_colSize + 1];

            for (unsigned int i = 0; i < m_colSize; i++) {
                temp[i] = m_collection[i];
            }

            temp[m_colSize] = value;

            delete[] m_collection;
            m_collection = temp;
            
            m_colSize++;

            m_added = true;
        }
        return *this;
    }
}