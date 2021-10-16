/* 
  * File: Chapter 12 Problem #2
  * Author: Alexis Lemus
  * Created on 10/16/2021
  * Purpose: Display a txt file to the user.
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
void displayBook (fstream &, const int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
        
    //Declare Variable Data Types and Constants
    string input;           // INPUT - Input from the user.
    const int LIMIT = 24;   // CALC - To keep track of my many lines to show
    
        
    //Initialize Variables
        
    // Program outputs
    cout << "Welcome to the political theory literature program." << endl;
    do {
        cout << "Choose your ideology" << endl << endl;
        cout << "\t1. \"The Conquest of Bread\" by Peter Kropotkin ";
        cout << "(Enter \"bread.txt\")" << endl;
        cout << "\t2. \"Atlas Shrugged\" by Ayn Rand (Enter \"atlas.txt\")\n";
        cout << "\t3. \"State and Revolution\" by Vladmir Lenin ";
        cout << "(Enter \"state.txt\")" << endl;
        cout << "\t4. \"Revolt Against the Modern World\" by Julius Evola ";
        cout << "(Enter \"revolt.txt\")" << endl;
        cout << "\t5.  Exit Program(Enter \"QUIT\")" << endl;
        cin >> input;
    
        fstream file(input.c_str(), ios::in);
    
        if (file.fail() && input != "Quit" && input != "QUIT")
            cout << "Entry not recognized. Please try again." << endl;
        
        if (file.good())
            displayBook(file, LIMIT);
            
    } while (input != "Quit" && input != "QUIT");
    
    cout << "End of program" << endl;
    
    //Exit stage right!
    return 0;
}

void displayBook (fstream &file, const int LIMIT) {
    int counter = 0;    // Newline character counter
    char ch;            // To hold a character
    string input;       // User input
    
    if (file) {
        // Get a character from the file.
        file.get(ch);
        
        // While the last read operation was
        // successful, continue.
        while (file) {
            // Newline character counter.
            if (ch == '\n')
                counter++;
            
            // Ask user if they would like to continue.
            if (counter == LIMIT) {
                cout << "\n\nOnly 24 lines can be displayed at a time." << endl;
                cout << "Would you like to continue?" << endl;
                cout << "Enter \"Q\" to exit. Enter anything else";
                cout << " to continue" << endl;
                cin >> input;
                
                if (input == "Q" || input == "q") {
                    file.close();
                    break;
                }
                // Reset the counter
                counter = 0;
            }
            
            // Display the last character read.
            cout << ch;
            
            // Read the next character
            file.get(ch);
        }
    }
}