#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const string clientsFileName = "clients.md";

void showMainMenu();
void showTransactionsMenu();

struct sClient{

    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double balance;
    bool markForDelete = false;
};

enum enMainMenuOptions{
    eListClients = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClient = 4,
    eFindClient = 5,
    eTransactions = 6,
    eExit = 7 
};

enum enTransactionsMenuOptions{
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalance = 3,
    eMainMenu = 4,
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

bool clientExistsByAccountNumber(string accountNumber, string fileName){

    vector<sClient> vClients;
    fstream myFile;
    myFile.open(fileName, ios::in); // read mode

    if(myFile.is_open()){

        string line;
        sClient client;

        while(getline(myFile, line)){
            
            client = convertLineToRecord(line);
            if(client.accountNumber == accountNumber){
                myFile.close();
                return true;
            }
            vClients.push_back(client);
        }
        myFile.close();
    }
    return false;
}

void printClientBalanceRecord(sClient client){

    cout << "| " << setw(15) << left << client.accountNumber;
    cout << "| " << setw(40) << left << client.name;
    cout << "| " << setw(12) << left << client.balance;
}

void printClientRecord(sClient client){

    cout << "| " << setw(15) << left << client.accountNumber;
    cout << "| " << setw(10) << left << client.pinCode;
    cout << "| " << setw(40) << left << client.name;
    cout << "| " << setw(12) << left << client.phone;
    cout << "| " << setw(12) << left << client.balance;

}

void printClientCard(sClient client){

    cout << "The following are the client details:\n";

    cout << "------------------------------------" << endl;
    cout << "Account Number: " << client.accountNumber << endl;
    cout << "PIN code      : " << client.pinCode << endl;
    cout << "Name          : " << client.name << endl;
    cout << "Phone         : " << client.phone << endl;
    cout << "Balance       : " << client.balance << endl;
    cout << "------------------------------------" << endl;
}

short readMainMenuOption(){

    short choice = 0;
    cout << "choose what yow wanna do? [1 to 7]? ";
    cin >> choice;

    return choice;    
}

short readTransactionsMenuOption(){

    short choice = 0;
    cout << "choose what yow wanna do? [1 to 4]? ";
    cin >> choice;

    return choice;    
}

sClient readNewClient(){

    sClient client;
    
    cout << "Enter Account Number? ";
    getline(cin >> ws, client.accountNumber)  ;

    while (clientExistsByAccountNumber(client.accountNumber, clientsFileName)){

        cout << "\nClient with [" << client.accountNumber << "] Already exists, enter another account number\n";
        getline(cin >> ws, client.accountNumber)  ;
    }

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

sClient changeClientRecord(string accountNumber){

    sClient client;

    client.accountNumber = accountNumber;

    cout << "Enter PIN code? ";
    getline(cin >> ws, client.pinCode)  ;
    
    cout << "Enter Name? ";
    getline(cin, client.name)  ;
    
    cout << "Enter Phone Number? ";
    getline(cin, client.phone)  ;
    
    cout << "Enter Account Balance? ";
    cin >> client.balance;

    return client;
}

void addDataLineToFile(string fileName, string stDataLine){

    fstream myFile;
    myFile.open(fileName, ios::out | ios::app);

    if(myFile.is_open()){

        myFile << stDataLine << endl;
        myFile.close();
    }
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

void addNewClient(){

    sClient client;
    client = readNewClient();
    addDataLineToFile(clientsFileName, convertRecordToLine(client));
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
    return vClients;
}

string readClientAccountNumber(){

    string s1;
    
    cout << "Please Enter the Account Number?\n";
    getline(cin >> ws, s1);
    return s1;
}

void showAllClientsScreen(){

    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);

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

void addNewClients(){

    char addMore = 'Y';

    do{
        cout << "Adding new client:\n\n";

        addNewClient();
        cout << "\nClient added successfully, do you wanna add more clients?";
        cin >> addMore;
    }while(toupper(addMore) == 'Y');

}

void showAddNewClientsScreen(){

    cout << "\n-------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-------------------------------\n";

    addNewClients();
}

bool deleteClientByAccountNumber(string accountNumber, vector<sClient>& vClients){

    sClient client;
    char answer = 'n';

    if(findClientByAccountNumber(accountNumber, vClients, client)){

        printClientCard(client);
        
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
    return false;
}

void showDeleteClientScreen(){

    cout << "\n-------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-------------------------------\n";

    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);
    string accountNumber = readClientAccountNumber();
    deleteClientByAccountNumber(accountNumber, vClients);
}

bool updateClientByAccountNumber(string accountNumber, vector<sClient>& vClients){

    sClient client;
    char answer = 'n';

    if(findClientByAccountNumber(accountNumber, vClients, client)){

        printClientCard(client);
        
        cout << "Are you sure you wanna update this client? y/N ? ";
        cin >> answer;

        if(toupper(answer) == 'Y'){
        

            for(sClient& c : vClients){
                
                if(c.accountNumber == accountNumber){
                    c = changeClientRecord(accountNumber);
                    break;
                }
                
            }

            saveClientsDataToFile(clientsFileName, vClients);
            
            cout << "\n\nClient Deleted Successfully.";
            return true;
        
        }else
            return false;

        
    }else{

        cout << "\nClient with Account Nubmer (" << accountNumber << ") NOT found";
        return false;
    }
}

void showUpdateClientScreen(){

    cout << "\n-------------------------------\n";
    cout << "\tUpdate Client Screen";
    cout << "\n-------------------------------\n";

    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);
    string accountNumber = readClientAccountNumber();
    updateClientByAccountNumber(accountNumber, vClients);
}

void showFindClientScreen(){

    cout << "\n-------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-------------------------------\n";

    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);
    sClient client;
    string accountNumber = readClientAccountNumber();
    if(findClientByAccountNumber(accountNumber, vClients, client))
        printClientCard(client);
    else
        cout << "\nClient with Account Number [" << accountNumber << "] is not found!";
}

void showEndScreen(){

    cout << "\n-------------------------------\n";
    cout << "\tThe End (:";
    cout << "\n-------------------------------\n";
}

void goBackToMainMenu(){

    system("read -p \"Press any key to go back to Main Menu...\"");
    showMainMenu();
}

void goBackToTransactionsMenu(){
    
    system("read -p \"Press any key to go back to Transactions Menu...\"");
    system("clear");
    showTransactionsMenu();
}

bool withdrawBalanceByAccountNumber(string accountNumber, vector<sClient>& vClients){

    sClient client;
    char answer = 'n';
    double withdrawAmount;

    if(findClientByAccountNumber(accountNumber, vClients, client)){

        printClientCard(client);
        cout << "Please enter withdraw amount? ";
        cin >> withdrawAmount; 
        cout << "Are you sure you wanna perform this transaction? y/N ? ";
        cin >> answer;

        if(toupper(answer) == 'Y'){

            for(sClient& c : vClients){
                
                if(c.accountNumber == accountNumber){
                    if(c.balance > withdrawAmount){
                        c.balance -= withdrawAmount;
                        break;
                    }else
                        cout << "\nYou don't have this amount";
                }
                
            }

            saveClientsDataToFile(clientsFileName, vClients);
            
            cout << "\n\nAmount withdrawed Successfully.";
            return true;
        
        }else
            return false;

        
    }else{

        cout << "\nClient with Account Nubmer (" << accountNumber << ") NOT found";
        return false;
    }

}

bool depositBalanceByAccountNumber(string accountNumber, vector<sClient>& vClients, double amount){

    sClient client;
    char answer = 'n';
    cout << "Are you sure you wanna perform this transaction? y/N ? ";
    cin >> answer;

    if(toupper(answer) == 'Y'){

        for(sClient& c : vClients){
                
            if(c.accountNumber == accountNumber){
                c.balance += amount;
                saveClientsDataToFile(clientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is : " << c.balance;
                break;
            }
                
        }

            
        return true;
        
    }else
        return false;
}

void showDepositScreen(){

    cout << "\n-------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-------------------------------\n";

    sClient client;
    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);
    string accountNumber = readClientAccountNumber();   

    while(!findClientByAccountNumber(accountNumber, vClients, client)){
        
        cout << "\nClinet with [" << accountNumber << "] does not exist.\n";
        accountNumber = readClientAccountNumber();
    }

    printClientCard(client);

    double amount = 0;
    cout << "Please enter deposit amount? ";
    cin >> amount;

    depositBalanceByAccountNumber(accountNumber, vClients, amount);
}

void showWithdrawScreen(){

    cout << "\n-------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-------------------------------\n";

    sClient client;
    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);
    string accountNumber = readClientAccountNumber();   

    while(!findClientByAccountNumber(accountNumber, vClients, client)){
        
        cout << "\nClinet with [" << accountNumber << "] does not exist.\n";
        accountNumber = readClientAccountNumber();
    }

    printClientCard(client);

    double amount = 0;
    cout << "Please enter deposit amount? ";
    cin >> amount;

    while(amount > client.balance){

        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << client.balance;
        cout << " Please enter another amount? ";
        cin >> amount;
    }

    depositBalanceByAccountNumber(accountNumber, vClients, amount * -1);
}

void showTotalBalanceScreen(){

    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);
    double total = 0;


    cout << "\n\t\t\t\t\tBalance List (" << vClients.size() << ") Client(s)";
    cout << "\n___________________________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n___________________________________________________________\n" << endl;

    for(sClient client : vClients){
        total += client.balance;
        printClientRecord(client);
        cout << endl;
    }
    cout << "\t\t\t\t\tTotal Balance = " << total << endl;
}

void performTransactionsMenuOption(enTransactionsMenuOptions transactionsMenuOption){

    switch (transactionsMenuOption){
        case enTransactionsMenuOptions::eDeposit:{
            system("clear");
            showDepositScreen();
            goBackToTransactionsMenu();
            break;
        }
        case enTransactionsMenuOptions::eWithdraw:{
            system("clear");
            showWithdrawScreen();
            goBackToTransactionsMenu();
            break;
        }
        case enTransactionsMenuOptions::eTotalBalance:{
            
            system("clear");
            showTotalBalanceScreen();
            goBackToTransactionsMenu();
            break;
        }
        case enTransactionsMenuOptions::eMainMenu:{
            system("clear");
            showMainMenu();
            break;
        }
    }
}

void showTransactionsMenu(){

    cout << "=====================================\n";
    cout << "     Transactions Menu Screen\n";
    cout << "=====================================\n";
    cout << "[1] Deposit.\n";
    cout << "[2] Withdraw.\n";
    cout << "[3] Total Balance.\n";
    cout << "[4] Main Menu.\n";
    cout << "=====================================\n";

    performTransactionsMenuOption((enTransactionsMenuOptions)readTransactionsMenuOption());
}

void performMainMenuOption(enMainMenuOptions mainMenuOption){

    switch (mainMenuOption){
        case enMainMenuOptions::eListClients:{
            system("clear");
            showAllClientsScreen();
            goBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eAddNewClient:{
            system("clear");
            showAddNewClientsScreen();
            goBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eDeleteClient:{
            
            system("clear");
            showDeleteClientScreen();
            goBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eUpdateClient:{
            system("clear");
            showUpdateClientScreen();
            goBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eFindClient:{
            system("clear");
            showFindClientScreen();
            goBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eTransactions:{
            
            system("clear");
            showTransactionsMenu();
            goBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eExit:{
            system("clear");
            showEndScreen();
            break;
        }
    
    }
}

void showMainMenu(){

    system("clear");

    cout << "=====================================\n";
    cout << "             Main Screen\n";
    cout << "=====================================\n";
    cout << "[1] show clients list.\n";
    cout << "[2] add new client.\n";
    cout << "[3] delete client.\n";
    cout << "[4] update client info.\n";
    cout << "[5] find client.\n";
    cout << "[6] Transactions.\n";
    cout << "[7] Exit.\n";
    cout << "=====================================\n";

    performMainMenuOption((enMainMenuOptions)readMainMenuOption());
}

int main(){

    showMainMenu();

    return 0;
}