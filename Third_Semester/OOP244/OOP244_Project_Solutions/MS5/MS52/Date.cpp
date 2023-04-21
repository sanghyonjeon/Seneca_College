/* Citation and Sources...
Final Project Milestone 52
Module: Date
Filename: Date.cpp
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

	Date::Date(int year, int month, int day) {
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
			m_error = "Invlid Minute";
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
		return !m_error;
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

	void Date::setYear(int year) {
		m_year = year;
	}

	void Date::setMonth(int month) {
		m_month = month;
	}

	void Date::setDay(int day) {
		m_day = day;
	}

	void Date::setHour(int hour) {
		m_hour = hour;
	}

	void Date::setMinute(int minute) {
		m_minute = minute;
	}

	void Date::print(std::ostream& ostr) const {
		ostr.fill('0');
		ostr.setf(ios::right);
		ostr << getYear() << '/';
		ostr.width(2);
		ostr << getMonth() << '/';
		ostr.width(2);
		ostr << getDay();
		if (!getDateOnly() && m_minute != 0 && m_hour != 0) {
			ostr << ", ";
			ostr.width(2);
			ostr << getHour() << ':';
			ostr.width(2);
			ostr << getMinute();
		}
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& rhs) {
		if (rhs) {
			rhs.print(ostr);
		}
		else {
			ostr << rhs.error().getMessage() << "(";
			rhs.print(ostr);
			ostr << ")";
		}
		return ostr;
	}

	std::istream& Date::rread(std::istream& istr) {
		m_year = m_month = m_day = m_hour = m_minute = 0;
		m_error = "NULL Date";

		m_error.clear();
		istr >> m_year;
		if (!istr) {
			m_error = "Cannot read year entry";
		}
		istr.ignore();
		istr >> m_month;
		if (!m_error && !istr) {
			m_error = "Cannot read month entry";
		}
		istr.ignore();
		istr >> m_day;
		if (!m_error && !istr) {
			m_error = "Cannot read day entry";
		}
		if (!getDateOnly() && istr.peek() != '\n' && istr.peek() != EOF) {
			istr.ignore();
			istr >> m_hour;
			if (!m_error && !istr) {
				m_error = "Cannot read hour entry";
			}
			istr.ignore();
			istr >> m_minute;
			if (!m_error && !istr) {
				m_error = "Cannot read minute entry";
			}
		}
		else {
			m_hour = m_minute = 0;
		}
		if (istr) {
			if (m_year < MIN_YEAR || m_year > MAX_YEAR) {
				error() = "Invalid Year";
			}
			else if (m_month < 1 || m_month > 12) {
				error() = "Invalid Month";
			}
			else if (m_day < 1 || m_day > daysOfMonth(m_year, m_month)) {
				error() = "Invalid Day";
			}
			else if (!getDateOnly() && (m_hour < 0 || m_hour > 23)) {
				error() = "Invalid Hour";
			}
			else if (!getDateOnly() && (m_minute < 0 || m_minute > 59)) {
				error() = "Invlid Minute";
			}
		}
		return istr;
	}

	std::istream& operator>>(std::istream& istr, Date& rhs) {
		return rhs.rread(istr);
	}
}