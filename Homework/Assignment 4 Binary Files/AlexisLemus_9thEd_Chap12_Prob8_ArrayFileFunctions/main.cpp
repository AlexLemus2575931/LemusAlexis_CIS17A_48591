/* 
  * File:   
  * Author: Alexis Lemus
  * Created on 10/13/2021
  * Purpose: Write an array to a file and display it.
  */

//System Libraries
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void arrayToFile (string, int [], const int);
void fileToArray (string, int[], const int);
void displayAry (int [], const int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
        
    //Declare Variable Data Types and Constants
    const int SIZE = 5;       // Array size, change if needed.
    int array[SIZE] = {0,1,2,3,4};
    string fileName = "sample.txt";
        
    //Initialize Variables
        
    //Process or map Inputs to Outputs
    arrayToFile(fileName, array, SIZE);         // Copy array to file
    fileToArray(fileName, array, SIZE);        // Copy file to array.
        
    //Display Outputs
    displayAry(array, SIZE);                   // Display new array.
        
    //Exit stage right!
    return 0;
}

void arrayToFile (string name, int array[], const int size) {
    // Open the file in binary mode.
    fstream file;
    file.open(name.c_str(), ios::out | ios::binary);
    
    // Write the contents of the array to the file.
    cout << "Writing the characters to the file...\n";
    file.write(reinterpret_cast<char *>(array), size);
    
    // Close the file.
    file.close();
}

void fileToArray (string name, int array[], const int size) {
    // Open the file for input in binary mode. 
    fstream file;
    file.open(name.c_str(), ios::in | ios::binary);
    
    // Read the contents of the file into the array.
    cout << "Now reading the data back into memory...\n";
    file.read(reinterpret_cast<char *>(array), size);
    
    // Close the file.
    file.close();
}

void displayAry (int array[], const int size) {
    cout << "Now displaying the array from the file." << endl;
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl << "Done!";
}