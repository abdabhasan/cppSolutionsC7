#include <iostream>
#include <vector>

using namespace std;

/*
    Write a program to remove all punctuations from string;
*/

string removePunctuationsFromString(string s1){

    string s2 = "";

    for(short i = 0; i < s1.length(); i++){
        
        if(!ispunct(s1[i]))
            s2 += s1[i];
    }
    return s2;
}


int main(){
    
    string s1 = "Hey, this is a testing string; that's it (:";

    cout << "The original string :\n" << s1;
    cout << "\n\nAfter removing punct:\n";
    cout << removePunctuationsFromString(s1);

    return 0;
}