/* 
 * File: Code-E Chapter 11 Structures Q6
 * Author: Alexis Lemus
 * Created on 10/6/2021
 * Purpose: Store and display movie data.
*/

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
struct MovieData {
    string title;       // Movie title
    string direct;      // Movie director.
    int year;           // Year Released
    int rTime;          // Running time.
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
MovieData *GetData(int &);          // Get number of movies.
void Display(MovieData [], int);   // Display the movies.


//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    MovieData *movies;
    int size;       // Hold amount of movies.
                               
    //Process or map Inputs to Outputs
    movies=GetData(size);
    Display(movies, size);


    delete []movies;
    //Exit stage right!
    return 0;
}

MovieData *GetData(int &size) {
    cout << "This program reviews structures" << endl;
    cout << "Input how many movies, the Title of the Movie, Director, Year Released, ";
    cout << "and the Running Time in (minutes)." << endl << endl;
    cin >> size;
    
    // Dynamic memory allocation
    MovieData *movies = new MovieData[size];
    
    for (int i = 0; i < size; i++) {
        cin.ignore();
        getline(cin, movies[i].title);
        getline(cin, movies[i].direct);
        cin >> movies[i].year >> movies[i].rTime;
    }
    return movies;
}

void Display(MovieData movies[], int size) {
    cout << left;
    for (int i = 0; i < size; i++) {
        if (i < size-1) {
            cout << setw(11) << "Title:" << movies[i].title << endl;
            cout << setw(11) << "Director:" << movies[i].direct << endl;
            cout << setw(11) << "Year:" << movies[i].year << endl;
            cout << setw(11) << "Length:" << movies[i].rTime << endl << endl;
        }
        else {
            cout << setw(11) << "Title:" << movies[i].title << endl;
            cout << setw(11) << "Director:" << movies[i].direct << endl;
            cout << setw(11) << "Year:" << movies[i].year << endl;
            cout << setw(11) << "Length:" << movies[i].rTime << endl;
        }
    }
}