#include <iostream>

using namespace std;

/*
    Write a program to read a string then
    invert all it's letters case and print it;
*/

string readString(){

    string s1;
    
    cout << "Please Enter Your String?\n";
    getline(cin, s1);
    return s1;
}

char invertLetterCase(char ch1){
    
    return isupper(ch1) ? tolower(ch1) : toupper(ch1);   
}

string invertAllStringLettersCase(string s1){

    for(short i = 0; i < s1.length(); i++){

            s1[i] = invertLetterCase(s1[i]); 
    }
    return s1;
}

int main(){
    
    string s1= readString();

    cout << "string after inverting case" << endl;
    s1 = invertAllStringLettersCase(s1);
    cout << s1;


    return 0;
}