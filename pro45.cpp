#include <iostream>
#include <vector>

using namespace std;

/*
    Write a program to read bank client data record and convert it to one line;
*/

struct sClient{

    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double balance;
};

string joinString(vector <string> vString, string delimeter){

    string s1 = ""; 

    for (string& word : vString) {
        s1 = s1 + word + delimeter;
    }
    return s1.substr(0, s1.length() - delimeter.length());
}

sClient readNewClient(){

    sClient client;
    
    cout << "Enter Account Number? ";
    getline(cin, client.accountNumber)  ;

    cout << "Enter PIN code? ";
    getline(cin, client.pinCode)  ;
    
    cout << "Enter Name? ";
    getline(cin, client.name)  ;
    
    cout << "Enter Phone Number? ";
    getline(cin, client.phone)  ;
    
    cout << "Enter Account Balance? ";
    cin >> client.balance;

    return client;
}

string convertRecordToLine(sClient client, string seperator = "#//#"){

    string stClientRecord = "";

    stClientRecord += client.accountNumber + seperator;
    stClientRecord += client.pinCode + seperator;
    stClientRecord += client.name + seperator;
    stClientRecord += client.phone + seperator;
    stClientRecord += to_string(client.balance);

    return stClientRecord;
}

int main(){
    
    cout << "Please Enter Client Data:\n\n";

    sClient client;
    client = readNewClient();

    cout << "\n\nClient Record for saving is:\n";
    cout << convertRecordToLine(client);


    return 0;
}