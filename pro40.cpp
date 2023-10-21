#include <iostream>
#include <vector>

using namespace std;

/*
    write a program to join 
    array of strings into a one string with separators;
*/

string joinString(vector <string> vString, string delimeter){

    string s1 = ""; 

    for (string& word : vString) {
        s1 = s1 + word + delimeter;
    }
    return s1.substr(0, s1.length() - delimeter.length());
}

string joinString(string  arrString[], short length, string delimeter){

    string s1 = ""; 

    for (short i = 0; i < length; i++) {
        s1 = s1 + arrString[i] + delimeter;
    }
    return s1.substr(0, s1.length() - delimeter.length());
}

int main(){
    
    vector <string> vWords = {"ali", "test", "jaber", "imam"};
    string arr[] = {"ali", "test", "jaber", "imam"};

    cout << "\nVector after join : " << endl;
    cout << joinString(vWords, "/");

    cout << "\n\nArray after join : " << endl;
    cout << joinString(arr, 4, "/");
    
    cout << endl;
    return 0;
}