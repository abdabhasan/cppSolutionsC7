#include <iostream>
#include <iomanip>

using namespace std;

/*
    Write a program to check if the matrix is identity or NOT.
*/

bool isIdentityMatrix(int arr1[3][3], short rows, short cols){

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            
            if(i == j && arr1[i][j] != 1){
                    return false;
            }else if(i != j && arr1[i][j] != 0){
                    return false;
            }
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

    int arr1[3][3]= {
        {1, 0 , 0},
        {0, 1 , 0},
        {0, 0 , 1}};

    cout << "\nMatrix1:\n";
    
    // fillMatrixWithRandomNumbers(arr1, 3, 3);
    printMatrix(arr1, 3, 3);

    
    if(isIdentityMatrix(arr1, 3, 3))
        cout << "\nYES: it is Identity\n";
    else
        cout << "\nNO: it is NOT\n";


    return 0;
}