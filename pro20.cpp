#include <iostream>

using namespace std;

/*
    Write a program to checkc if the matrix is palindrome or not.
*/

bool isMatrixPalindrome(int arr[3][3], short rows, short cols){

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols / 2; j++){
            if(arr[i][j] != arr[i][cols - 1 - j])
                return false;
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
    
    int arr1[3][3] = {{1, 2, 1}, {2, 1, 2}, {2, 1, 2}};

    cout << "\nMatrix1:\n";

    printMatrix(arr1, 3, 3);

    if(isMatrixPalindrome(arr1, 3, 3))
        cout << "\nYes: it is Palindrome" << endl;
    else
        cout << "NO: it is NOT Palindrome" << endl;

    return 0;
}