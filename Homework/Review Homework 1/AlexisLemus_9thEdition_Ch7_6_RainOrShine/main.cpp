/* 
 * File:   main.cpp
 * Author: Alexis Lemus
 * Created on September 5, 2021, 8:27 PM
 * Purpose: Summer Weather Report.
 */

// System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// Function Prototypes.


// Execution begins here.
int main() {
    const int ROWS = 3;
    const int COLUMNS = 30;
    
    char weaData [ROWS][COLUMNS];   // Weather Data.
    string month [ROWS] = { "June", "July", "August" };
    int mIndex;         // Index for month.
    int dIndex;         // Index for days.
    int weCount;        // Counter to calculate amount of rainy days in a month.
    int mntRain;        // Counter to hold the month with the most rain.
    int mostR;          // Counter to calculate the most rain of a month.
    int totalRs;        // Total amount of rainy days.
    int totalCs;        // Total amount of cloudy days.
    int totalSs;        // Total amount of sunny days.
    ifstream inFile;
    
    // Initialize
    totalRs = 0;
    totalCs = 0;
    totalSs = 0;
    weCount = 0;
    mostR = 0;
    
    // Open the input file.
   inFile.open("RainOrShine.txt");
    
    // Read data from the file. 
    for (mIndex = 0; mIndex < 3; mIndex++) {
        for (dIndex = 0; dIndex < 30; dIndex++)
            inFile >> weaData[mIndex][dIndex];
    }
    
    // Close the input file.
    inFile.close();
    
    // Calculate amount of rainy, cloudy and sunny days each month.
    for (mIndex = 0; mIndex < 3; mIndex++) {
        for (dIndex = 0; dIndex < 30; dIndex++) {
            if (weaData[mIndex][dIndex] == 'R') totalRs++;
            if (weaData[mIndex][dIndex] == 'C') totalCs++;
            if (weaData[mIndex][dIndex] == 'S') totalSs++;
        }
    }
    
    // Calculate the month with the most rain.
    for (mIndex = 0; mIndex < 3; mIndex++) {
        int rCount = 0;     // Counter to compare months' rainy days.
        for (dIndex = 0; dIndex < 30; dIndex++) {
            if (weaData[mIndex][dIndex] == 'R') rCount++;
            if (rCount > mostR) mntRain = mIndex;
        }   
    }

    // Display amount of rainy, cloudy and sunny days each month,
    for (mIndex = 0; mIndex < 3; mIndex++) {
        cout << month[mIndex] << " Weather Report:" << endl << endl;
        for (dIndex = 0; dIndex < 30; dIndex++)
            if (weaData[mIndex][dIndex] == 'R') weCount++;
        cout << "# of Rainy Days: " << weCount << endl;
        weCount = 0;
        for (dIndex = 0; dIndex < 30; dIndex++)
            if (weaData[mIndex][dIndex] == 'C') weCount++;
        cout << "# of Cloudy Days: " << weCount << endl;
        weCount = 0;
        for (dIndex = 0; dIndex < 30; dIndex++)
            if (weaData[mIndex][dIndex] == 'S') weCount++;
        cout << "# of Sunny Days: " << weCount << endl << endl;
        weCount = 0;
    }
    
    // Display the amount of rainy, cloudy, and sunny days 
    // of the three month period.
    cout << "Combined Weather Report (June, July, August): " << endl << endl;
    cout << "# of Rainy Days: " << totalRs << endl;
    cout << "# of Cloudy Days: " << totalCs << endl;
    cout << "# of Sunny Days: " << totalSs << endl << endl;
    
    // Display the most rainy month.
    cout << "The rainiest month was " << month[mntRain] << ".";
    return 0;
}


