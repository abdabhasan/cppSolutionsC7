#include <iostream>

using namespace std;

/*
    Write a program to read a string then
    count all vowels in that string;
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

short countVowelsInString(string s1){

    short counter = 0;

    for(short i = 0; i < s1.length(); i++){

        if(isVowel(s1[i]))
            counter++;
    }
    return counter++;
}


int main(){
    
    string s1 = readString();

    cout << "Number of Vowels is : ";
    cout << countVowelsInString(s1);

    return 0;
}