/* 
  * File: Ch 12 # 9
  * Author: Alexis Lemus
  * Created on 10/16/2021
  * Purpose: Encrypt data from a file.
  */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void readFile (fstream &, fstream &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
        
    //Declare Variable Data Types and Constants
    string input;       // Name of input file
    string output;      // Name of output file
        
    //Process or map Inputs to Outputs
    cout << "This program encrypts text files into a secret code." << endl;
    cout << "Enter the name of the text file you want to encrypt." << endl;
    cout << "NOTE: Enter \"sample.txt\" if you want to test the program.\n";
    cin >> input;
    
    // Open the input file.
    fstream inFile(input.c_str(), ios::in);

    // Input validation
    while(inFile.fail()) {
        cout << "File not found. Please try again." << endl;
        cin >> input;
        fstream inFile(input.c_str(), ios::in);
    }
    
    cout << "Enter the name of the output file." << endl;
    cin >> output;
        
    // Open the output file.
    fstream outFile(output.c_str(), ios::out);
    
    // Call the read function
    readFile(inFile, outFile);
 
    // Close the files
    inFile.close();
    outFile.close();
    
    // Farewell.
    cout << "Done!" << endl;
    
    //Exit stage right!
    return 0;
}

void readFile(fstream &inFile, fstream &outFile) {
    char ch;            // To hold a character
    int enc = 10;       // Encryptor 
        
    cout << "Encrypting file..." << endl;
    if (inFile) {
        // Get a character from the file.
        inFile.get(ch);
                
        // While the last read operation was
        // successful, continue.
        while (inFile) {                  
            // Display the last character read.
            ch = ch + static_cast<char>(enc);     // Adding 10 ASCII value.
            outFile << ch;
                        
            // Read the next character
            inFile.get(ch);
        }
    }
}