/* 
 * File: Ch 12 #11
 * Author: Alexis Lemus
 * Created on 10/13/2021
 * Purpose: Save each division's data into a file.
*/

//System Libraries
#include <iostream>
#include <string>
#include <fstream>
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
void validation(float&);
void sendToFile (Division);

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
    getData(south);
    
    // Print data to file.
    cout << endl << endl;
    cout << "Now transferring this data to text file: \"Company Data.txt\" ...";
    cout << endl;
    
    sendToFile(north);
    sendToFile(west);
    sendToFile(east);
    sendToFile(south);
    
    cout << "Done." << endl;
    
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
}

void sendToFile (Division div) {
    // Open the file
    fstream file("Company Data.txt", ios::out | ios::app);
  
    // begin printing to output file.
    file << "*********************************************************" << endl;
    file << "****************** " << div.name<< " **********************";
    file << "**********" << endl;
    file << "*********************************************************" << endl;
    file << endl;
    file << fixed << showpoint << setprecision(2);
    file << "\tQuarter 1 Sales: $" << div.q1Sales << endl;
    file << "\tQuarter 2 Sales: $" << div.q2Sales << endl;
    file << "\tQuarter 3 Sales: $" << div.q3Sales << endl;
    file << "\tQuarter 4 Sales: $" << div.q4Sales << endl << endl;
    file << "\tQuarterly Sales: $" << div.avgSales << endl << endl << endl;
    
    // Close the file
    file.close();
}