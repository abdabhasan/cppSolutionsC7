#include <iostream>
#include <iomanip>

using namespace std;

/*
    Write a program to fill a 3x3 matrix with random numbers,
    then print each row's sum.
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

int matrixRowSum(int arr[3][3], short rowNumber, short cols){
    
    int sum = 0;

    for (short j = 0; j < cols ; j++){
        sum += arr[rowNumber][j];
    }
    return sum;
}

void printEachMatrixRowSum(int arr[3][3], short rows, short cols){

    cout << "The following are the sum of each row in the matrix:\n";

    for(int i = 0; i < rows; i++){
    cout << "Row " << i + 1 << " Sum = " << matrixRowSum(arr, i, cols) << endl;
    }
}

int main(){

    srand((unsigned)time(NULL));

    int arr[3][3];

    fillMatrixWithRandomNumbers(arr, 3, 3);
    
    cout << "\n The following is a 3x3 random matrix:\n";
    printMatrix(arr, 3, 3);

    printEachMatrixRowSum(arr, 3, 3);

    return 0;
}