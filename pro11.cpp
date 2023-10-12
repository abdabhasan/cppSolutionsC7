#include <iostream>
#include <iomanip>

using namespace std;

/*
    Write a program to compare two matrices and check if they are
    eaual or Not.

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

bool areTwoMatricesEqual(int arr1[3][3], int arr2[3][3], short rows, short cols){

    return(sumAllMatrixNumbers(arr1, rows, cols) == sumAllMatrixNumbers(arr2, rows, cols));
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

    int arr1[3][3], arr2[3][3];

    cout << "\nMatrix1:\n";
    
    fillMatrixWithRandomNumbers(arr1, 3, 3);
    printMatrix(arr1, 3, 3);

    cout << "\nMatrix2:\n";
    
    fillMatrixWithRandomNumbers(arr2, 3, 3);
    printMatrix(arr2, 3, 3);
    
    if(areTwoMatricesEqual(arr1, arr2, 3, 3))
        cout << "\nYES: they are EQUAL\n";
    else
        cout << "\nNO: they are NOT\n";



    return 0;
}