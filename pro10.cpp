#include <iostream>
#include <iomanip>

using namespace std;

/*
    Write a program to fill a 3x3 matrix with random numbers,
    then write a function to sum all numbers in this matrix and print it.
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

int sumAllMatrixNumbers(int arr[3][3], short rows, short cols){
    
    short sum = 0;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            sum += arr[i][j];
        }
    }
    return sum;
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
    
    cout << "\n Sum of Matrix1 is:  " << sumAllMatrixNumbers(arr1, 3, 3);


    return 0;
}