/*
*****************************************************************************
                          Workshop - #2 (Part-1)
Full Name  : Sang Hyon Jeon
Student ID#: 113552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_PACKAGE_H_
#define SDDS_PACKAGE_H_

#define filename_r "Filtered_Dataset.csv"

namespace sdds {

    struct Customers {
        char* Package_Name;
        int user_id;
        double timeinhours;
        int dayofyear;
        int Fwifitime;
        int Fctime;
        char dayofweek;
    };

    int loadTraces(); // Loads a customers structure with its values from the file      
    int loadTraces(Customers& user); // Allocates dynamic array of customers and loads all the file records into the array.

    void grouptTraces(); // Group the dynamic array of records based on the user id of customers.

    void display(); // Displays a customer record on the screen.
    void deallocateMemory();  // (1). Deallocates all the Package names in the customer (users) elements,
                              // (2). Deallocates the users array 
}
#endif  