/* 
 * File: Code-E Chapter 11 Structures Q1
 * Author: Alexis Lemus
 * Created on 10/6/2021
 * Purpose: Calculate each division's total and average sales.
*/

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
struct Division {
    string name;        // Division name.
    float q1Sales;      // 1st Quarter sales.
    float q2Sales;      // 2nd Quarter sales.
    float q3Sales;      // 3rd Quarter sales.
    float q4Sales;      // 4th Quarter sales.
    float total;        // Total annual sales.
    float avgSales;     // Average quarterly sales.
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void getData (Division&);
void lastData (Division&);      // Last data excludes final endl for formatting.

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Division north = {"North"};
    Division west = {"West"};
    Division east = {"East"};
    Division south = {"South"};
    
    //Process or map Inputs to Outputs
    getData(north);
    getData(west);
    getData(east);
    lastData(south);

    //Exit stage right!
    return 0;
}

void getData (Division& div) {
    cout << div.name << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> div.q1Sales;
    cout << "Enter second-quarter sales:" << endl;
    cin >> div.q2Sales;
    cout << "Enter third-quarter sales:" << endl;
    cin >> div.q3Sales;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> div.q4Sales;
    
    // Calculate the total annual sales and average quarterly sales.
    div.total = div.q1Sales + div.q2Sales + div.q3Sales + div.q4Sales;
    div.avgSales = div.total/4;
    
    cout << fixed << showpoint << setprecision(2);
    
    cout << "Total Annual sales:$" << div.total << endl;
    cout << "Average Quarterly Sales:$" << div.avgSales << endl;
}

void lastData (Division& div) {
    cout << div.name << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> div.q1Sales;
    cout << "Enter second-quarter sales:" << endl;
    cin >> div.q2Sales;
    cout << "Enter third-quarter sales:" << endl;
    cin >> div.q3Sales;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> div.q4Sales;
    
    // Calculate the total annual sales and average quarterly sales.
    div.total = div.q1Sales + div.q2Sales + div.q3Sales + div.q4Sales;
    div.avgSales = div.total/4;
    
    cout << fixed << showpoint << setprecision(2);
    
    cout << "Total Annual sales:$" << div.total << endl;
    cout << "Average Quarterly Sales:$" << div.avgSales;
}