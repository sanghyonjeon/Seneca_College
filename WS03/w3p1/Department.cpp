/*
*****************************************************************************
                          Workshop - #3 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 113552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {
    Department::Department() {
        departmentName = nullptr;
        departmentProjects = nullptr;
        numProjects = 0;
        departmentBudget = 15345.99;
    }

    void Department::updateName(const char* newname) {
        if (newname && strlen(newname) > 0) {
            if (departmentName) delete[] departmentName;
            departmentName = new char[strlen(newname) + 1];
            strcpy(departmentName, newname);
        }
    }

    void Department::updateBudget(double change) {
        departmentBudget += change;
    }

    bool Department::addProject(Project& newproject) {
        double totalCost = totalexpenses() + newproject.m_cost;
        if (totalCost <= departmentBudget) {
            Project* temp = new Project[numProjects + 1];
            for (int i = 0; i < numProjects; i++)
                temp[i] = departmentProjects[i];
            temp[numProjects++] = newproject;

            delete[] departmentProjects;
            departmentProjects = temp;
            return true;
        }
        return false;
    }

    void Department::createDepartment(const char* newname, Project& newproject, double change) {
        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }

    Project* Department::fetchProjects() const {
        return departmentProjects;
    }

    int Department::fetchNumProjects() const {
        return numProjects;
    }

    double Department::fetchBudget() const {
        return departmentBudget;
    }

    char* Department::fetchName() const {
        return departmentName;
    }

    double Department::totalexpenses() {
        double total = 0;
        for (int i = 0; i < numProjects; i++)
            total += departmentProjects[i].m_cost;
        return total;
    }

    double Department::remainingBudget() {
        return departmentBudget - totalexpenses();
    }

    void Department::clearDepartment() {
        delete[] departmentName;
        delete[] departmentProjects;
        numProjects = 0;
        departmentBudget = 15345.99;
        departmentName = nullptr;
        departmentProjects = nullptr;
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