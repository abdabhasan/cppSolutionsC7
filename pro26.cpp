#include <iostream>

using namespace std;

/*
    Write a program to read a string then
    upper all letters, then lower all of them in that string;
*/

string readString(){

    string s1;
    
    cout << "Please Enter Your String?\n";
    getline(cin, s1);
    return s1;
}

string lowerAllString(string s1){

    for(short i = 0; i < s1.length(); i++){

            s1[i] = tolower(s1[i]);
    }
    return s1;
}

string upperAllString(string s1){

    for(short i = 0; i < s1.length(); i++){

            s1[i] = toupper(s1[i]);
    }
    return s1;
}

int main(){
    
    string s1= readString();

    cout << "\nstring after upper:\n";
    s1 = upperAllString(s1);
    cout << s1 << endl;
    
    cout << "\nstring after lower:\n";
    s1 = lowerAllString(s1);
    cout << s1 << endl;
    


    return 0;
}