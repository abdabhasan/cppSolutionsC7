#include <iostream>
#include <iomanip>

using namespace std;

/*
    Write a program to compare two matrices and check if they are
    typical or Not.
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

bool areTwoMatricesTypical(int arr1[3][3], int arr2[3][3], short rows, short cols){

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(arr1[i][j] != arr2[i][j])
                return false;
        }
    }
    return true;
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
    
    if(areTwoMatricesTypical(arr1, arr2, 3, 3))
        cout << "\nYES: they are Typical\n";
    else
        cout << "\nNO: they are NOT\n";


    return 0;
}