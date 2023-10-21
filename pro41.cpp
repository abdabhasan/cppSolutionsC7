#include <iostream>
#include <vector>

using namespace std;

/*
    Write a program to read a string
    and reverse its words;
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

string reverseWordsInString(string s1){

    vector<string> vString;
    string s2 = "";

    vString = splitStringWords(s1, " ");

    // declare iterator
    vector<string>::iterator iter = vString.end();

    while(iter != vString.begin()){

        --iter;

        s2 += *iter + " ";
    }

    s2 = s2.substr(0, s2.length() - 1); // remove the last space.

    return s2;
}

int main(){
    
    string s1 = readString();
    cout << "\n\nString after reversing words:\n";
    cout << reverseWordsInString(s1);

    return 0;
}