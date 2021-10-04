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
void prntDat(const int * const *, const int * const *, int, int); // Print the array
int **augment(const int* const *, int, int);  // Augment the original array
void destroy(int **, int, int);         // Deallocate Memory


int main(){
    // Declare Variables
    int rows;            // 2D array rows
    int cols;            // 2D array columns
    int **array;         // Original array
    int **aug;           // Augmented array.
    
    // Get data
    array=getData(rows, cols);
    
    // Augment the array
    aug=augment(array, rows, cols);
    
    // Print the array and the sum.
    prntDat(array, aug, rows, cols);
    
    // Deallocate memory;
    destroy(array,rows,cols);
    destroy(aug, rows, cols);
    
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

void prntDat(const int* const *ary, const int * const *aug, int rows, int cols){
    for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++ ) {
             if (j < (cols - 1))
                cout << ary[i][j] << " ";
            else
                cout << ary[i][j];
         }
        cout << endl;
    }
    
    for (int i = 0; i < (rows+1); i++) {
         for (int j = 0; j < (cols+1); j++ ) {
             if (j < (cols))
                cout << aug[i][j] << " ";
            else
                cout << aug[i][j];
         }
        if (i < rows)
            cout << endl;
    }
}

int **augment(const int* const *array, int rows, int cols) {
    // Fill the new aug array with zeroes.
    int **aug = new int*[rows+1];
    for (int i = 0; i < (rows+1); i++) {
        aug[i] = new int[cols+1];
        for (int j = 0; j < (cols+1); j++)
            aug[i][j] = 0;
    }
    
    for (int i = 1; i < (rows+1); i++) {
        for (int j = 1; j < (cols+1); j++)
            aug[i][j] = array[i-1][j-1];
    }
    
    return aug;
}

void destroy(int **ary, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        delete [] ary[i];
    delete []ary;
}