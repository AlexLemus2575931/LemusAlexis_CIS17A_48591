/* 
 * File: main.cpp
 * Author: Alexis Lemus
 * Created on September 4, 2021, 12:54 PM
 * Purpose: Converting USD to Euros and Yen.
 */

// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

// Global Constants - No Global Variables.

// Function Prototypes
float US_TO_EU_CVN (float usd, const float EU_RATE);
float US_TO_YEN_CVN (float usd, const float YEN_RATE);

// Execution begins.
int main() {
    float usd;      // INPUT - User inputted value in USD.
    float yen;      // OUTPUT - The value in Yen converted from USD.
    float euro;     // OUTPUT - The value in Euro converted from USD.
    
    const float EU_RATE = .83932;  // CONSTANT - The Euro rate per 1 US dollar.
    const float YEN_RATE = 110.53; // CONSTANT - The Yen rate per 1 US dollar.
    
    // Computations are based off the currency exchange rate on June 23, 2021.
    // $1 USD = 0.83932 Euro
    // $1 USD = 110.53 Yen
    
    // Prompt the user to enter a value of US dollars.
    cout << "This program converts US Dollars to Euros and Japanese Yen.\n";
    cout << "How much would you like to convert? ";
    cin >> usd;
    
    // Call the conversion functions.
    euro = US_TO_EU_CVN (usd, EU_RATE);
    yen = US_TO_YEN_CVN (usd, YEN_RATE);
    
    cout << euro << endl;
    cout << yen << endl;

    // Setting notation
    cout << fixed << showpoint << setprecision(2);
    
    // Display the results to the user.
    cout << "You entered $" << usd << "." << endl;
    cout << "\t€" << euro << endl; 
    cout << "\t¥" << yen << endl;
    return 0;
}

float US_TO_EU_CVN (float usd, const float EU_RATE)
{
    float euro;
    euro = usd * EU_RATE;
    return euro;
}

float US_TO_YEN_CVN (float usd, const float YEN_RATE)
{
    float yen;
    yen = usd * YEN_RATE;
    return yen;
}

