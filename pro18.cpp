#include <iostream>

using namespace std;

/*
    Write a program to print the intersected numbers in two given matrices.
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

bool isNumberInMatrix(int arr[3][3], short rows, short cols, short number){

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(arr[i][j] == number)
                return true;
        }
    }
    return false;
}

void printIntersectedNumbersInTwoArrays(int arr1[3][3], int arr2[3][3], short rows, short cols){

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            
            if(isNumberInMatrix(arr2, 3, 3, arr1[i][j]))
                cout << arr1[i][j] << "  ";
        }
    }


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

    int arr1[3][3], arr2[3][3], number;

    cout << "\nMatrix1:\n";

    fillMatrixWithRandomNumbers(arr1, 3, 3);
    printMatrix(arr1, 3, 3);

    cout << "\nMatrix2:\n";

    fillMatrixWithRandomNumbers(arr2, 3, 3);
    printMatrix(arr2, 3, 3);

    cout << "intersected numbers are:" << endl;

    printIntersectedNumbersInTwoArrays(arr1, arr2, 3, 3);


    return 0;
}