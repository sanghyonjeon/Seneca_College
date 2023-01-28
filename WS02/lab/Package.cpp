/*
*****************************************************************************
                          Workshop - #2 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 1123552194
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
#include "Package.h"
#include "Tools.h"

using namespace std;
namespace sdds {
    int no_of_traces;
    Customers* users = nullptr;
    
    // Load all the users records into the Customers array, and return a bool for success.
    int loadTraces() {
        bool check = true;
        int i = 0;

        if (openFile_r(filename_r)) {

            // Set the noOfTraces to the number of records found in the file.
            no_of_traces = noOfTraces();
                                   
            // Dynamically allocate an array of Customers into the global Customers' pointer (users) with the size of no_of_traces.
            users = new Customers[no_of_traces + 1];

            // Load the Customers' records from the file into the dynamically created array (use a loop).
            for (i = 0; i < no_of_traces; i++) {

                loadTraces(users[i]);
            }

            // If the number of the records does not match the number of read ones, print an error message.
            if (i != no_of_traces) {
                cout << "Error reading the records, Check the data file " << endl;
            }
            else {
             // Set check to true.
                check = true;
            }

            // Close the file; call closefile() function.
            closefile();

        }
        else {
            cout << "Could not open the"<< filename_r <<" data file"<< endl;
        }
        return check;
    }  

    int loadTraces(Customers& user_info) {
        bool check = false;
        char read_Package_name[50];

        if (read(user_info.dayofweek)&& read(user_info.user_id) && read(user_info.timeinhours) && read(user_info.dayofyear) && read(user_info.Fwifitime)  
            && read(user_info.Fctime) && read(read_Package_name)) { // if reading of data

           // Allocate memory to the size of the Package_name + 1, while keeping its address in the name of the customers reference (user_info.Package_Name)
            user_info.Package_Name = new char[strLen(read_Package_name) + 1];

           // Copy the name into the newly allocated memory, using provided strCpy function
            strCpy(user_info.Package_Name, read_Package_name);

           // Set check to true if the previous process is successfully completed
            check = true;
        }
        return check; 
    }
    
    void grouptTraces() {  // Fully provided
        int i, j;
        Customers temp_record;
        for (i = no_of_traces - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (users[j].user_id > users[j + 1].user_id) {
                    temp_record = users[j];
                    users[j] = users[j + 1];
                    users[j + 1] = temp_record;
                }
            }
        }
    }

    // Display all customer record(s) whose spent time is greater than 1 hour, and day of week is Friday.
    void display() {
        int i;

        for (i = 0; i < no_of_traces; i++) {
            if ((users[i].timeinhours > 1.0) && (users[i].dayofweek == 'F')) {
                cout << users[i].user_id << "," << users[i].timeinhours << "," << users[i].Fctime << "," << users[i].Fwifitime << "," << users[i].Package_Name << endl;
            }
        }
    }
    
    // (1). Deallocate all the Package names in the customer (users) elements,
    // (2). Deallocate the users array 
    void deallocateMemory(void) {
        int i;

        for (i = 0; i < no_of_traces; i++) {
            delete[] users[i].Package_Name;
        }
        delete[] users;
    }
}


