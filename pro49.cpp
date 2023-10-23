#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*
    Write a program to find client by account Number and print it;
*/

const string clientsFileName = "clients.md";

struct sClient{

    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double balance;
};

string readClientAccountNumber(){

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

vector<sClient> loadClientsDataFromFile(string fileName){

    vector<sClient> vClients;

    fstream myFile;
    myFile.open(fileName, ios::in); // read mode

    if(myFile.is_open()){

        string line;
        sClient client;

        while(getline(myFile, line)){

            client = convertLineToRecord(line);
            
            vClients.push_back(client);
        }
        myFile.close(); 
    }
    return vClients;
} 

void printClientRecord(sClient client){

    cout << "The following are the client details:\n";

    cout << "Account Number: " << client.accountNumber << endl;
    cout << "PIN code      : " << client.pinCode << endl;
    cout << "Name          : " << client.name << endl;
    cout << "Phone         : " << client.phone << endl;
    cout << "Balance       : " << client.balance << endl;
}

bool findClientByAccountNumber(string accountNumber, sClient& client){

    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);

    for(sClient& c : vClients){

        if(c.accountNumber == accountNumber){

            client = c;
            return true;
        }
    }
    return false;
}


int main(){

    sClient client;
    string accountNumber = readClientAccountNumber();

    if(findClientByAccountNumber(accountNumber, client))
        printClientCard(client);
    else
        cout << "\nClient with Account Nubmer (" << accountNumber << ") NOT found";


    return 0;
}