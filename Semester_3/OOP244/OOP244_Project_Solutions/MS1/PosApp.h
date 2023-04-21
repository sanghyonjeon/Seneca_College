/* Citation and Sources...
Final Project Milestone 1
Module: PosApp
Filename: PosApp.h
Version: 1.0
Author: Sang Hyon Jeon
Revision History
-----------------------------------------------------------
Date        Reason
2023/03/10  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_

namespace sdds {
	const int MAX_FILENAME_LENGTH = 255;

	class PosApp {
		char m_filename[MAX_FILENAME_LENGTH + 1];

		int menu();
		void addItem();
		void removeItem();
		void stockItem();
		void listItems();
		void POS();
		void saveRecs();
		void loadRecs();

	public:
		PosApp(const char* filename);
		PosApp(const PosApp& src) = delete;
		PosApp& operator=(const PosApp& src) = delete;

		void run();
	};
}
#endif // !SDDS_POSAPP_H_