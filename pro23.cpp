#include <iostream>

using namespace std;

/*
    Write a program to read a string then print the first letter of each word in that string.
*/

string readString(){

    string s1;
    
    cout << "Please Enter Your String?\n";
    getline(cin, s1);
    return s1;
}

void printFirstLetterOfEachWord(string s1){

    bool isFirstLetter = true;

    cout << "\nfirst letters of this string:\n";

    for(short i = 0; i < s1.length(); i++){

        if(s1[i] != ' ' && isFirstLetter){
            cout<< s1[i] << endl;
        }
        isFirstLetter = (s1[i] == ' ' ? true : false);

    }   
}

int main(){
    
    printFirstLetterOfEachWord(readString());

    return 0;
}