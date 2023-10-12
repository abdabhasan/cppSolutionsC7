#include <iostream>
#include <iomanip>

using namespace std;

/*
    Write a program to fill a 3x3 matrix with random numbers,
    and print it, then print the middle row and middle col.
*/

int randomNumber(int from, int to){

    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

void fillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols){

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = randomNumber(1, 10);
        }
    }
}

void printMatrixMiddleRow(int arr[3][3], short rows, short cols){
    
    short midRow = rows / 2;

    for(int i = 0; i < cols; i++){
            printf("%0*d   ", 2, arr[midRow][i]);
    }
    cout << endl;
}

void printMatrixMiddleCol(int arr[3][3], short rows, short cols){
    
    short midCol = cols / 2;

    for(int i = 0; i < rows; i++){
            printf("%0*d   ", 2, arr[i][midCol]);
    }
    cout << endl;
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

    srand((unsigned)time(NULL));

    int arr1[3][3], arr2[3][3], arrMultiplyed[3][3];

    cout << "\nMatrix1:\n";
    
    fillMatrixWithRandomNumbers(arr1, 3, 3);
    printMatrix(arr1, 3, 3);
    
    cout << "\nMiddle ROW of matrix1 is:\n";
    printMatrixMiddleRow(arr1, 3, 3);
    cout << "\nMiddle Col of matrix1 is:\n";
    printMatrixMiddleCol(arr1, 3, 3);

    return 0;
}