#include <iostream>

using namespace std;

/*
    Write a program to read a string then
    count the words in that string;
*/

string readString(){

    string s1;
    
    cout << "Please Enter Your String?\n";
    getline(cin, s1);
    return s1;
}

short countWordsInString(string s1){

    string delim = " "; // delimiter.
    short counter = 0;
    short pos = 0;
    string sWord; // define a string variable.

    // use find() func to get the position of the delimiters.
    while((pos = s1.find(delim)) != std::string::npos){
        
        sWord = s1.substr(0, pos); // store the word.
        if(sWord != "")
            counter++;

        s1.erase(0, pos + delim.length()); // erase() until postion and move to next word.
    }

    if(s1 != "")
        counter++; // count the last word in the string;

    return counter;
}

int main(){
    
    string s1 = readString();

    cout << "\nyour string words number is : ";
    cout << countWordsInString(s1); 

    return 0;
}