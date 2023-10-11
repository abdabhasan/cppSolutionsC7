#include <iostream>
#include <iomanip>

using namespace std;

/*
    Write a program to fill a 3x3 matrix with random numbers,
    then sum each col in separate array and print the results.
*/

int randomNumber(int from, int to){

    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

void fillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols){

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = randomNumber(1, 100);
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

int matrixColSum(int arr[3][3], short rows, short colsNumber){
    
    int sum = 0;

    for (short j = 0; j < rows ; j++){
        sum += arr[j][colsNumber];
    }
    return sum;
}

void fillRowsSumsInArray(int arr1[3][3], int arr2[3], short rows, int cols){

    for(int i = 0; i < rows; i++){
        arr2[i] = matrixColSum(arr1, rows, i);
    }
}

void printEachMatrixRowSum(int arr[3], short rows){

    cout << "The following are the sum of each col in the matrix:\n";

    for(int i = 0; i < rows; i++){
    cout << "Col " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

int main(){

    srand((unsigned)time(NULL));

    int arr1[3][3], arr2[3];

    fillMatrixWithRandomNumbers(arr1, 3, 3);
    
    cout << "\n The following is a 3x3 random matrix:\n";
    printMatrix(arr1, 3, 3);

    fillRowsSumsInArray(arr1, arr2, 3, 3);

    printEachMatrixRowSum(arr2, 3);

    return 0;
}