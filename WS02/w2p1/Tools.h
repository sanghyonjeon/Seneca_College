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
#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

namespace sdds {
	int openFile_r(const char filename[]); // Provided
	void closefile(); // Provided
	int noOfTraces(); // Provided

	int read(char Package_Name[]); // Return a Cstring argument to send back the name of the Package.
	int read(int& int_number); // Return a reference argument to an int to pass back the user_id, dayofyear, Fwifitime and Fctime.
	int read(double& timeinhours); // Return a reference argument to a double to pass back the timeinhours.
	int read(char& dayofweek); // Return a reference argument to a char to pass back the dayofweek.

	void strCpy(char* des, const char* src); // Provided
	int strLen(const char* s); // Provided
}
#endif