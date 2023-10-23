#include <iostream>
#include <vector>

using namespace std;

/*
    Write a program to convert line data to record and print it;
*/

struct sClient{

    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double balance;
};

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

sClient convertLineToRecord(string line, string seperator = "#//#"){

    sClient client;
    vector<string> vClientData;

    vClientData = splitStringWords(line, seperator);
    client.accountNumber = vClientData[0];
    client.pinCode = vClientData[1];
    client.name = vClientData[2];
    client.phone = vClientData[3];
    client.balance = stod(vClientData[4]); // cast string to double;

    return client;
}

void printClientRecord(sClient client){

    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccount Number : " << client.accountNumber;
    cout << "\nPIN code       : " << client.pinCode;
    cout << "\nName           : " << client.name;
    cout << "\nPhone          : " << client.phone;
    cout << "\nAccount Balance: " << client.balance;
}

int main(){
    
    string stLine = "1256#//#1235#//#testing name#//#123456789#//#2000.000000";
    cout << "\nLine Record is :";
    cout << stLine;


    sClient client = convertLineToRecord(stLine);

    printClientRecord(client);

    return 0;
}