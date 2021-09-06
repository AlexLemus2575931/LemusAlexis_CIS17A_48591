/* 
 * File:   main.cpp
 * Author: Alexis Lemus
 * Created on September 6, 2021, 2:46 PM
 * Purpose: Convert Celsius to Fahrenheit
 */

// System Libraries
#include <iostream>
using namespace std;

// Global Constants - No Global Variables.
// Function Prototypes
float C_TO_F_CVN (float tempC);

// Execution begins.
int main() {
    // Declaring variables.
    float tempC;    // INPUT - Temperature in Celsius.
    float tempF;    // OUTPUT - Temperature in Fahrenheit
    
    // Ask the user what temperature they would like to convert.
    cout << "This program accepts a temperature in Celsius and converts ";
    cout << "it to Fahrenheit: ";
    cin >> tempC;
    
    tempF = C_TO_F_CVN (tempC);
    
    cout << tempC << " is equal to " << tempF << " in Fahrenheit.";
    return 0;
}

float C_TO_F_CVN (float tempC)
{
    float tempF;
    tempF = ((9 * tempC) / 5) + 32;
    return tempF;
}

