#include <iostream>
#include <vector>

using namespace std;

/*
    write a program to join 
    vector of strings into a one string with separators;
*/

string joinVector(vector <string> vString, string delimeter){

    string s1 = ""; 

    for (string& word : vString) {
        s1 = s1 + word + delimeter;
    }
    return s1.substr(0, s1.length() - delimeter.length());
}

int main(){
    
    vector <string> vWords = {"ali", "test", "jaber", "imam"};

    cout << "\nVector after join : " << endl;
    cout << joinVector(vWords, "/");

    
    cout << endl;
    return 0;
}