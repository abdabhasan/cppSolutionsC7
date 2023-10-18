#include <iostream>

using namespace std;

/*
    Write a program to read a string then
    print each word in that string;
*/

string readString(){

    string s1;
    
    cout << "Please Enter Your String?\n";
    getline(cin, s1);
    return s1;
}

/* // ! my code
void printEachWordInString(string s1){

    cout << "your string words are : \n\n";

    for(short i = 0; i < s1.length(); i++){

        if(s1[i] != ' '){
            cout << s1[i]; 
        }
        if(s1[i] == ' ')
            cout << endl;
    }
}
*/

void printEachWordInString(string s1){

    string delim = " "; // delimiter.

    cout << "\n your string words are : \n\n";
    short pos = 0;
    string sWord; // define a string variable.

    // use find() func to get the position of the delimiters.
    while((pos = s1.find(delim)) != std::string::npos){
        
        sWord = s1.substr(0, pos); // store the word.
        if(sWord != "")
            cout << sWord << endl;
        
        s1.erase(0, pos + delim.length()); // erase() until postion and move to next word.
    }

    if(s1 != "")
        cout << s1 << endl; // print the last word of the string.
}

int main(){
    
    printEachWordInString(readString()); 

    return 0;
}