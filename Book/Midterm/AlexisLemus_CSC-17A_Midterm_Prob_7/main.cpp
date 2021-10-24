/* 
  * File: Midterm Prob # 7
  * Author: Alexis Lemus
  * Created on 10/22/2021
  * Purpose: Factoring input integer into its prime numbers.
  */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries
struct Prime {
    unsigned short prime;
    unsigned char power;
};

struct Primes {
    unsigned char nPrimes;
    Prime *prime;
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
Primes *factor(int);    // Input an integer and return all prime factors.
void prntPrm(Primes *);   // Output all prime factors.
int getPrimes(int);            // Returns number of primes.
int *fillAry(int, int);        // Returns array of primes.
int **fctrAry(int *, int, int);// Fills 2d array of factors and powers.

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
        
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
    
    //Exit stage right!
    return 0;
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
