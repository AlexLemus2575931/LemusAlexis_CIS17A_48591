/* 
  * File: Midterm Prob 4
  * Author: Alexis Lemus
  * Created on 10/22/2021
  * Purpose: Encrypting Data  
  */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
bool errorCheck(int [], const int);
bool errorCheck2(int [], const int);
void encryption(int [], const int);


//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
        
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
    
    //Exit stage right!
    return 0;
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