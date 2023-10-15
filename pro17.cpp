#include <iostream>
#include <iomanip>

using namespace std;

/*
    Write a program to check if the given number exists in matrix or not.
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

int readPositiveNumber(string message){
    
    int number = 0;
    
    do{
    
        cout << message << endl;
        cin >> number;
    
    }while(number < 1 || number > 100 );

    return number;
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

    int arr1[3][3] = {{0, 0, 1}, {12, 0, 0}, {5, 0, 0}}, number;

    cout << "\nMatrix1:\n";

    fillMatrixWithRandomNumbers(arr1, 3, 3);
    printMatrix(arr1, 3, 3);

    number = readPositiveNumber("Please enter the number to look for in matrix?");

    if(isNumberInMatrix(arr1, 3, 3, number))
        cout << "\nYES: it is there\n";
    else
        cout << "\nNO: it is NOT there\n";
    
    
    return 0;
}