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
int *sort(const int *, int);    // Sort Smallest to largest
int *reverse(const int *, int); // Sort in reverse order
void prntDat(const int *, const int *, int); // Print the array

int main(){
	// Declare variables and Fill
	int arySize;        // Size of the array.
    const int *ary;     // Integer array.
    int *sorted;        // Sorted Array(smallest to largest).
    int *reversed;      // Sorted array in reverse order.   

    // Call the getData function to retrieve the array.
    ary=getData(arySize);
    
    // Sort the data collected smallest to largest.
    sorted=sort(ary, arySize);
    
    // Sort the data collected largest to smallest.
    reversed=reverse(ary, arySize);
    
    // Print the data.
    prntDat(sorted, reversed, arySize);
    
    delete []ary;
    delete []sorted;
    delete []reversed;
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

int *sort(const int *ary, int size) {
    // Copy const int array into a new dynamic array.
    int *array = new int[size];
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

int *reverse(const int *ary, int size) {
    // Copy const int array into a new dynamic array.
    int *array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = ary[i];
        
    int startScan, minIndex, maxValue;
    for (startScan = 0; startScan < (size - 1); startScan++){
        minIndex = startScan;
        maxValue = array[startScan];
        for(int index = startScan + 1; index < size; index++){
            if (array[index] > maxValue){
                maxValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = maxValue;
    }
    return array;
}

void prntDat(const int *sorted, const int *reversed, int size) {
    for (int i = 0; i < size; i++) {
        if (i < (size - 1))
            cout << sorted[i] << " ";
        else
            cout << sorted[i];
    }
    cout << endl;
    
    for (int i = 0; i < size; i++) {
        if (i < (size - 1))
            cout << reversed[i] << " ";
        else
            cout << reversed[i];
    }
}