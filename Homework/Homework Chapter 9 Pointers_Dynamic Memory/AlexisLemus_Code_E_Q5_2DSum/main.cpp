/* 
 * File:   main.cpp
 * Author: Alexis Lemus
 * Created on October 3rd, 2021, 7:45 PM
 */

//Libraries
#include <iostream>
using namespace std;

// Necessary global constants

// Function Prototypes
int **getData(int &, int &);            // Fill the array
void prntDat(const int * const *, int, int); // Print the array
void destroy(int **, int, int);         // Deallocate Memory
int sum(const int* const *, int, int);  // Return the sum

int main(){
    // Declare Variables
    int rows;            // 2D array rows
    int cols;            // 2D array columns
    int **array;         // Original array
    
    // Get data
    array=getData(rows, cols);
    
    // Print the array and the sum.
    prntDat(array, rows, cols);
    
    // Deallocate memory;
    destroy(array,rows,cols);
    
    return 0;
}

int **getData(int &rows, int &cols){
    cin >> rows >> cols;
    // Dynamic Memory Allocation
    int **ary = new int*[rows];
    for (int i = 0; i < rows; i++) {
        ary[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            cin >> ary[i][j];
    }
    
    return ary;
}

void prntDat(const int* const *ary, int rows, int cols){
    for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++ ) {
             if (j < (cols - 1))
                cout << ary[i][j] << " ";
            else
                cout << ary[i][j];
         }
        cout << endl;
    }
    
    // Display the grand sum
    cout << sum(ary, rows, cols);
}

int sum(const int* const *ary, int rows, int cols) {
    int grandSum = 0;       // Grand sum of array
    for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++ )
             grandSum += ary[i][j];
    }
    return grandSum;
}

void destroy(int **ary, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        delete [] ary[i];
    delete []ary;
}