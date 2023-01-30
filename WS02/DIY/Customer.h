/*
*****************************************************************************
                          Workshop - #2 (Part-2)
Full Name  : Sang Hyon Jeon
Student ID#: 1123552194
Email      : shjeon5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_

namespace sdds {
    struct Customers {
        char user_name[21];
        int retweets_count;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets' report.
        int noOfRecords;
    };

    // Sets Customer data members to an empty state
    void EmptyRecord(Customers& customer);

    // Sets CustomersRecord data members to an empty state
    void EmptyRecord(CustomersRecord& record);

    // Prompts for user name. If user name is entered, prompt Customer data and return True.
    // If user enters an empty value, return false.
    bool read(Customers& rec);

    // Fully provided
    void read(char* str, int len);

    // Adds a Customer to the dynamically allocated memory of customers in CustomersRecord
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec);

    // Prints the Customer information
    void display(const Customers& c_rec);

    // Prints a row number with a period before each user name. Then, it prints all the customers' records.
    void display(const CustomersRecord& t_rec);
}

#endif 
