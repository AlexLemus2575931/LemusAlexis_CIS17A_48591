/* 
 * File: Midterm Problem #8
 * Author: Dr Mark E. Lehr
 * Purpose:  Menu using Functions,
 *           extend for midterm
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

//User Libraries
struct BankAcnt {               // For Problem 1
    string actNo;               // Account number.
    string name;                // Account name.
    string addrss1;             // Account address line 1.
    string addrss2;             // Account address line 2.
    float initial;              // Initial balance.
    float *checks;              // Account debits.
    float *credits;             // Account deposits.
    float final;                // Final balance.
};

struct EmployeeInfo {           // For Problem 2
    string name;    // Employee name.
    float hours;    // Hours worked.
    float rate;     // Pay rate.
    float gross;    // Gross pay.
};

struct Prime {                  // For Problem 7
    unsigned short prime;
    unsigned char power;
};

struct Primes {                 // For Problem 7
    unsigned char nPrimes;
    Prime *prime;
};

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm4a();
void prblm4b();
void prblm5();
void prblm6();
void prblm7();

// Functions for problem 1.
void getData (BankAcnt [], int, bool);      // Fill the structure.
void printData (BankAcnt [], int);          // Print the array

// Functions for problem 2
void getData(EmployeeInfo [], int);          // Retrieve data for employees.
void errorCheck(float &);                    // Input Validation.
float grossPay(EmployeeInfo [], int,         // Returns employees gross pay. 
               const int, const int);             
void PrntCheck(EmployeeInfo [], int, string, // Print Employee Check
               string, string);
void Number2English(float);                  // Converting number to English.

// Functions for Problem 4a
bool errorCheck(int [], const int);
bool errorCheck2(int [], const int);
void encryption(int [], const int);

// Functions for Problem 4b
void Decryption(int [], const int);

// Functions for Problem 7
Primes *factor(int);    // Input an integer and return all prime factors.
void prntPrm(Primes *);   // Output all prime factors.
int getPrimes(int);            // Returns number of primes.
int *fillAry(int, int);        // Returns array of primes.
int **fctrAry(int *, int, int);// Fills 2d array of factors and powers.

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    // Program Intro
    cout << "*************** Alexis Lemus Midterm Menu ***************" << endl;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='8');
    
    //Exit stage right!
    return 0;
}

void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl; 
    cout<<"Type 6 for Problem 6"<<endl; 
    cout<<"Type 7 for Problem 7"<<endl<<endl;
}


void prblm1(){
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
}

void prblm2(){
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
}

void prblm3(){
    cout<<"Problem 3 is outside of this project."<<endl;
}

void prblm4() {
    char input;
    cout << "Do you want to encrypt or decrypt?\n";
    cout << "\t1. Encrypt\n";
    cout << "\t2. Decrypt\n";
    cin >> input;
    
    switch (input) {
        case '1':{prblm4a(); break;}
        case '2':{prblm4b(); break;}
        default: cout << "Return to main menu..." << endl;
    }
    cout << endl;
}

void prblm4a(){
    //Declare Variable Data Types and Constants
    const int MAX_SIZE = 4;         // Max amount 
    const int MAX_DGT = 7;          // A digit cannot be larger than 7.
    bool error;                     // Triggers when an error occurs.
    bool error2;                    // Triggers when an error occurs.
    char input[MAX_SIZE];           // Array of chars.
    int data[MAX_SIZE];             // Array of ints.
        
    //Initialize Variables
    
    // Program intro
    cout << "************************************************" << endl;
    cout << "************ Encryption Application ************" << endl;
    cout << "************************************************" << endl << endl;
    
    do {
        error2 = false;
        do {
            cout << "Enter the four digit number you would like to encrypt :\n";       
            cin >> input[0] >> input[1] >> input[2] >> input[3];        
            error = false;
            for (int i = 0; i < MAX_SIZE; i++) {
                data[i] = input[i];
                data[i] -= '0';     // Convert to regular digit.
            }
            error = errorCheck(data, MAX_SIZE);
        } while (error);
        
        //Process or map Inputs to Outputs
        encryption(data, MAX_SIZE);        
        error2 = errorCheck(data, MAX_SIZE);
    } while (error2);
        
    //Display Outputs
    cout << "The new encrypted is ";
    for (int i = 0; i < MAX_SIZE; i++)
        cout << data[i];
}

void prblm4b() {
    //Declare Variable Data Types and Constants
    const int MAX_SIZE = 4;         // Max amount 
    const int MAX_DGT = 7;          // A digit cannot be larger than 7.
    bool error;                     // Triggers when an error occurs.
    bool error2;                    // Triggers when an error occurs.
    char input[MAX_SIZE];           // Array of chars.
    int data[MAX_SIZE];             // Array of ints.
        
    //Initialize Variables
    
    // Program intro
    cout << "************************************************" << endl;
    cout << "************ Decryption Application ************" << endl;
    cout << "************************************************" << endl << endl;
    
    do {
        error2 = false;
        do {
            cout << "Enter the four digit number you would like to decrypt :\n";       
            cin >> input[0] >> input[1] >> input[2] >> input[3];        
            error = false;
            for (int i = 0; i < MAX_SIZE; i++) {
                data[i] = input[i];
                data[i] -= '0';     // Convert to regular digit.
            }
            error = errorCheck(data, MAX_SIZE);
        } while (error);
        
        //Process or map Inputs to Outputs
        Decryption(data, MAX_SIZE);        
        error2 = errorCheck2(data, MAX_SIZE);
    } while (error2);
        
    //Display Outputs
    cout << "The decrypted number is ";
    for (int i = 0; i < MAX_SIZE; i++)
        cout << data[i];
}

void prblm5(){
    cout<<"problem 5: Factorials and data overflow"<<endl << endl;
    cout << "Char data type overflows after: 6\n";
    cout << "Unsigned Char data type overflows after: 7\n";
    cout << "Short data type overflows after: 7\n";
    cout << "Unsigned Short data type overflows after: 8\n";
    cout << "int data type overflows after: 7\n";
    cout << "Unsigned int data type overflows after: 12\n";
    cout << "long data overflows after: 12\n";
    cout << "unsigned long data overflows after: 12\n";
    cout << "unsigned long long data overflows after: 20\n";
    cout << "float data type overflows after: 13\n";    
    cout << endl << endl;
}

void prblm6(){
    cout << "problem 6: Hand written work can be found in the folder."<<endl;
    
    cout << "49.1875 base 10" << endl;
    cout << "\t110001.0011 base 2" << endl;
    cout << "\t61.14       base 8" << endl;
    cout << "\t31.3        base 16" << endl;
    cout << "\tNASA Format: 626000 06" << endl;
    
    cout << "3.07421875 base 10" << endl;
    cout << "\t11.00010011 base 2" << endl;
    cout << "\t3.046       base 8" << endl;
    cout << "\t31.3        base 16" << endl;
    cout << "\tNASA Format: 626000 02" << endl;
    
    cout << "0.2 base 10" << endl;
    cout << "\t0.0011      base 2" << endl;
    cout << "\t0.1463      base 8" << endl;
    cout << "\t0.3         base 16" << endl;    
    cout << "\tNASA Format: 666666 FE" << endl;
    
    cout << "-49.1875 base 10" << endl;
    cout << "\t1110.1101   base 2" << endl;
    cout << "\t16.15       base 8" << endl;
    cout << "\tE.D         base 16" << endl;
    cout << "\tNASA Format: 768000 04" << endl;
    
    cout << "-3.07421875 base 10" << endl;
    cout << "\t0.11101101  base 2" << endl;
    cout << "\t0.732       base 8" << endl;
    cout << "\t0.ED        base 16" << endl;
    cout << "\tNASA Format: 768000 00" << endl;
    
    cout << "-0.2 base 10" << endl;
    cout << "\t1.1101      base 2" << endl;
    cout << "\t1.6735      base 8" << endl;
    cout << "\t1.D         base 16" << endl;    
    cout << "\tNASA Format: 777777 01" << endl;
    
    cout << "699999 02 in base 10 is 3.296875" << endl;
    cout << "699999 03 in base 10 is 6.5625" << endl;
    cout << "966667 FF in base 10 is -0.966667" << endl;
}

void prblm7(){
//Declare Variable Data Types and Constants
    int input;
    bool error;
    Primes *data = new Primes[1];

    //Initialize Variables
        
    //Process or map Inputs to Outputs
    cout << "************************************************" << endl;
    cout << "*********** Factorization Application **********" << endl;
    cout << "************************************************" << endl << endl;    
    
    do {
        error = false;
        cout << "Enter the integer you would like to see the prime factors of:\n";
        cout << "(NOTE: Can only accept values between 2 and 65,000)\n";
        cin >> input;
        
        if (input > 65000 || input < 2) {
            error = true;
            cout << "Invalid input detected. Please try again..." << endl;
        }
    } while (error);
    
    data = factor(input);
        
    //Display Outputs
    cout << input << " = ";
    prntPrm(data);
    
    // Destroy
    delete[] data[0].prime;
    delete[] data;
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
    cout << endl << endl;
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

bool errorCheck(int data[], const int SIZE) {
    bool result = false;
    for (int i = 0; i < SIZE; i++) {
        if (data[i] > 7) {
            cout << "Cannot accept any digits over 7. Please try again.\n";
            result = true;
        }    
    }
    return result;
}

void encryption(int data[], const int SIZE) {
    for (int i = 0; i < SIZE; i++)
        data[i] = (data[i] + 3) % 8; 
    
    // Swaps
    swap(data[0], data[2]);
    swap(data[1], data[3]);
}

bool errorCheck2(int data[], const int SIZE) {
    bool result = false;
    for (int i = 0; i < SIZE; i++) {
        if (data[i] > 7) {
            cout << "ERROR: A digit greater than 7 was generated.\n";
            cout << "Please try again." << endl;
            result = true;
        }    
    }
    return result;    
}

void Decryption(int data[], const int SIZE) {
    for (int i = 0; i < SIZE; i++)
        data[i] = (data[i] + 5) % 8; 
    
    // Swaps
    swap(data[0], data[2]);
    swap(data[1], data[3]);
}

Primes *factor(int input) {
    int nPrimes;
    int *primAry;       // Array of prime numbers
    nPrimes = getPrimes(input);
    primAry = new int [nPrimes];
    primAry = fillAry(input, nPrimes);
    Primes *data = new Primes[1];
    
    // Find the number of unique factors
    int tester = -1;
    int unique = 0;
    for (int i = 0; i < nPrimes; i++) {
        if (tester != primAry[i]) {
            unique++;
            tester = primAry[i]; 
        }
    }
    
    int **array = new int *[unique];
    for (int i = 0; i < unique; i++)
        array[i] = new int[unique]; 
        
    data[0].prime = new Prime[unique];
    array = fctrAry(primAry, nPrimes, unique);
    
    // Load structure with 2d array.
    data[0].nPrimes = unique;
    for (int i = 0; i < unique; i++) {
        data[0].prime[i].prime = array[i][0];
    }
    for (int i = 0; i < unique; i++) {
        data[0].prime[i].power = array[i][1];
    }
    
    // Destroy
    delete[] primAry;
    for (int i = 0; i < unique; i++)
        delete[] array[i];
    delete[] array;
    
    return data;
}

void prntPrm(Primes *data) {
    
   for (int i = 0; i < data[0].nPrimes; i++) {
       if (i == data[0].nPrimes-1) {
           cout << data[0].prime[i].prime << "^" << int(data[0].prime[i].power);
            cout << endl;
       }
       else {
        cout << data[0].prime[i].prime << "^" << int(data[0].prime[i].power);
        cout << " * ";
       }
   }
    
}

int getPrimes(int input) {
    int count = 0;
    while (input % 2 == 0){
        count++;
        input = input/2;
    }

    for (int i = 3; i <= sqrt(input); i = i + 2){
        while (input % i == 0){
            count++;
            input = input/i;
        }
    }
 
    if (input > 2) {
        count++;
    }
    return count;
}

int *fillAry(int input, int size) {
    int *ary = new int [size];
    int index = 0;
    while (input % 2 == 0){
        ary[index] = 2;
        input = input/2;
        index++;
    }

    for (int i = 3; i <= sqrt(input); i = i + 2){
        // While i divides n, print i and divide n
        while (input % i == 0){
            ary[index] = i;
            index++;
            input = input/i;
        }
    }
 
    if (input > 2) {
        ary[index] = input;
        index++;
    }
    return ary;    
}

int **fctrAry(int *ary, int size, int unique) {
    int **ary2 = new int *[unique];
    for (int i = 0; i < unique; i++)
        ary2[i] = new int[unique];    

    // Make an array with unique factors only.
    int *uAry = new int [unique];
    int tester = -1;
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (tester != ary[i]) {
            uAry[index] = ary[i];            
            tester = ary[i];
            index++;
        }
    }
    
    // Initialize array to zero
    for (int i = 0; i < unique; i++) {
        for (int j = 0; j < unique; j++)
            ary2[i][j] = 0;
    }
    
    // Fill one column of 2d array with unique array.
    for (int i = 0; i < unique; i++) 
        ary2[i][0] = uAry[i];  
    
    // Fill 2nd column of 2d array
    index = 0;
    for (int i = 0; i < unique; i++) {
        for (int j = 0; j < unique; j++) {
            for (int k = 0; k < size; k++)
                if (ary2[i][j] == ary[k])
                    ary2[i][j+1] = ary2[i][j+1] + 1;
        }
    }
    return ary2;
}
