/*
*****************************************************************************
                          Workshop - #2 (Part-2)
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
using namespace std;
#include "Customer.h"
#include "Tools.h"

#define MAX_NAME_LENGTH 21

namespace sdds {
    // Sets Customer data members to an empty state
    void EmptyRecord(Customers& customer) {
        strCpy(customer.user_name, "");
        customer.likes_count = 0;
        customer.replies_count = 0;
        customer.retweets_count = 0;
        customer.share_videos = '\0';
    };

    // Sets CustomersRecord data members to an empty state
    void EmptyRecord(CustomersRecord& records) {
        records.ptr_rec = nullptr;
        records.noOfRecords = 0;
    };


    // Prompts for user name. If user name is entered, prompt Customer data and return True.
    // If user enters an empty value, return false.
    bool read(Customers& rec) {
        char entered_user_name[MAX_NAME_LENGTH];
        int entered_likes_count;
        int entered_retweets_count;
        int entered_replies_count;
        char entered_share_videos;

        int flag;

        cout << " Enter User name: ";

        if (cin.peek() == '\n') {
            flag = 0;
        }
        else {
            cin.getline(entered_user_name, MAX_NAME_LENGTH);
            strCpy(rec.user_name, entered_user_name);

            cout << " Enter likes_count: ";
            cin >> entered_likes_count;
            rec.likes_count = entered_likes_count;

            cout << " Enter retweets_count: ";
            cin >> entered_retweets_count;
            rec.retweets_count = entered_retweets_count;

            cout << " Enter replies_count: ";
            cin >> entered_replies_count;
            rec.replies_count = entered_replies_count;

            cout << " Enter share videos (y/n): ";
            cin >> entered_share_videos;
            rec.share_videos = entered_share_videos;

            clearInputBuffer();
            flag = 1;
        }
        return flag;
    }

    // Fully provided
    void read(char* str, int len) {
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }

    // Adds a Customer to the dynamically allocated memory of customers in CustomersRecord
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {
        int i;
        Customers* temp_customer = new Customers[t_rec.noOfRecords + 1];

        for (i = 0; i < t_rec.noOfRecords; i++) {
            temp_customer[i] = t_rec.ptr_rec[i];
        }

        temp_customer[i] = c_rec;
        delete[] t_rec.ptr_rec;
        t_rec.noOfRecords++;
        t_rec.ptr_rec = temp_customer;
    }

    // Prints the Customer information
    void display(const Customers& c_rec) {
        cout << c_rec.user_name << ", "
            << c_rec.likes_count << ", "
            << c_rec.retweets_count << ", "
            << c_rec.replies_count << ", "
            << c_rec.share_videos << "\n\n";
    }

    // Prints a row number with a period before each user name. Then, it prints all the customers' records.
    void display(const CustomersRecord& t_rec) {
        for (int i = 0; i < t_rec.noOfRecords; i++) {
            cout << i + 1 << ". ";
            display(t_rec.ptr_rec[i]);
        }
    }
}

