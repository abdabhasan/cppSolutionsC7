#include <iostream>

using namespace std;

/*
    Write a program to read a string then
    lowercase the first letter of each word in that string;
*/

string readString(){

    string s1;
    
    cout << "Please Enter Your String?\n";
    getline(cin, s1);
    return s1;
}

string lowercaseFirstLetterOfEachWord(string s1){

    bool isFirstLetter = true;

    for(short i = 0; i < s1.length(); i++){

        if(s1[i] != ' ' && isFirstLetter){
            s1[i] = tolower(s1[i]);
        }
        isFirstLetter = (s1[i] == ' ' ? true : false);

    }
    return s1;
}



int main(){
    
    string s1= readString();
    cout << "\nstring after conversion:\n";
    
    s1 = lowercaseFirstLetterOfEachWord(s1);
    
    cout << s1 << endl;


    return 0;
}