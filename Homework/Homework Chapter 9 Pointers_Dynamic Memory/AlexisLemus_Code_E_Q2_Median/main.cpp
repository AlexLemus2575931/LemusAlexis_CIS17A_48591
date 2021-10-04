/* 
 * File:   main.cpp
 * Author: Alexis Lemus
 * Created on October 3rd, 2021, 7:45 PM
 */

//Libraries
#include <iostream>     //I/O Library
#include <iomanip>  
using namespace std;

//No Global Constants

//Function Prototypes
int *getData(int &);            // Return the array size and the array
void prntDat(int *,int);        // Print the integer array
float *median(int *, int);      // Fill the median Array with the Float array size, the median, and the integer array data
int *selectionSort(int [], int);// Sorting algorithm.
void prntMed(float *);          // Print the median Array.

//Execution begins here
int main() {
    // Declare variables and Fill
    int arySize;        // Size of the array.
    int *ary;           // Integer array.
    float *medAry;      // Median array
    
    // Call the getData function to retrieve the array.
    ary=getData(arySize);
    
    // Print the integer array.
    prntDat(ary, arySize);
    
    // Calculate the median
    medAry=median(ary, arySize);
    
    // Print the median array.
    prntMed(medAry);
    
    delete []ary;
    delete []medAry;
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

void prntDat(int *ary,int arySize) {
    for (int i = 0; i < arySize; i++) {
        cout << ary[i];
        if (i < arySize - 1) 
            cout << " ";
        }
    cout << endl;
}

float *median(int *ary, int size) {
    // Dynamic Memory Allocation
    float *medAry = new float[size + 2];
    
    // New Array Size.
    medAry[0] = size + 2;
    
    // Copy the integer array into the medAry
    for (int i = 2; i < (size+2); i++) {
        medAry[i] = ary[i-2];
    }
    
    // Sort the array to determine the median.
    int *sorted;
    sorted = selectionSort(ary, size);
    
    // Calculate the size of the array.
    float medValue;     // Median value,
    if (size%2)
        medAry[1] = sorted[size/2];
    else {
        medAry[1] = (sorted[(size-1)/2]+(sorted[size/2]))/2.0f;
    }
    
    return medAry;
}

int *selectionSort(int ary[], int size) {
    int *array = new int[size];
    // Copy old array to new.
    for (int i = 0; i < size; i++)
        array[i] = ary[i];
    
    int startScan, minIndex, minValue;
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
    return array;
}

void prntMed(float *medAry) {
    cout << medAry[0] << " ";
    cout << fixed << showpoint << setprecision(2);

    for (int i =1; i < medAry[0]; i++) {
            cout << medAry[i];
        if (i < (medAry[0]-1)) 
            cout << " ";
    }
}