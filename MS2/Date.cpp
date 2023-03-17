/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Date.cpp
Version: 1.0
Author: Sang Hyon Jeon
Revision History
-----------------------------------------------------------
Date        Reason
2023/03/20  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "Date.h"
#include "Utils.h"
#include "POS.h"

using namespace std;

namespace sdds {
	Date::Date() {
		int year, month, day, hour, minute;
		getSystemDate(year, month, day, hour, minute, false);
		*this = Date(year, month, day, hour, minute).dateOnly(false);
	}

	Date::Date(int year, int month, int day) {\
		*this = Date(year, month, day, 0, 0).dateOnly(true);

		// Check the date and time validity and set the error message accordingly
		if (year < MIN_YEAR || year > MAX_YEAR) {
			m_error = "Invalid Year";
		}
		else if (month < 1 || month > 12) {
			m_error = "Invalid Month";
		}
		else if (day < 1 || day > daysOfMonth(year, month)) {
			m_error = "Invalid Day";
		}
	}

	Date::Date(int year, int month, int day, int hour, int minute) {
		m_year = year;
		m_month = month;
		m_day = day;
		m_hour = hour;
		m_minute = minute;
		dateOnly(false);

		// Check the date and time validity and set the error message accordingly
		if (year < MIN_YEAR || year > MAX_YEAR) {
			m_error = "Invalid Year";
		}
		else if (month < 1 || month > 12) {
			m_error = "Invalid Month";
		}
		else if (day < 1 || day > daysOfMonth(year, month)) {
			m_error = "Invalid Day";
		}
		else if (!m_dateOnly && (hour < 0 || hour > 23)) {
			m_error = "Invalid Hour";
		}
		else if (!m_dateOnly && (minute < 0 || minute > 59)) {
			m_error = "Invalid Minute";
		}
	}

	bool Date::operator==(const Date& rhs) const {
		return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) == uniqueDateValue(rhs.m_year, rhs.m_month, rhs.m_day, rhs.m_hour, rhs.m_minute);
	}

	bool Date::operator!=(const Date& rhs) const {
		return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) != uniqueDateValue(rhs.m_year, rhs.m_month, rhs.m_day, rhs.m_hour, rhs.m_minute);
	}

	bool Date::operator<(const Date& rhs) const {
		return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) < uniqueDateValue(rhs.m_year, rhs.m_month, rhs.m_day, rhs.m_hour, rhs.m_minute);
	}

	bool Date::operator>(const Date& rhs) const {
		return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) > uniqueDateValue(rhs.m_year, rhs.m_month, rhs.m_day, rhs.m_hour, rhs.m_minute);
	}

	bool Date::operator<=(const Date& rhs) const {
		return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) <= uniqueDateValue(rhs.m_year, rhs.m_month, rhs.m_day, rhs.m_hour, rhs.m_minute);
	}

	bool Date::operator>=(const Date& rhs) const {
		return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) >= uniqueDateValue(rhs.m_year, rhs.m_month, rhs.m_day, rhs.m_hour, rhs.m_minute);
	}

	Date& Date::dateOnly(bool value) {
		m_dateOnly = value;
		if (value) {
			m_hour = 0;
			m_minute = 0;
		}
		return *this;
	}

	Date::operator bool() const {
		return bool(m_error) == false;
	}

	const Error& Date::error() const {
		return m_error;
	}

	Error& Date::error() {
		return m_error;
	}

	int Date::getYear() const {
		return m_year;
	}
	int Date::getMonth() const {
		return m_month;
	}
	int Date::getDay() const {
		return m_day;
	}
	int Date::getHour() const {
		return m_hour;
	}
	int Date::getMinute() const {
		return m_minute;
	}
	bool Date::getDateOnly() const {
		return m_dateOnly;
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& rhs) {
		if (rhs) {
			ostr << rhs.getYear() << '/';
			ostr.fill('0');
			ostr.width(2);
			ostr << rhs.getMonth() << '/';
			ostr.width(2);
			ostr << rhs.getDay();
			if (!rhs.getDateOnly()) {
				ostr << ", ";
				ostr.width(2);
				ostr << rhs.getHour() << ':';
				ostr.width(2);
				ostr << rhs.getMinute();
			}
		}
		else {
			ostr << rhs.error().getMessage();
		}
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Date& rhs) {
		int year, month, day, hour, minute;
		char delimiter;

		if (!(istr >> year)) {
			rhs.error() = "Cannot read year entry";
			istr.clear();
			istr.ignore(1000, '\n');
		}
		else if (!(istr >> delimiter >> month)) {
			rhs.error() = "Cannot read month entry";
			istr.clear();
			istr.ignore(1000, '\n');
		}
		else if (!(istr >> delimiter >> day)) {
			rhs.error() = "Cannot read day entry";
			istr.clear();
			istr.ignore(1000, '\n');
		}
		else if (!rhs.getDateOnly()) {
			if (!(istr >> delimiter >> hour)) {
				rhs.error() = "Cannot read hour entry";
				istr.clear();
				istr.ignore(1000, '\n');
			}
			else if (!(istr >> delimiter >> minute)) {
				rhs.error() = "Cannot read minute entry";
				istr.clear();
				istr.ignore(1000, '\n');
			}
			else {
				rhs = Date(year, month, day, hour, minute);
			}
		}
		else {
			rhs = Date(year, month, day);
		}
		return istr;
	}
}