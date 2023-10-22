#include <iostream>
#include <vector>

using namespace std;

/*
    Write a program to replace a words in string using custom func
*/

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

string lowerAllString(string s1){

    for(short i = 0; i < s1.length(); i++){

            s1[i] = tolower(s1[i]);
    }
    return s1;
}

string joinString(vector <string> vString, string delimeter){

    string s1 = ""; 

    for (string& word : vString) {
        s1 = s1 + word + delimeter;
    }
    return s1.substr(0, s1.length() - delimeter.length());
}

string replaceWordInString(string s1, string stringToReplace, string stringReplaceTo, bool matchCase = true){

    vector<string> vString = splitStringWords(s1, " ");
    
    for(string& s : vString){

        if(matchCase){
            if(s == stringToReplace)
                s = stringReplaceTo;
        }else {
            if(lowerAllString(s) == lowerAllString(stringToReplace))
                s = stringReplaceTo;
        }
    }

    return joinString(vString, " ");
}

int main(){
    
    string s1 = "Welcome to Morrocco , Morrocco is a nice country";
    string stringToReplace = "morrocco";
    string replaceTo = "Jordan";

    cout << "Original string:\n" << s1;
    
    cout << "\nReplace with match case:\n";
    cout << replaceWordInString(s1, stringToReplace, replaceTo);
    
    cout << "\nReplace with NO match case:\n";
    cout << replaceWordInString(s1, stringToReplace, replaceTo, false);

    return 0;
}