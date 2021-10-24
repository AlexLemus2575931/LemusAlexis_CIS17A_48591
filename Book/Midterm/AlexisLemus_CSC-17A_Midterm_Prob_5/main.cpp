/* 
  * File: Midterm Prob 5
  * Author: Alexis Lemus
  * Created on 10/22/2021
  * Purpose: Find which value of n causes an overflow.
  */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
        
    //Declare Variable Data Types and Constants
    /*
    unsigned char data = 1;     // Data type to test.
    long double sup = 1;        // To test overflow. Largest possible data type
    int n = 100;      // Factorial 
    
    for (int i = 1; i <= n; i++) {
        data *= i;
        sup *= i;
        cout << "i = " << i << "\t" << data << endl;
        if (data != sup) {
            cout << "It overflowed at " << i << endl;
            break;
        }
    }
    */
        
    //Initialize Variables
        
    //Process or map Inputs to Outputs
        
    //Display Outputs
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
            
    
    //Exit stage right!
    return 0;
}

//  char = 6
//  unsigned char = 6
//  short = 7
//  unsigned short = 8
//  int = 7
//  unsigned int = 12
//  long = 12
//  unsigned long = 12
//  long long = 20
//  unsigned long long = 20
//  float = 13