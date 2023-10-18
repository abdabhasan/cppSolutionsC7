#include <iostream>

using namespace std;

/*
    Write a program to read a string then
    print all vowels in that string;
*/

string readString(){

    string s1;
    
    cout << "Please Enter Your String?\n";
    getline(cin, s1);
    return s1;
}

bool isVowel(char ch1){

    ch1 = tolower(ch1);

    return((ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1 == 'u'));
}

void printVowelsInString(string s1){
    
    cout << "Vowels in the string are : ";

    for(short i = 0; i < s1.length(); i++){

        if(isVowel(s1[i]))
            cout << s1[i] << "   ";
    }
}

int main(){
    
    string s1 = readString();

    printVowelsInString(s1);

    return 0;
}