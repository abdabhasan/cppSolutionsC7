#include <iostream>

using namespace std;

/*
    Write a program to read a character then
    check if it is a vowel or NOT;
*/

char readChar(){

    char ch1;
    
    do{
        cout << "Please Enter Your Character?\n";
        cin >> ch1;
    }while(char(ch1) < 65 || char(ch1) > 122);

    return ch1;
}

bool isVowel(char ch1){

    ch1 = tolower(ch1);

    return((ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1 == 'u'));
}

int main(){
    
    char ch1 = readChar(); 

    if(isVowel(ch1))
        cout << "\nYes it is vowel";
    else
        cout << "\nNo it is NOT vowel";

    return 0;
}