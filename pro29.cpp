#include <iostream>

using namespace std;

/*
    Write a program to read a string then
    count small/capital letters in that string;
*/

string readString(){

    string s1;
    
    cout << "Please Enter Your String?\n";
    getline(cin, s1);
    return s1;
}

short countSmallLetters(string s1){

    short counter = 0; 

    for(short i = 0; i < s1.length(); i++){
        if(islower(s1[i]))
            counter++;
    }
    return counter;
}

short countCapitalLetters(string s1){

    short counter = 0; 

    for(short i = 0; i < s1.length(); i++){
        if(isupper(s1[i]))
            counter++;
    }
    return counter;
}

int main(){
    
    string s1= readString();

    cout << "string length = " << s1.length() <<  endl;
    cout << "capital letters count = " << countCapitalLetters(s1) <<  endl;
    cout << "small letters count = " << countSmallLetters(s1) <<  endl;



    return 0;
}