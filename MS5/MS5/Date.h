/* Citation and Sources...
Final Project Milestone 5
Module: Date
Filename: Date.h
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
#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_
#include "Error.h"

namespace sdds {
	class Date {
		int m_year;
		int m_month;
		int m_day;
		int m_hour;
		int m_minute;
		bool m_dateOnly;
		Error m_error;

	public:
		Date();
		Date(int year, int month, int day);
		Date(int year, int month, int day, int hour, int minute = 0);
		
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		Date& dateOnly(bool value);

		operator bool() const;

		const Error& error() const;
		Error& error();

		int getYear() const;
		int getMonth() const;
		int getDay() const;
		int getHour() const;
		int getMinute() const;
		bool getDateOnly() const;

		void setYear(int year);
		void setMonth(int month);
		void setDay(int day);
		void setHour(int hour);
		void setMinute(int minute);

		void print(std::ostream& ostr) const;
		std::istream& rread(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Date& rhs);
	std::istream& operator>>(std::istream& istr, Date& rhs);
}
#endif // !SDDS_DATE_H_