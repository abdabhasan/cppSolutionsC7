#include <iostream>

using namespace std;

/*
    Write a program to print the Min and Max number in matrix'.
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

int minNumberInMatrix(int arr[3][3], short rows, short cols){

    short minNumber = arr[0][0];

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(arr[i][j] < minNumber)
                minNumber = arr[i][j];
        }
    }
    return minNumber;
}

int maxNumberInMatrix(int arr[3][3], short rows, short cols){

    short maxNumber = arr[0][0];

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(arr[i][j] > maxNumber)
                maxNumber = arr[i][j];
        }
    }
    return maxNumber;
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

    int arr1[3][3];

    cout << "\nMatrix1:\n";

    fillMatrixWithRandomNumbers(arr1, 3, 3);
    printMatrix(arr1, 3, 3);

    cout << "Minimum number is : ";
    cout << minNumberInMatrix(arr1, 3, 3) << endl;

    cout << "Max number is : ";
    cout << maxNumberInMatrix(arr1, 3, 3) << endl;


    return 0;
}