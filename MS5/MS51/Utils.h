/* Citation and Sources...
Final Project Milestone 51
Module: Utils
Filename: Utils.h
Version: 1.0
Author: Sang Hyon Jeon
Revision History
-----------------------------------------------------------
Date        Reason
2023/04/16  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_

namespace sdds {
	void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
	int uniqueDateValue(int year, int mon, int day, int hour, int min);
	int daysOfMonth(int year, int month);
}
#endif // !SDDS_UTILS_H_