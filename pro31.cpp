#include <iostream>

using namespace std;

/*
    Write a program to read a string and character then
    count the character in that string (match case or not);
*/

string readString(){

    string s1;
    
    cout << "Please Enter Your String?\n";
    getline(cin, s1);
    return s1;
}

char readChar(){

    char ch1;
    
    do{
        cout << "Please Enter Your Character?\n";
        cin >> ch1;
    }while(char(ch1) < 65 || char(ch1) > 122);

    return ch1;
}

char invertLetterCase(char ch1){
    
    return isupper(ch1) ? tolower(ch1) : toupper(ch1);   
}

short countCharInStringCaseSensetive(string s1, char ch1){

    short counter = 0;

    for(short i = 0; i < s1.length(); i++){

        if(s1[i] == ch1)
            counter++;
    }
    return counter++;
}

short countCharInStringCaseNotSensetive(string s1, char ch1){

    short counter = 0;

    for(short i = 0; i < s1.length(); i++){

        if(s1[i] == ch1 || s1[i] == invertLetterCase(ch1))
            counter++;
    }
    return counter++;
}

int main(){
    
    string s1 = readString();
    char ch1 = readChar(); 

    cout << "Letter \'" << ch1 << "\' count = ";
    cout << countCharInStringCaseSensetive(s1, ch1) << endl;

    cout << "Letter \'" << ch1 << "\' or " << "\'" << invertLetterCase(ch1) << "\' count = ";
    cout << countCharInStringCaseNotSensetive(s1, ch1);


    return 0;
}