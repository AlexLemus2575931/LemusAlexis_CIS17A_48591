/* 
 * File:   main.cpp
 * Author: C3H8
 * Created on September 3, 2021, 7:26 PM
 * Purpose: Fahrenheit to Celsius Conversion Table.
 */

// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
void TempTab (const int LOW_END, const int TOP_END, int tempF);
float Celsius (float tempF);

int main() {
    const int LOW_END = 0;       // Beginning of the table.
    const int TOP_END = 20;      // Beginning of the table.
    
    int tempF;
    
    // Call the temperature table function.
    TempTab (LOW_END, TOP_END, tempF);
    return 0;
}

void TempTab (const int LOW, const int TOP, int tempF) {
    // Setting up table.
    cout << "Fahrenheit" << setw(25) << "Celsius" << endl;
    cout << "---------------------------------------------" << endl;
    
    // Setting precision.
    cout << fixed << showpoint << setprecision(1);
    
    // Begin for loop.
    for (int index = LOW; index <= TOP; index++) {
        float tempC;
        tempF = index;
        // Call the Celsius conversion function.
        tempC = Celsius (tempF);
        
        // Display table.
        cout << left << setw(28) << index  << " " << setw(6) << tempC << endl;
    }
}

float Celsius (float tempF) {
    float tempC;
    tempC = (tempF - 32) * 5 / 9;
    return tempC;
}