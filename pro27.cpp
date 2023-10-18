#include <iostream>

using namespace std;

/*
    Write a program to read a character then
    invert it is case and print it;
*/

char readChar(){

    char ch1;
    
    do{
        cout << "Please Enter Your Character?\n";
        cin >> ch1;
    }while(char(ch1) < 65 || char(ch1) > 122);

    return ch1;
}

char invertLetterCase(char ch1){
    
    return isupper(ch1) ? tolower(ch1) : toupper(ch1);   
}

int main(){
    
    char ch1= readChar();

    cout << "Character after inverting case" << endl;

    ch1 = invertLetterCase(ch1);
    cout << ch1;


    return 0;
}