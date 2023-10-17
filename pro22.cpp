#include <iostream>

using namespace std;

/*
    Write a program to print Fibonacci series of 10.
*/

void printFibonacciUsingRecurssion(short number, int prev1, int prev2){

    int febNumber = 0;
    if(number > 0){
        febNumber = prev1 + prev2;
        prev2 = prev1;
        prev1 = febNumber;
        cout << febNumber << "   ";
        printFibonacciUsingRecurssion(number - 1, prev1, prev2);
    }
}



int main(){
    

    printFibonacciUsingRecurssion(10, 0, 1);    

    return 0;
}