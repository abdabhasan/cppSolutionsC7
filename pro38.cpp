#include <iostream>
#include <vector>

using namespace std;

/*
    Write a program to read a string then
    Trim left, right, all;
*/

string trimLeft(string s1){

    for(short i = 0; i < s1.length(); i++){
        
        if(s1[i] != '=')
            return s1.substr(i, s1.length() - i);
    }
    return "";
}

string trimRight(string s1){
    
    for(short i = s1.length() - 1; i >= 0; i--){
        
        if(s1[i] != '=')
            return s1.substr(0, i + 1);
    }
    return "";
}

string trimm(string s1){

    return (trimLeft(trimRight(s1)));
}

int main(){
    
    string s1 = "=========This is a testing string=========";

    cout << "\nThe string    = " << s1;
    cout << "\nTrim Left     = " << trimLeft(s1);
    cout << "\nTrim Right    = " << trimRight(s1);
    cout << "\nTrim          = " << trimm(s1); 


    cout << endl;
    return 0;
}