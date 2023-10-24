#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*
    Write a program to delete client by account Number;
*/

const string clientsFileName = "clients.md";

struct sClient{

    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double balance;
    bool markForDelete = false;
};

string readClientAccountNumber(){

    string s1;
    
    cout << "Please Enter the Account Number?\n";
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

string convertRecordToLine(sClient client, string seperator = "#//#"){

    string stClientRecord = "";

    stClientRecord += client.accountNumber + seperator;
    stClientRecord += client.pinCode + seperator;
    stClientRecord += client.name + seperator;
    stClientRecord += client.phone + seperator;
    stClientRecord += to_string(client.balance);

    return stClientRecord;
}

void printClientRecord(sClient client){

    cout << "The following are the client details:\n";

    cout << "Account Number: " << client.accountNumber << endl;
    cout << "PIN code      : " << client.pinCode << endl;
    cout << "Name          : " << client.name << endl;
    cout << "Phone         : " << client.phone << endl;
    cout << "Balance       : " << client.balance << endl;
}

bool markClientForDeleteByAccountNumber(string accountNumber, vector<sClient>& vClients){

    for(sClient& c : vClients){
        
        if(c.accountNumber == accountNumber){

            c.markForDelete = true;
            return true;
        }
    }
    return false;
}

vector<sClient> saveClientsDataToFile(string fileName, vector<sClient> vClients){

    fstream myFile;
    myFile.open(fileName, ios::out); // overwrite

    string dataLine;

    if(myFile.is_open()){

        for(sClient c: vClients){

            if(c.markForDelete == false){

                dataLine = convertRecordToLine(c);
                myFile << dataLine << endl;
            }
        }
        myFile.close();
    }
}

bool findClientByAccountNumber(string accountNumber, vector<sClient> vClients, sClient& client){

    for(sClient& c : vClients){

        if(c.accountNumber == accountNumber){

            client = c;
            return true;
        }
    }
    return false;
}

bool deleteClientByAccountNumber(string accountNumber, vector<sClient>& vClients){

    sClient client;
    char answer = 'n';

    if(findClientByAccountNumber(accountNumber, vClients, client)){

        printClientRecord(client);
        
        cout << "Are you sure you wanna delete this client? y/N ? ";
        cin >> answer;

        if(toupper(answer) == 'Y'){
        
            markClientForDeleteByAccountNumber(accountNumber, vClients);
            saveClientsDataToFile(clientsFileName, vClients);

            // refresh clients
            vClients = loadClientsDataFromFile(clientsFileName);

            cout << "\n\nClient Deleted Successfully.";
            return true;
        }
        
    }
    else{

        cout << "\nClient with Account Nubmer (" << accountNumber << ") NOT found";
        return false;
    }
}

int main(){

    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);
    string accountNumber = readClientAccountNumber();

    deleteClientByAccountNumber(accountNumber, vClients);


    return 0;
}