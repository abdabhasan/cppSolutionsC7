#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/*
    Write a program to ask you to enter clients and save them to file;
*/

const string clientsFileName = "clients.md";

struct sClient{

    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double balance;
};

sClient readNewClient(){

    sClient client;
    
    cout << "Enter Account Number? ";
    getline(cin >> ws, client.accountNumber)  ;

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

string convertRecordToLine(sClient client, string seperator = "#//#"){

    string stClientRecord = "";

    stClientRecord += client.accountNumber + seperator;
    stClientRecord += client.pinCode + seperator;
    stClientRecord += client.name + seperator;
    stClientRecord += client.phone + seperator;
    stClientRecord += to_string(client.balance);

    return stClientRecord;
}

void addDataLineToFile(string fileName, string stDataLine){

    fstream myFile;
    myFile.open(fileName, ios::out | ios::app);

    if(myFile.is_open()){

        myFile << stDataLine << endl;
        myFile.close();
    }
}

void addNewClient(){

    sClient client;
    client = readNewClient();
    addDataLineToFile(clientsFileName, convertRecordToLine(client));
}

void addClients(){

    char addMore = 'Y';

    do{

        system("clear");
        cout << "Adding new client:\n\n";

        addNewClient();
        cout << "\nClient added successfully, do you wanna add more clients?";
        cin >> addMore;
    }while(toupper(addMore) == 'Y');

}

int main(){

    addClients();

    return 0;
}