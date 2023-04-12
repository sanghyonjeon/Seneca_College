/* Citation and Sources...
Final Project Milestone 55
Module: Error
Filename: Error.cpp
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
#include "Error.h"
#include <cstring>

using namespace std;

namespace sdds {
	Error::Error() {
		m_message = nullptr;
	}

	Error::Error(const char* message) {
		if (message != nullptr && message[0] != '\0') {
			m_message = new char[strlen(message) + 1];
			strcpy(m_message, message);
		}
		else {
			m_message = nullptr;
		}
	}

	Error::Error(const Error& src) {
		if (src.m_message != nullptr && src.m_message[0] != '\0') {
			m_message = new char[strlen(src.m_message) + 1];
			strcpy(m_message, src.m_message);
		}
		else {
			m_message = nullptr;
		}
	}

	Error::~Error() {
		delete[] m_message;
	}

	Error& Error::operator=(const Error& src) {
		if (this != &src) {
			delete[] m_message;
			if (src.m_message != nullptr) {
				m_message = new char[strlen(src.m_message) + 1];
				strcpy(m_message, src.m_message);
			}
			else {
				m_message = nullptr;
			}
		}
		return *this;
	}

	Error& Error::operator=(const char* message) {
		delete[] m_message;
		if (message != nullptr && message[0] != '\0') {
			m_message = new char[strlen(message) + 1];
			strcpy(m_message, message);
		}
		else {
			m_message = nullptr;
		}
		return *this;
	}

	Error::operator bool() const {
		return m_message != nullptr;
	}

	Error& Error::clear() {
		delete[] m_message;
		m_message = nullptr;
		return *this;
	}

	const char* Error::getMessage() const {
		return m_message;
	}

	void Error::setMessage(const char* str) {
		delete[] m_message;
		m_message = new char[strlen(str) + 1];
		strcpy(m_message, str);
	}

	bool Error::isClear() const {
		return (m_message == nullptr || m_message[0] == '\0');
	}

	std::ostream& operator<<(std::ostream& ostr, const Error& rhs) {
		if (rhs) {
			ostr << rhs.getMessage();
		}
		return ostr;
	}
}