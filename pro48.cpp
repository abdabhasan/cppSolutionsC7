#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*
    Write a program to read clients file and show them on the screen;
*/

const string clientsFileName = "clients.md";

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

    cout << "| " << setw(15) << left << client.accountNumber;
    cout << "| " << setw(10) << left << client.pinCode;
    cout << "| " << setw(40) << left << client.name;
    cout << "| " << setw(12) << left << client.phone;
    cout << "| " << setw(12) << left << client.balance;

}

void pirntAllClientsData(vector<sClient> vClients){

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s)";
    cout << "\n___________________________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "PIN Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n___________________________________________________________\n" << endl;

    for(sClient client : vClients){

        printClientRecord(client);
        cout << endl;
    }
}

int main(){

    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);
    pirntAllClientsData(vClients);


    return 0;
}