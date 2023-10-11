#include <iostream>
#include <iomanip>

using namespace std;

/*
    Write a program to fill a 3x3 matrix with ordered numbers,
    then transpose matrix and print it.
*/

void fillMatrixWithOrderedNumbers(int arr[3][3], short rows, short cols){

    short counter = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            counter++;
            arr[i][j] = counter;
        }
    }
}

void transposeMatrix(int arr[3][3], int arrTransposed[3][3], short rows, short cols){

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
             arrTransposed[i][j] = arr[j][i];
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

    int arr1[3][3], arrTransposed[3][3];

    cout << "\n The following is a 3x3 orderd matrix:\n";
    
    fillMatrixWithOrderedNumbers(arr1 , 3, 3);
    
    printMatrix(arr1, 3, 3);

    cout << "\n The following is a 3x3 transposed matrix:\n";

    transposeMatrix(arr1, arrTransposed, 3, 3);

    printMatrix(arrTransposed, 3, 3);

    return 0;
}