/* 
 * File:   main.cpp
 * Author: Alexis Lemus
 * Created on October 3rd, 2021, 7:45 PM
 */

//Libraries
#include <iostream>
using namespace std;

// No Global Constants 

// Function Prototypes
int *getData(int &);            // Fill the array
int *sumAry (const int *, int); // Return the array with successive sums
void prntDat(int *, const int *, int); // Print the array

int main(){
    // Declare Variables
    int arySize;
    const int *array;   // Original array
    int *sums;          // Summed array.
    
    // Get data
    array=getData(arySize);
    
    // Creating a parallel array of sums.
    sums=sumAry(array, arySize);
    
    // Print the arrays.
    prntDat(sums, array, arySize);
    
    delete []array;
    delete []sums;
    return 0;
}

int *getData(int &arySize) {
    cin >> arySize;
    // Dynamic Memory Allocation
    int *ary = new int[arySize];
    for (int i = 0; i < arySize; i++)
        cin >> ary[i];
        
    return ary;
}

int *sumAry (const int *ary, int size) {
    int *sums = new int [size];
    
    sums[0] = ary[0];
    
    for (int i = 1; i < size; i++)
        sums[i] = sums[i-1]+ary[i];
    
    return sums;
}

void prntDat(int *sums, const int *ary, int size) {
    for (int i = 0; i < size; i++) {
        if (i < (size - 1))
            cout << ary[i] << " ";
        else
            cout << ary[i];
    }
    cout << endl;
    
    for (int i = 0; i < size; i++) {
        if (i < (size - 1))
            cout << sums[i] << " ";
        else
            cout << sums[i];
    }
        
}