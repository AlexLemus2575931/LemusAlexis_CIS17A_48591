/* 
  * File:   
  * Author: Alexis Lemus
  * Created on 10/11/2021
  * Purpose:  
  */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
struct Speaker {
    string name;    // Speaker Name
    string phone;   // Phone number
    string topic;   // Speaking Topic
    string fee;      // Fee Required.
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void LaunchMenu(string &);
void MenuLoop(Speaker [], string &, int, const int);
void NewEntry(Speaker [], int &, const int);
void EditEntry(Speaker [], int);
void Display(Speaker [], int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
        
    //Declare Variable Data Types and Constants
    const int MAX = 10;
    int counter = 0;        // To keep track of array.
    Speaker data[MAX];
    string input;       // User input.
        
    //Initialize Variables
        
    //Process or map Inputs to Outputs
    cout << "****************************************" << endl;
    cout << "********* Speakers' Bureau *************" << endl;
    cout << "************** Database ****************" << endl;
    cout << "****************************************" << endl << endl;
    
    // Menu launch.
    LaunchMenu(input);
    while(input != "QUIT" || input != "Quit") {
        MenuLoop(data, input, counter, MAX);
    }   
    
    //Exit stage right!
    return 0;
}

void LaunchMenu(string &input) {
    cout << "What action would you like to do?" << endl;
    cout << "\t1. Enter New Data (Enter \"NEW\")" << endl;
    cout << "\t2. Edit Data (Press \"EDIT\")" << endl;
    cout << "\t3. Display All Data (Press \"DISPLAY\")" << endl;
    cout << "\t4. Quit (Press \"QUIT\")" << endl;
    cin >> input;
    cin.ignore();
}

void NewEntry(Speaker data[], int &counter, const int size) {
    string input;
    for (int i = counter; i < size; i++) {
        cout << "Enter the speaker's name" << endl;
        getline(cin, data[i].name);
        cout << "Enter the speaker's telephone number" << endl;
        getline(cin, data[i].phone);
        cout << "Enter the speaker's speaking topic" << endl;
        getline(cin, data[i].topic);
        cout << "Enter the speaker's fee required" << endl;
        cin >> data[i].fee;
        
        counter++;
        cout << "Would you like to continue adding speakers?" << endl;
        cout << "Enter (Y/N)" << endl;
        cin >> input;
    cin.ignore();
        
        if (input == "N" || input == "n") {
            break;
        }
    }
}

void EditEntry(Speaker data[], int counter) {
    int input;
    string input2;
    cout << "Which speaker would you like to edit?(Enter an input 1-10)"<< endl;
    cin >> input;
    cout << "What would you like to edit about speaker #" << input << "?\n";
    cout << "Name (Enter \"NAME\")" << endl;
    cout << "Telephone Number (Enter \"PHONE\")" << endl;
    cout << "Speaking Topic (Enter \"TOPIC\")" << endl;
    cout << "Fee Required (Enter \"FEE\")" << endl;
    cin >> input2;
    
    if (input2 == "NAME")
        data[input].name;
    else if (input2 == "PHONE")
        data[input].phone;
    else if (input2 == "TOPIC")
        data[input].topic;
    else if (input2 == "FEE")
        data[input].fee;
    else {
        cout << "Did not recognize input. Please try again:" << endl;
        EditEntry(data, counter);
    }
}

void Display(Speaker data[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << "Speaker Name: " << data[i].name << endl;
        cout << "Telephone Number: " << data[i].phone << endl;
        cout << "Speaking Topic: " << data[i].topic << endl;
        cout << "Fee Required: " << data[i].fee << endl << endl;
    }
}

void MenuLoop(Speaker data[], string &input, int counter, const int MAX) {
    if (input == "NEW")
        NewEntry(data, counter, MAX);
    else if (input == "EDIT")
        EditEntry(data, counter);
    else if (input == "DISPLAY")
        Display(data, counter);
    else if (input == "QUIT");
        // Do nothing
    else{
        cout << "Did not recognize input. Please try again:" << endl;
        LaunchMenu(input);
    } 
}