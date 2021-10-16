/* 
  * File:   
  * Author: Alexis Lemus
  * Created on  10/13/2021
  * Purpose: Filter a sentence to correct capitalization.
  */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
        
    //Declare Variable Data Types and Constants
    char ch;            // To hold a character.
    bool char1;         // First character
    string first;       // Name of the first file. 
    string second;      // Name of the second file.

        
    //Initialize Variables
    char1 = true;
        
    //Process or map Inputs to Outputs
    cout << "Enter the name of the input file:" << endl;
    getline(cin, first);
    cout << "Enter the name of the output file:" << endl;
    getline(cin, second);
    
    // Open the files.
    fstream inFile(first.c_str(), ios::in);
    fstream outFile(second.c_str(), ios::out);
    
    // Analyze and edit sentence.
    if (inFile) {
        inFile.get(ch);
        
        while (inFile && ch != '.') {
            if (char1) {
                // Write uppercase char to outFile.
                outFile.put(toupper(ch));
            }
            else {
                // Write lowercase char  to outFile.
                outFile.put(tolower(ch));
            }
            
            // Switch off the char1 after the first iteration.
            char1 = false;
            
            // Read another char from inFile
            inFile.get(ch);
        }
    }
    
    // Close the files.
    inFile.close();
    outFile.close();
    
    //Exit stage right!
    return 0;
}