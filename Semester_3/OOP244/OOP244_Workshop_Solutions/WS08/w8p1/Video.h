/*
*****************************************************************************
                          Workshop - #8 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 113552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_VIDEO_H_
#define SDDS_VIDEO_H_
#include "Media.h"

namespace sdds {
    class Video : public Media {
        int m_length;
    
    protected:
        int get() const;
    
    public:
        Video();
        Video(int length);

        Video(const Video& src) = delete;
        Video& operator=(const Video& src) = delete;

        void load(std::istream& is);
    };
}
#endif // !SDDS_VIDEO_H_