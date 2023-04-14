/* Citation and Sources...
Final Project Milestone 5
Module: Error
Filename: Error.h
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
#ifndef SDDS_ERROR_H_
#define SDDS_ERROR_H_
#include <iostream>

namespace sdds {
	class Error {
		char* m_message;

	public:
		Error();
		Error(const char* message);
		Error(const Error& src);
		~Error();

		Error& operator=(const Error& src);
		Error& operator=(const char* message);

		operator bool() const;

		Error& clear();
		const char* getMessage() const;

		bool isClear() const;
		void setMessage(const char* message);
	};
	std::ostream& operator<<(std::ostream& ostr, const Error& rhs);
}
#endif // !SDDS_ERROR_H_