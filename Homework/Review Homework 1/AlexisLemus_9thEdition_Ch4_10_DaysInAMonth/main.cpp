/*
 * File:   main.cpp
 * Author: Alexis Lemus
 * Created on September 2, 2021, 6:03 PM
 * Purpose: Determine the number of days in a given month/year.
 */

// System Libraries
#include <iostream>
using namespace std;

// Global Constants
const int JAN = 1;
const int FEB = 2;
const int MAR = 3;
const int APR = 4;
const int MAY = 5;
const int JUN = 6;
const int JUL = 7;
const int AUG = 8;
const int SEP = 9;
const int OCT = 10;
const int NOV = 11;
const int DEC = 12;

// Execution of code begins here.
int main() {
    int month;      // INPUT - Month number.
    int year;     // INPUT - Year.
    bool leap;      // FLAG - To mark if leap year.
    
    // Ask the user to input a month.
    cout << "This program determines how many days are in the specified month.";
    cout << endl << "Enter a month (1-12): ";
    cin >> month;
    
    // Input validation.
    while (month <= 0 || month > 12) {
        cout << "Invalid input. Please enter a valid month (1-12): ";
        cin >> month;
    }
    
    // Ask the user to input the year.
    cout << "Enter a year: ";
    cin >> year;
    
    // Determine if it is a leap year.
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) leap == true;
            else leap = false;
        }
        else leap = true;
    }
    else leap = false;
    
    switch (month) {
        case JAN: cout << "31 days."; break;
        case FEB: // Determine if it is a leap year.
            if (leap = true) cout << "29 days.";
            else  cout << "28 days."; break;
        case MAR: cout << "31 days."; break;
        case APR: cout << "30 days."; break;
        case MAY: cout << "31 days."; break;
        case JUN: cout << "30 days."; break;
        case JUL: cout << "31 days."; break;
        case AUG: cout << "31 days."; break;
        case SEP: cout << "30 days."; break;
        case OCT: cout << "31 days."; break;
        case NOV: cout << "30 days."; break;
        case DEC: cout << "31 days."; break;
    }
    return 0;
}

