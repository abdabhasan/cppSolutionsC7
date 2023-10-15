#include <iostream>
#include <iomanip>

using namespace std;

/*
    Write a program to check if the matrix is Sparce or NOT.
*/

int countGivenNumberInMatrix(int arr[3][3], short rows, short cols, short number){

    short counter = 0;
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(arr[i][j] == number)
                counter++;
        }
    }
    return counter;
}

bool isSparceMatrix(int arr[3][3], short rows, short cols){

    short matrixSize = cols * rows;
    
    return (countGivenNumberInMatrix(arr, rows, cols, 0) >= (matrixSize / 2));
}

void printMatrix(int arr[3][3], short rows, short cols){

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%0*d   ", 2, arr[i][j]);
        }
        cout << endl;
    }

}


int main(){

    int arr1[3][3] = {{0, 0, 1}, {12, 0, 0}, {5, 0, 0}}, number;

    cout << "\nMatrix1:\n";
    
    printMatrix(arr1, 3, 3);

    if(isSparceMatrix(arr1, 3, 3))
        cout << "\nYES: it is Sparce\n";
    else
        cout << "\nNO: it is NOT Sparce\n";
    
    
    
    
    return 0;
}