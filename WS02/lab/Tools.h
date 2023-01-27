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

	// ADD: Declare read prototypes (4 prototypes)

	char* read(FILE* fp);
	bool read(int& user_id, int& dayofyear, int& Fwifitime, int& Fctime, FILE* fp);
	double& read(double& timeinhours, FILE* fp);
	char& read(char& dayofweek, FILE* fp);





	void strCpy(char* des, const char* src); // Provided
	int strLen(const char* s); // Provided
}
#endif 
