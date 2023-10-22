#include <iostream>
#include <vector>

using namespace std;

/*
    Write a program to replace a word in string
*/

string replaceWordInString(string s1, string stringToReplace, string stringReplaceTo){

    short pos = s1.find(stringToReplace);

    while(pos != std::string::npos){

        s1 = s1.replace(pos, stringToReplace.length(), stringReplaceTo);
        pos = s1.find(stringToReplace); // find the next
    }
    return s1;
}


int main(){
    
    string s1 = "Welcome to India, India is a nice country";
    string stringToReplace = "India";
    string replaceTo = "Jordan";

    cout << "\nOriginal string:\n" << s1;
    cout << "\nString after Replace:\n";
    cout << replaceWordInString(s1, stringToReplace, replaceTo);

    return 0;
}