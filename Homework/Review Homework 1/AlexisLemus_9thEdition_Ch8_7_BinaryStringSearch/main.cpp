/* 
 * File:   main.cpp
 * Author: Alexis Lemus
 * Created on September 6, 2021, 6:06 AM
 * Purpose: Modify the binarySearch function to search for strings.
 */

// System Libraries
#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
int binarySearch(string names[], const int NUM_NAMES, string search);
void selectionSort(string names[], const int NUM_NAMES);

// Execution begins here.
int main() {
    const int NUM_NAMES = 20;       // Number of names.
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill",
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                               "James, Jean", "Weaver, Jim", "Pore, Bob",
                               "Rutherford, Greg", "Javens, Renee",
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };
    string search;                  // INPUT - Name to search for.
    int position;
    
    // Ask the user to enter a name to search for.
    cout << "Enter a name to search for: ";
    getline(cin, search);
    
    selectionSort (names, NUM_NAMES);
    
    position = binarySearch (names, NUM_NAMES, search);
    
    if (position == -1) cout << "Name not found.";
    else cout << search << " was found.";
    
    return 0;
}


void selectionSort(string array[], const int size) {
    int minIndex;
    string minValue;
    for (int startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minValue = array[startScan];
        for(int index = startScan + 1; index < size; index++) {
            if (array[index] < minValue){
                minValue = array[index];
                minIndex = index;
                }
            }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}

int binarySearch(string array[], const int numElems, string value)
{
    int first = 0,              // First array element
        last = numElems - 1,    // Last array element
        middle,                 // Midpoint of search
        position = -1;          // Position of search value
    bool found = false;         // Flag
    while (!found && first <= last) {
        middle = (first + last) / 2; 
        if (array[middle] == value) {
            found = true;
            position = middle;
        }
        else if (array[middle] > value) last = middle - 1;
        else first = middle + 1; 
    }
    return position;
}
