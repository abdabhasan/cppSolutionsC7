#include <iostream>
#include <iomanip>

using namespace std;

/*
    Write a program to fill a 3x3 matrix with random numbers.
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


int main(){

    srand((unsigned)time(NULL));

    int arr[3][3];

    fillMatrixWithRandomNumbers(arr, 3, 3);
    
    cout << "\n The following is a 3x3 random matrix:\n";
    printMatrix(arr, 3, 3);


    return 0;
}