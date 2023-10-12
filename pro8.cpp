#include <iostream>
#include <iomanip>

using namespace std;

/*
    Write a program to fill two 3x3 matrix with random numbers,
    and print them, then multiply them into a 3rd matrix and print it.
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

void multiplyTwoMatrixes(int arr1[3][3], int arr2[3][3], int ArrMultiplyed[3][3], short rows, short cols){
    
    for(int i = 0; i < rows; i++){

        for(int j = 0; j < cols; j++){
            ArrMultiplyed[i][j] = arr1[i][j] * arr2[i][j];
        }
    }

}

void printMatrix(int arr[3][3], short rows, short cols){

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << setw(3) << arr[i][j] << "\t";
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
   
    cout << "\nMatrix2:\n";
    
    fillMatrixWithRandomNumbers(arr2, 3, 3);
    printMatrix(arr2, 3, 3);
   
    cout << "\nResult:\n";
    
    multiplyTwoMatrixes(arr1, arr2, arrMultiplyed, 3, 3);
    printMatrix(arrMultiplyed, 3, 3);
    
    return 0;
}