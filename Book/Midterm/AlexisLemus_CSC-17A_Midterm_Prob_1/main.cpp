/* 
  * File: Midterm Problem #1
  * Author: Alexis Lemus
  * Created on 10/18/2021
  * Purpose: Banking Application
  */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

struct BankAcnt {
    string actNo;               // Account number.
    string name;                // Account name.
    string addrss1;             // Account address line 1.
    string addrss2;             // Account address line 2.
    float initial;              // Initial balance.
    float *checks;              // Account debits.
    float *credits;             // Account deposits.
    float final;                // Final balance.
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void getData (BankAcnt [], int, bool);  // Fill the structure.
void printData (BankAcnt [], int);      // Print the array

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
        
    //Declare Variable Data Types and Constants
    int count;                    // Number of accounts.
    bool error;                   // Trigger when an invalid input is detected.
    char stop;                    // User input if user wants to stop.  
    BankAcnt *acnts;              // Dynamic memory allocation. 
        
    //Initialize Variables
    
    // Program intro
    cout << "************************************************" << endl;
    cout << "*************** Bank Application ***************" << endl;
    cout << "************************************************" << endl << endl;
    
    //Process or map Inputs to Outputs
    acnts = new BankAcnt[1];   // Dynamic memory allocation.
    for (int i = 0; i < 1; i++) {
        getData(acnts, i, error);
    }
    
    //Display Outputs
    cout << "************************************************" << endl;
    cout << "*************** Account Summary ****************" << endl;
    cout << "************************************************" << endl << endl;    
    for (int i = 0; i < 1; i++) {
        printData(acnts, i);
    }
    cout << "Thank you for using our program." << endl;
    
    // Give back memory.
    delete[] acnts[0].checks;
    delete[] acnts[0].credits;
    delete[] acnts;
    
    //Exit stage right!
    return 0;
}

void getData (BankAcnt acnts[], int index, bool error) {
    cout << "********************** Account Info : *************************\n";
    // Get account number.
    do {
        error = false;
        cout << "Enter your account number (Must be 5 digits): ";
        cin >> acnts[index].actNo;

        // Error checking.
        int size = acnts[index].actNo.length();
        
        if (size != 5) {
            cout << "Invalid response detected. Please try again." << endl;
            error = true;
        }
        else {
            for (int i = 0; i < 5; i++) {
                if (acnts[index].actNo[i] >= 58 || acnts[index].actNo[i] <= 47){
                    cout << "Invalid response detected. Please try again.\n";
                    error = true;
                }
            }
        }
    } while(error);
    cin.ignore();                   // Clear the line for upcoming getlines.
    
    // Get account name.
    cout << "Enter account name: ";
    getline(cin, acnts[index].name);
    
    // Get account address.
    cout << "Enter account address (line 1): ";
    getline(cin, acnts[index].addrss1);
    
    cout << "Enter account address (line 2): ";
    getline(cin, acnts[index].addrss2);
    
    // Get initial account balance.
    cout << "Enter the initial account balance this month: ";
    cin >> acnts[index].initial;
    
    // Copy initial to final.
    acnts[index].final = acnts[index].initial;
    
    // Get the checks used this month.
    int count;                // Amount of checks and deposits.
    float input;              // User input.
    
    do {
        error = false;
        cout << "Enter the amount of checks written this month: ";
        cin >> count;
        
        // Error checking
        if (count < 0){
            cout << "Cannot accept a negative value." << endl;
            cout << "Please try again." << endl;
            error = true;
        }
    } while (error);
    acnts[index].checks = new float[count+1];
    acnts[index].checks[0] = count;
    
    for (int i = 1; i < count+1; i++) {
        do {
            error = false;
            cout << "Enter the value of each check " << i << endl;
            cin >> input;

            if (input < 0){
                cout << "Cannot accept a negative value." << endl;
                cout << "Please try again." << endl;
                error = true;
            }
            if (!error) {
                acnts[index].checks[i] = input;
                acnts[index].final -= input; 
            }
        } while (error);
    }
    
    // Get the deposits for this month.
    do {
        error = false;
        cout << "Enter the amount of deposits made this month: ";
        cin >> count;
        
        // Error checking
        if (count < 0){
            cout << "Cannot accept a negative value." << endl;
            cout << "Please try again." << endl;
            error = true;
        }
    } while (error);
    acnts[index].credits = new float[count+1];
    acnts[index].credits[0] = count;
    
    for (int i = 1; i < count+1; i++) {
        do {
            error = false;
            cout << "Enter the value of each deposit " << i << endl;
            cin >> input;

            if (input < 0){
                cout << "Cannot accept a negative value." << endl;
                cout << "Please try again." << endl;
                error = true;
            }
            if (!error) {
                acnts[index].credits[i] = input;
                acnts[index].final += input;
            }
        } while (error);
    }
    
    cout << endl << endl;
}

void printData (BankAcnt acnts[], int index) {
    bool over;          // To trigger overdraft message.
    float checks = 0;   // Total checks written.
    float deps = 0;     // Total Deposits made.
    
    cout << "size of checks " << acnts[index].checks[0] << endl;
    cout << "size of deps " << acnts[index].credits[0] << endl;
    
    // Calculate total checks and deposits
    for (int i = 0; i < acnts[index].checks[0]; i++) {
        checks += acnts[index].checks[i+1];
        cout << "Checks " << i+1 << " " << acnts[index].checks[i+1] << endl;
    }
    
    for (int i = 0; i < acnts[index].credits[0]; i++) {
        deps += acnts[index].credits[i+1];
        cout << "Credits " << i+1 << " " << acnts[index].credits[i+1] << endl;
    }    
    over = (acnts[index].final < 0)?true:false;
    
    cout << fixed << showpoint << setprecision(2);      // Formatting.
    
    cout << "\tAccount Number:    " << acnts[index].actNo << endl;
    cout << "\tAccount Name:      " << acnts[index].name << endl;
    cout << "\tAccount Address:   " << acnts[index].addrss1 << endl;
    cout << "\t\t\t   " << acnts[index].addrss2 << endl;
    cout << "\tInitial Balance:   $" << acnts[index].initial << endl;
    cout << "\tChecks Disbursed:  $" << checks << endl;
    cout << "\tDeposits Received: $" << deps << endl;
    
    if (over) {
        cout << "\tATTENTION: Your account was overdrawn this month." << endl;
        cout << "\tA $25 overdraft has been incurred and will be debited\n";
        cout << "\tto the current balance of -$" << (acnts[index].final*-1);
        cout << "." << endl;
        acnts[index].final -= 25;
        cout << "\tFinal balance:    -$" << (acnts[index].final*-1);
        cout << endl << endl <<endl;
    }
    else {
        cout << "\tFinal balance:     $" << acnts[index].final << endl << endl;
        cout << endl << endl <<endl;
    }
}