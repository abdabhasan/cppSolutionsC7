#include <iostream>
#include <iomanip>

using namespace std;

/*
    Write a program to count given number in matrix.
*/

int randomNumber(int from, int to){

    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

int readPositiveNumber(string message){
    
    int number = 0;
    
    do{
    
        cout << message << endl;
        cin >> number;
    
    }while(number < 1 || number > 10 );

    return number;
}

void fillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols){

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = randomNumber(1, 10);
        }
    }
}

int countGivenNumberInMatrix(int arr[3][3], short rows, short cols, short number){

    short counter = 0;
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(arr[i][j] == number)
                counter++;
        }
    }
    return counter;
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

    int arr1[3][3], number;

    cout << "\nMatrix1:\n";
    
    fillMatrixWithRandomNumbers(arr1, 3, 3);
    printMatrix(arr1, 3, 3);

    number =  readPositiveNumber("Enter the number to count in matrix ?");

    cout << "Number " << number << " count in matrix is " <<
        countGivenNumberInMatrix(arr1, 3, 3, number) << endl;

    return 0;
}