/*
*****************************************************************************
                          Workshop - #3 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 1123552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_
#include <iostream>

namespace sdds {

    const int MAX_TOPIC_LENGTH = 25;

    struct Project {
        char m_topic[MAX_TOPIC_LENGTH+1];
        double m_cost;
    };

	//class Department does here
    class Department {
    private:
        char* departmentName;
        Project* departmentProjects;
        int numProjects;
        double departmentBudget;

    public:
        Department();
        void updateName(const char* newname);
        void updateBudget(double change);
        bool addProject(Project& newproject);
        void createDepartment(const char* newname, Project& newproject, double change);
        Project* fetchProjects() const;
        int fetchNumProjects() const;
        double fetchBudget() const;
        char* fetchName() const;
        double totalexpenses();
        double remainingBudget();
        void clearDepartment();
    };
	
	//helper functions - do not belong inside the class
    void display(const Project& project);
    void display(const Department& department);

}
#endif // !SDDS_DEPARTMENT_H_