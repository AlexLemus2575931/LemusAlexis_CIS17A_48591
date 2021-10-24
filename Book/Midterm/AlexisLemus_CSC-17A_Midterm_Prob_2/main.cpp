/* 
  * File: Midterm Prob #2
  * Author: Alexis Lemus
  * Created on 10/19/2021
  * Purpose: Generate Paychecks for Workers. 
  */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
//#include <ctime>
using namespace std;

//User Libraries
struct EmployeeInfo {
    string name;    // Employee name.
    float hours;    // Hours worked.
    float rate;     // Pay rate.
    float gross;    // Gross pay.
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void getData(EmployeeInfo [], int);          // Retrieve data for employees.
void errorCheck(float &);                    // Input Validation.
float grossPay(EmployeeInfo [], int,         // Returns employees gross pay. 
               const int, const int);             
void PrntCheck(EmployeeInfo [], int, string, // Print Employee Check
               string, string);
void Number2English(float);                  // Converting number to English.

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
        
    //Declare Variable Data Types and Constants
    EmployeeInfo *emps;     // Dynamically allocated structure.
    int count;              // Number of employees to enter.
    bool error;             // Triggers when an invalid input is detected.
    string cmpName;         // Company name.
    string addrss1;         // Company Address Line 1.
    string addrss2;         // Company Address Line 2.
    
    //Initialize Variables
    const int PAY_DBL = 40; // Pay double after  40 hours.
    const int PAY_TRI = 60; // Pay triple after 60 hours.
    cmpName = "Lehr Industries Inc.";
    addrss1 = "4800 Magnolia Ave.";
    addrss2 = "Riverside, CA 92506";
    
    // Program intro
    cout << "************************************************" << endl;
    cout << "************* Paycheck Generator ***************" << endl;
    cout << "************************************************" << endl << endl;
    do {
        error = false;
        cout << "Enter the amount of employees you would like to enter: ";
        cin >> count;
        
        // Error checking
        if (count <= 0){
            cout << "Cannot accept a negative or zero value." << endl;
            cout << "Please try again." << endl;
            error = true;
        }
    } while (error);
    cout << endl;
    
    //Process or map Inputs to Outputs
    emps = new EmployeeInfo[count];     // Dynamic memory allocation.
    
    for (int i = 0; i < count; i++)     // Call getData function.
        getData(emps, i);
    
    for (int i = 0; i < count; i++)     // Call grossPay function.
        emps[i].gross = grossPay(emps, i, PAY_DBL, PAY_TRI);
    
    //Display Outputs
    for (int i = 0; i < count; i++)     // Call printCheck function.
        PrntCheck(emps, i, cmpName, addrss1, addrss2);
    
    //Exit stage right!
    return 0;
}

void getData(EmployeeInfo emps[], int index) {
    cout << "************* Employee Number: " << index+1 << " **************\n";
    
    // Get the employee name. 
    cin.ignore();                    // Clear the line for the upcoming getline.
    cout << "Enter the employee's name: ";
    getline(cin, emps[index].name);
    
    // Get the number of hours worked.
    cout << "Enter number of hours worked by " << emps[index].name << ": ";
    cin >> emps[index].hours;
    errorCheck(emps[index].hours);      // Input Validation.
    
    // Get the rate of pay.
    cout << "Enter the rate of pay for " << emps[index].name << ": ";
    cin >> emps[index].rate;
    errorCheck(emps[index].rate);
}

void errorCheck(float &value) {
    if (value < 0) {
        do {
            cout << "Cannot accept negative values. Please try again." << endl;
            cin >> value;
        } while (value < 0);
    }
}

float grossPay(EmployeeInfo emps[],int index, const int DBL, const int TRI) {
    float gross = 0;
    if (emps[index].hours > TRI) {
        gross += emps[index].rate * 40;
        gross += emps[index].rate * 2 * 20;
        gross += emps[index].rate * 3 * (emps[index].hours - TRI);
    }
    else if (emps[index].hours > DBL && emps[index].hours <= TRI) {
        gross += emps[index].rate * 2 * (emps[index].hours - DBL);
        gross += emps[index].rate * 40;        
    }
    else
        gross += emps[index].rate * emps[index].hours;
    
    return gross;
}

void PrntCheck(EmployeeInfo emps[], int index, string cmpName,
               string addrss1, string addrss2) {
    cout << fixed << showpoint << setprecision(2); 
    cout << endl << endl << endl;
    cout << cmpName << endl;
    cout << addrss1 << endl;
    cout << addrss2 << endl << endl;
    cout << "Pay to the" << endl;
    cout << "Order of " << emps[index].name << setw(30) << "$";
    cout << emps[index].gross << endl;
    
    Number2English(emps[index].gross);
    cout << endl;
    
    cout << setw(7) << " " << "x________________________________________";          
}

void Number2English(float value) {
    int n2Cnvrt = value;
    int penny = (value - static_cast<float>(n2Cnvrt)) * 100; 
    
    
    //Determine 1000's, 100's, 10's, 1's
    int n1000s,n100s,n10s,n1s;
    n1000s=n2Cnvrt/1000;   //Shift 3 places to the left
    n100s=n2Cnvrt%1000/100;//Remainder of division of 1000 then shift 2 left
    n10s=n2Cnvrt%100/10;   //Remainder of division of 100 then shift 1 left
    n1s=n2Cnvrt%10;        //Remainder of division by 10
        
    //Output the number of 1000's in Roman Numerals
    //Using the Switch Statement
    if (n1000s > 0) {
        if (n1000s > 99) {
            if(n1000s >= 900 && n1000s < 1000)cout<<"Nine HUndred ";
            if(n1000s >= 800 && n1000s < 900)cout<<"Eight Hundred ";
            if(n1000s >= 700 && n1000s < 800)cout<<"Seven Hundred ";
            if(n1000s >= 600 && n1000s < 700)cout<<"Six Hundred ";
            if(n1000s >= 500 && n1000s < 600)cout<<"Five Hundred ";
            if(n1000s >= 400 && n1000s < 500)cout<<"Four Hundred ";
            if(n1000s >= 300 && n1000s < 400)cout<<"Three Hundred ";
            if(n1000s >= 200 && n1000s < 300)cout<<"Two Hundred ";
            if(n1000s >= 100 && n1000s < 200)cout<<"One Hundred ";
                
            if (n1000s%10 != 0) {
                if(n1000s%10==9)cout<<"Nine ";
                else if(n1000s%10==8)cout<<"Eight ";
                else if(n1000s%10==7)cout<<"Seven ";
                else if(n1000s%10==6)cout<<"Six ";
                else if(n1000s%10==5)cout<<"Five ";
                else if(n1000s%10==4)cout<<"Four ";
                else if(n1000s%10==3)cout<<"Three ";
                else if(n1000s%10==2)cout<<"Two ";
                else if(n1000s%10==1)cout<<"One ";
                }
            }
        if (n1000s > 19) {
            if(n1000s >= 90 && n1000s < 100)cout<<"Ninety ";
            if(n1000s >= 80 && n1000s < 90)cout<<"Eighty ";
            if(n1000s >= 70 && n1000s < 80)cout<<"Seventy ";
            if(n1000s >= 60 && n1000s < 70)cout<<"Sixty ";
            if(n1000s >= 50 && n1000s < 60)cout<<"Fifty ";
            if(n1000s >= 40 && n1000s < 50)cout<<"Forty ";
            if(n1000s >= 30 && n1000s < 40)cout<<"Thirty ";
            if(n1000s >= 20 && n1000s < 30)cout<<"Twenty ";
                
            if (n1000s%10 != 0) {
                if(n1000s%10==9)cout<<"Nine ";
                else if(n1000s%10==8)cout<<"Eight ";
                else if(n1000s%10==7)cout<<"Seven ";
                else if(n1000s%10==6)cout<<"Six ";
                else if(n1000s%10==5)cout<<"Five ";
                else if(n1000s%10==4)cout<<"Four ";
                else if(n1000s%10==3)cout<<"Three ";
                else if(n1000s%10==2)cout<<"Two ";
                else if(n1000s%10==1)cout<<"One ";
            }
        }
        if(n1000s==19)cout<<"Nineteen ";
        else if(n1000s==18)cout<<"Eighteen ";
        else if(n1000s==17)cout<<"Seventeen ";
        else if(n1000s==16)cout<<"Sixteen ";
        else if(n1000s==15)cout<<"Fifteen ";
        else if(n1000s==14)cout<<"Fourteen ";
        else if(n1000s==13)cout<<"Thirteen ";
        else if(n1000s==12)cout<<"Twelve ";
        else if(n1000s==11)cout<<"Eleven ";
        else if(n1000s==10)cout<<"Ten ";
        else if(n1000s==9)cout<<"Nine ";
        else if(n1000s==8)cout<<"Eight ";
        else if(n1000s==7)cout<<"Seven ";
        else if(n1000s==6)cout<<"Six ";
        else if(n1000s==5)cout<<"Five ";
        else if(n1000s==4)cout<<"Four ";
        else if(n1000s==3)cout<<"Three ";
        else if(n1000s==2)cout<<"Two ";
        else if(n1000s==1)cout<<"One ";
            
        cout << "Thousand ";
    }
        
    //Output the number of 100's
    //Using the Ternary Operator
    cout<<(n100s==9?"Nine Hundred ":
           n100s==8?"Eight Hundred ":
           n100s==7?"Seven Hundred ":
           n100s==6?"Six Hundred ":
           n100s==5?"Five Hundred ":
           n100s==4?"Four Hundred ":
           n100s==3?"Three Hundred ":
           n100s==2?"Two Hundred ":
           n100s==1?"One Hundred ":"");
        
    //Output the number of 10's
    //Using Independent If Statements
    if(n10s==9)cout<<"Ninety ";
    if(n10s==8)cout<<"Eighty ";
    if(n10s==7)cout<<"Seventy ";
    if(n10s==6)cout<<"Sixty ";
    if(n10s==5)cout<<"Fifty ";
    if(n10s==4)cout<<"Forty ";
    if(n10s==3)cout<<"Thirty ";
    if(n10s==2)cout<<"Twenty ";
    if(n10s==1) {
        if(n1s==9)cout<<"Nineteen ";
        else if(n1s==8)cout<<"Eighteen ";
        else if(n1s==7)cout<<"Seventeen ";
        else if(n1s==6)cout<<"Sixteen ";
        else if(n1s==5)cout<<"Fifteen ";
        else if(n1s==4)cout<<"Fourteen ";
        else if(n1s==3)cout<<"Thirteen ";
        else if(n1s==2)cout<<"Twelve ";
        else if(n1s==1)cout<<"Eleven ";
        else cout << "Ten";
        n1s=0;
    }
        
    //Output the number of 1's
    //Using Dependent If Statements
    if(n1s==9)cout<<"Nine ";
    else if(n1s==8)cout<<"Eight ";
    else if(n1s==7)cout<<"Seven ";
    else if(n1s==6)cout<<"Six ";
    else if(n1s==5)cout<<"Five ";
    else if(n1s==4)cout<<"Four ";
    else if(n1s==3)cout<<"Three ";
    else if(n1s==2)cout<<"Two ";
    else if(n1s==1)cout<<"One ";
        
    // Penny value.
    cout << "and ";
    cout << penny << " / 100 Dollars" << endl;
}