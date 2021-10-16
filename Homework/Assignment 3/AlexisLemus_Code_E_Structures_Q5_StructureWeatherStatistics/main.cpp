/* 
 * File: Code-E Chapter 11 Structures Q5
 * Author: Alexis Lemus
 * Created on 10/6/2021
 * Purpose: Calculate and display weather statistics
*/

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries
struct WeatherStats {
    string month;           // Month.
    int totalR;             // Total rain
    int tempL;              // Low temperature    
    int tempH;              // High temperature
    float avgTemp;          // Average temperature
    
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void getData(WeatherStats [], const int);      // Retrieve data from User
void AvgMon(WeatherStats [], const int);       // Calculate average monthly temperature.
void AvgRain(WeatherStats [], const int);      // Display average rainfall.
void LowTemp(WeatherStats [], const int);      // Display lowest temp.
void HighTemp(WeatherStats [], const int);     // Display highest temp.
void AvgTemp(WeatherStats [], const int);      // Display average yearly temp.

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    const int MONTHS = 12;        // Amount of months
    WeatherStats weather[MONTHS];
                               
    //Process or map Inputs to Outputs
    getData(weather, MONTHS);
    AvgMon(weather, MONTHS);
    AvgRain(weather, MONTHS);
    LowTemp(weather, MONTHS);
    HighTemp(weather, MONTHS);
    AvgTemp(weather, MONTHS);

    //Exit stage right!
    return 0;
}

void getData(WeatherStats weather[], const int size) {
    for (int i = 0; i < size; i++) {
        cin >> weather[i].month >> weather[i].totalR;
        cin >> weather[i].tempL >> weather[i].tempH;
        cin.ignore();
    }
}

void AvgMon(WeatherStats weather[], const int size) {
    for (int i = 0; i < size; i++)
        weather[i].avgTemp = (static_cast<float>(weather[i].tempH)+static_cast<float>(weather[i].tempL))/2.0f;
}

void AvgRain(WeatherStats weather[], const int size) {
    float avg = 0;
    for (int i = 0; i < size; i++) 
        avg += (static_cast<float>(weather[i].totalR));
        
    avg = avg/12.0f;
    cout << fixed << showpoint << setprecision(1);
    cout << "Average Rainfall " << avg << " inches/month" << endl;
}

void LowTemp(WeatherStats weather[], const int size) {
    int lowTemp = 140;
    int lowIndex;           // To hold the element of the month.
    for(int i = 0; i < size; i++) {
        if (weather[i].tempL < lowTemp) {
            lowTemp = weather[i].tempL;
            lowIndex = i;
        }
    }
    
    cout << "Lowest  Temperature " << weather[lowIndex].month;
    cout << "  " << weather[lowIndex].tempL << " Degrees Fahrenheit" << endl;
}

void HighTemp(WeatherStats weather[], const int size) {
    int highTemp = -100;
    int highIndex;           // To hold the element of the month.
    for(int i = 0; i < size; i++) {
        if (weather[i].tempH > highTemp) {
            highTemp = weather[i].tempH;
            highIndex = i;
        }
    }
    
    cout << "Highest Temperature " << weather[highIndex].month;
    cout << "  " << weather[highIndex].tempH << " Degrees Fahrenheit" << endl;
}

void AvgTemp(WeatherStats weather[], const int size) {
    float average = 0;
    for (int i = 0; i < size; i++) {
        average += weather[i].avgTemp;
    }
    average = average/size;
    cout << "Average Temperature for the year " << static_cast<int>(round(average));
    cout << " Degrees Fahrenheit" << endl;
}