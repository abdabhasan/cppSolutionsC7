#include <iostream>

using namespace std;

/*
    Write a program to print Fibonacci series of 10.
*/

void printFibonacciUsingLoop(short number){

    int febNumber = 0;
    int prev1 = 1, prev2 = 0;
    cout << "1   ";
    for(short i = 2; i <= number; i++){
        febNumber = prev1 + prev2;
        cout << febNumber << "   ";
        prev2 = prev1;
        prev1 = febNumber;
    }
}



int main(){
    

    printFibonacciUsingLoop(10);    

    return 0;
}