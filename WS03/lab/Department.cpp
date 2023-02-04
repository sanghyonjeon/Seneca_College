#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {
    void Department::updateName(const char* newname) {
        char emptyString[] = "";

        // If the provided name is valid (exists and is not empty),
        // this function will set the name of the department.
        if (newname != emptyString) {
            int newnameLength = strlen(newname);
            // If the department is already set,
            // it will deallocate the name.
            if (departmentName != nullptr) {
                delete[] departmentName;
                departmentName = nullptr;
            }
            // It will create enough memory for the name of the department to match the new name
            // and then copies the data of the new name
            departmentName = new char[newnameLength];
            strcpy(departmentName, newname);
        }
            // If the new name is not valid,
            // the department's current name will not change.
    }

    void Department::updateBudget(double change) {
            // This function will update the budget of the department
            // by adding a new change to it.
        departmentBudget += change;
    }

    bool Department::addProject(Project& newproject) {
        int totalProjectCost;
        
            // This function will add a new project to the department,
            // as long as the total cost does not exceed the allocated budget.
        if ((departmentBudget - (totalProjectCost + newproject.m_cost)) >= 0) {
            if (numProject == 0) {
                strcpy(departmentProject[0].m_topic, newproject.m_topic);
            }
            else {
                Project* tempProject = new Project[numProject + 1];
                
                for (int i = 0; i < numProject; i++) {
                    tempProject[i] = departmentProject[i];
                }
                
            }

            numProject++;
            totalProjectCost += newproject.m_cost;
        }
        // If the new project cost in addition to the total cost of the current project does not exceed the budget,
        // this function will add the new project to the department list of projects by:
        /*
            // If there are no projects currently in progress:
                // create a new Project and save the data inside it
                // If there are projects currently in progress,
                // allocate a temp array of projects with new size = old size + 1.
                // copy all projects from the old array to the new one
                // add new data to the last position of the temp array
                // wipe out the old array
                // increase the number of the project by one
                // allocate projects with the new size
                // copy all projects from the temp array to projects
                // wipe out the temp array

            // This function will eventually return true,
            // if a project was added to the department, and false otherwise.
        */

        return 0;
    }

    void Department::createDepartment(const char* newname,
        Project& newproject,
        double change) {
        // This function will use functions updateName, addProject and updateBudget
        // to set the name of the department, add a project to it and update its budget.
        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }

    Project* Department::fetchProjects() const {
        // This function will return the list of projects a department is currently working on.

        return 0;
    }

    int Department::fetchNumProjects() const {
        // This function will return the number of projects a department is currently working on.
        return 0;
    }

    double Department::fetchBudget() const {
        // This function will return the current budget of a department.
        return 0;
    }

    char* Department::fetchName() const {
        // This function will return the name of a department.
        return 0;
    }

    double Department::totalexpenses() {
        // This function will calculate and return the expenses of a department.
        // The total expenses of a department is the total cost of all its current projects.
        return 0;
    }

    double Department::remainingBudget() {
        // This function will calculate and return the remaining budget of a department
        // by subtracting the total expenses from the budget.
        return 0;
    }

    void Department::clearDepartment() {
    // This function will clear all the dynamic memory allocation in a department.
    }

    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
            Project* temp = department.fetchProjects();
            int projects = department.fetchNumProjects();
            cout << "Department " << department.fetchName() << " details:" << endl;
            cout << "Budget: " << department.fetchBudget()
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }

}