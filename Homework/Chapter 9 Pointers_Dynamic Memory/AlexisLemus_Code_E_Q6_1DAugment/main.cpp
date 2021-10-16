/* 
 * File:   main.cpp
 * Author: Alexis Lemus
 * Created on October 3rd, 2021, 7:45 PM
 */

//Libraries
#include <iostream>
using namespace std;

// No GLobal Constants

// Function Prototypes
int *getData(int &);            // Read the array
int *augment(const int *, int);  // Augment and copy the original array.
void prntAry(const int *, int *, int); // Print the array.

int main(){
    // Declare variables.
    int arySize;        // Array size
    const int *array;   // Original array
    int *augAry;        // Augmented Array
    
    // Get data
    array=getData(arySize);
    
    // Augment
    augAry=augment(array, arySize);
    
    // Print
    prntAry(array, augAry, arySize);
    
    // Deallocate memory
    delete []array;
    delete []augAry;
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

int *augment(const int *array, int size) {
    // Dynamic memory Allocation
    int *aug = new int[size+1];
    
    // First element = 0;
    aug[0] = 0;
    
    // Copy the original array to the aug array.
    for (int i = 1; i < (size + 1); i++) 
        aug[i]=array[i-1];
        
    return aug;
}

void prntAry(const int *orig, int *aug, int size) {
    // Outputting the original
    for (int i = 0; i < size; i++) {
        if (i < (size - 1))
            cout << orig[i] << " ";
        else
            cout << orig[i];
    }
    cout << endl;
    
        for (int i = 0; i < (size+1); i++) {
        if (i < (size))
            cout << aug[i] << " ";
        else
            cout << aug[i];
    }
}