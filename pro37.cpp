#include <iostream>
#include <vector>

using namespace std;

/*
    Write a program to read a string then
    make a func to split each word in vector;
*/

string readString(){

    string s1;
    
    cout << "Please Enter Your String?\n";
    getline(cin, s1);
    return s1;
}

vector <string> splitStringWords(string s1, string delim){

    short pos = 0;
    string sWord; 
    vector <string> vWords;

    // use find() func to get the position of the delimiters.
    while((pos = s1.find(delim)) != std::string::npos){
        
        sWord = s1.substr(0, pos); // store the word.
        if(sWord != "")
            vWords.push_back(sWord);
            

        s1.erase(0, pos + delim.length()); // erase() until postion and move to next word.
    }

    if(s1 != "")
        vWords.push_back(s1); // add the last word in the string;

    return vWords;
}

int main(){
    
    string s1 = readString();
    vector <string> vWords;

    vWords = splitStringWords(s1, " ");
    cout << "\nTokens : " << vWords.size() << endl;
    for (string& word : vWords) {
        cout << word << endl;
    }

    return 0;
}