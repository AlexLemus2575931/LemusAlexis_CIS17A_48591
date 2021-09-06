/* 
 * File:   main.cpp
 * Author: C3H8
 * Created on September 2, 2021, 5:19 PM
 * Purpose: Calculate the population increase of organisms.
 */

// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
void UnderTwo (int &sPop);   // Input validation for values under two.
void NegVal (float &rate);   // Input Validation for negative values (float).
void NegVal (int &days);     // Input validation for negative values (int).
void PopCalc (int sPop, float rate,
              int days, float popG); // Calculate population increase.

// Execution begins here.
int main() {
    int sPop;       // INPUT - Starting population entered by user.
    float rate;     // INPUT - Rate of increase (as a percent) entered by user. 
    int days;       // INPUT - User determined amount of days.
    float popG;     // OUTPUT - Population growth.
    
    // Initialization of population growth.
   // popG = 0;       
    
    // Ask the user to enter a starting population.
    cout << "This program calculates the increase of a population of organisms";
    cout << " over time." << endl;
    cout << "What is the starting population? ";
    cin >> sPop;
    
    // Call the input validation function for population.
    while (sPop < 2) UnderTwo (sPop);
    
    // Ask the user to enter the daily population increase (as a percent).
    cout << "Enter the daily population increase (as a percent): ";
    cin >> rate;
    
    // Call the input validation function for rate.
    while (rate < 0) NegVal (rate);
    
    // Ask the user to enter the amount of days.
    cout << "Enter the amount of days to calculate the population growth: ";
    cin >> days;
    
    // Call the input validation function for days.
    while (days < 0) NegVal(days);
    
    // Call the population calculation function.
    PopCalc (sPop, rate, days, popG);
    return 0;
}

void UnderTwo (int &sPop) {
    cout << "Starting population cannot be under 2. Please try again :";
    cin >> sPop;
}

void NegVal (float &value) {
    cout << "Cannot accept a negative value. Please try again: ";
    cin >> value;
}

void NegVal (int &value) {
    cout << "Cannot accept a negative value. Please try again: ";
    cin >> value;
}
                                                                                
void PopCalc (int sPop, float rate, int days, float popG) {
    // Setting up chart
    cout << "Day #" << setw(31) << "Population" << endl;
    cout << "------------------------------------" << endl;
    cout << "Day #1" << setw(29) << sPop << endl;  
    
    // Initializing popG for calculations.
    popG = sPop;
    
    // Set Precision to round up.
    cout << fixed << setprecision(0);
    
    for (int index = 1; index < days; index++) {
        // Calculate the population increase.
        popG = (popG * rate) + popG;
        
        // Display the results.
        cout << "Day #" << (index + 1) << setw(29) << popG << endl;  
    }
}

