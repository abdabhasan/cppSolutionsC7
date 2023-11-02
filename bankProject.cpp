#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void showMainMenu();
void showTransactionsMenu();
void showManageUsersMenu();
void goBackToMainMenu();
void Login();

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
    eManageUsers = 7, 
    eExit = 8 
};

enum enTransactionsMenuOptions{
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalance = 3,
    eMainMenu = 4,
};

enum enManageUsersMenuOptions { 
 eListUsers = 1,
 eAddNewUser = 2,
 eDeleteUser = 3,
 eUpdateUser = 4,
 eFindUser = 5,
 eMainMenue = 6 
 };

enum enMainMenuPermissions { 
 eAll = -1,
 pListClients = 1,
 pAddNewClient = 2,
 pDeleteClient= 4,
 pUpdateClients = 8,
 pFindClient = 16,
 pTranactions = 32,
 pManageUsers = 64 
 };

struct stUser{

    string username;
    string password;
    int permissions;
    bool markForDelete = false;
};

// ===================> global vars <===========================
const string clientsFileName = "clients.md";
const string usersFileName = "users.md";

stUser currentUser;
// ===================> global vars <===========================

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

stUser convertUserLineToRecord(string line, string seperator = "#//#"){

    stUser user;
    vector<string> vUserData;

    vUserData = splitStringWords(line, seperator);
    user.username = vUserData[0];
    user.password = vUserData[1];
    user.permissions = stoi(vUserData[2]);

    return user;
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

vector<stUser> loadUsersDataFromFile(string fileName){

    vector<stUser> vUsers;

    fstream myFile;
    myFile.open(fileName, ios::in); // read mode

    if(myFile.is_open()){

        string line;
        stUser user;

        while(getline(myFile, line)){

            user = convertUserLineToRecord(line);
            
            vUsers.push_back(user);
        }
        myFile.close(); 
    }
    return vUsers;
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

bool userExistsByUsername(string username, string fileName){

    vector<stUser> vUsers;
    fstream myFile;
    myFile.open(fileName, ios::in); // read mode

    if(myFile.is_open()){

        string line;
        stUser user;

        while(getline(myFile, line)){
            
            user = convertUserLineToRecord(line);
            if(user.username == username){
                myFile.close();
                return true;
            }
            vUsers.push_back(user);
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

void printUserRecord(stUser user){

    cout << "| " << setw(15) << left << user.username;
    cout << "| " << setw(10) << left << user.password;
    cout << "| " << setw(40) << left << user.permissions;
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

void printUserCard(stUser user){

    cout << "The following are the user details:\n";

    cout << "------------------------------------" << endl;
    cout << "Username             : " << user.username << endl;
    cout << "password             : " << user.password << endl;
    cout << "permissions          : " << user.permissions << endl;
    cout << "------------------------------------" << endl;
}

short readMainMenuOption(){

    short choice = 0;
    cout << "choose what yow wanna do? [1 to 8]? ";
    cin >> choice;

    return choice;    
}

short readManageUsersMenuOption(){

    short choice = 0;
    cout << "choose what yow wanna do? [1 to 6]? ";
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

int readPermissionsToSet(){

    int permissions = 0;
    char answer = 'n';
    
    cout << "\nDo you wanna give full access? y/n? ";
    cin >> answer;

    if(answer == 'y' || answer == 'Y')
        return -1;
    
    cout << "\nDo U wanna give access to : \n";

    cout << "\nshow clients list? y/n? ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y')
        permissions += enMainMenuPermissions::pListClients;

    cout << "\nadd new client? y/n? ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y')
        permissions += enMainMenuPermissions::pAddNewClient;

    cout << "\ndelete client? y/n? ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y')
        permissions += enMainMenuPermissions::pDeleteClient;

    cout << "\nupdate client? y/n? ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y')
        permissions += enMainMenuPermissions::pUpdateClients;

    cout << "\nfind client? y/n? ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y')
        permissions += enMainMenuPermissions::pFindClient;

    cout << "\ntransactions? y/n? ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y')
        permissions += enMainMenuPermissions::pTranactions;

    cout << "\nmanage users? y/n? ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y')
        permissions += enMainMenuPermissions::pManageUsers;

    return permissions;   
}

stUser readNewUser(){

    stUser user;
    
    cout << "Enter username? ";
    getline(cin >> ws, user.username)  ;

    while (userExistsByUsername(user.username, clientsFileName)){

        cout << "\nUser with [" << user.username << "] Already exists, enter username\n";
        getline(cin >> ws, user.username)  ;
    }

    cout << "Enter password ? ";
    getline(cin, user.password)  ;

    user.permissions = readPermissionsToSet();

    return user;
}

stUser changeUserRecord(string username){

    stUser user;

    user.username = username;

    cout << "Enter password? ";
    getline(cin >> ws, user.password)  ;
    
    return user;
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

string convertUserRecordToLine(stUser user, string seperator = "#//#"){

    string stUserRecord = "";

    stUserRecord += user.username + seperator;
    stUserRecord += user.password + seperator;
    stUserRecord += to_string(user.permissions);

    return stUserRecord;
}

void addNewClient(){

    sClient client;
    client = readNewClient();
    addDataLineToFile(clientsFileName, convertRecordToLine(client));
}

void addNewUser(){

    stUser user;
    user = readNewUser();
    addDataLineToFile(usersFileName, convertUserRecordToLine(user));
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

bool findUserByUsername(string username, vector<stUser> vUsers, stUser& user){

    for(stUser& u : vUsers){

        if(u.username == username){

            user = u;
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

bool markUserForDeleteByUsername(string username, vector<stUser>& vUsers){

    for(stUser& u : vUsers){
        
        if(u.username == username){

            u.markForDelete = true;
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

vector<stUser> saveUsersDataToFile(string fileName, vector<stUser> vUsers){

    fstream myFile;
    myFile.open(fileName, ios::out); // overwrite

    string dataLine;

    if(myFile.is_open()){

        for(stUser c: vUsers){

            if(c.markForDelete == false){

                dataLine = convertUserRecordToLine(c);
                myFile << dataLine << endl;
            }
        }
        myFile.close();
    }
    return vUsers;
}

string readClientAccountNumber(){

    string s1;
    
    cout << "Please Enter the Account Number?\n";
    getline(cin >> ws, s1);
    return s1;
}

string readUsername(){

    string s1;
    
    cout << "Please Enter the username?\n";
    getline(cin >> ws, s1);
    return s1;
}

bool checkAccessPermission(enMainMenuPermissions permission){

    if(currentUser.permissions == enMainMenuPermissions::eAll)
        return true;
    if((permission & currentUser.permissions) == permission)
        return true;
    else 
        return false;
}

void showAccessDeniedMessage(){

    cout << "\n-------------------------\n";
    cout << "Access denied, \nYou dont have permission to do this,\nPlease contact the ADMIN";
    cout << "\n-------------------------\n";
}

void showAllClientsScreen(){

    if(!checkAccessPermission(enMainMenuPermissions::pListClients)){
        showAccessDeniedMessage();
        goBackToMainMenu();
        return;
    }

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

    if(!checkAccessPermission(enMainMenuPermissions::pAddNewClient)){
        showAccessDeniedMessage();
        goBackToMainMenu();
        return;
    }


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

bool deleteUserByUsername(string username, vector<stUser>& vUsers){

    stUser user;
    char answer = 'n';

    if(findUserByUsername(username, vUsers, user)){

        printUserCard(user);
        
        cout << "Are you sure you wanna delete this user? y/N ? ";
        cin >> answer;

        if(toupper(answer) == 'Y'){
        
            markUserForDeleteByUsername(username, vUsers);
            saveUsersDataToFile(usersFileName, vUsers);

            // refresh clients
            vUsers = loadUsersDataFromFile(usersFileName);

            cout << "\n\nUser Deleted Successfully.";
            return true;
        }
        
    }
    else{

        cout << "\nUser with username (" << username << ") NOT found";
        return false;
    }
    return false;
}

void showDeleteClientScreen(){

    if(!checkAccessPermission(enMainMenuPermissions::pDeleteClient)){
        showAccessDeniedMessage();
        goBackToMainMenu();
        return;
    }

    cout << "\n-------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-------------------------------\n";

    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);
    string accountNumber = readClientAccountNumber();
    deleteClientByAccountNumber(accountNumber, vClients);
}

bool updateUserByUsername(string username, vector<stUser>& vUsers){

    stUser user;
    char answer = 'n';

    if(findUserByUsername(username, vUsers, user)){

        printUserCard(user);
        
        cout << "Are you sure you wanna update this user? y/N ? ";
        cin >> answer;

        if(toupper(answer) == 'Y'){
        

            for(stUser& c : vUsers){
                
                if(c.username == username){
                    c = changeUserRecord(username);
                    break;
                }
                
            }

            saveUsersDataToFile(clientsFileName, vUsers);
            
            cout << "\n\nClient Deleted Successfully.";
            return true;
        
        }else
            return false;

        
    }else{

        cout << "\nClient with Account Nubmer (" << username << ") NOT found";
        return false;
    }
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

    if(!checkAccessPermission(enMainMenuPermissions::pUpdateClients)){
        showAccessDeniedMessage();
        goBackToMainMenu();
        return;
    }

    cout << "\n-------------------------------\n";
    cout << "\tUpdate Client Screen";
    cout << "\n-------------------------------\n";

    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);
    string accountNumber = readClientAccountNumber();
    updateClientByAccountNumber(accountNumber, vClients);
}

void showFindClientScreen(){

    if(!checkAccessPermission(enMainMenuPermissions::pFindClient)){
        showAccessDeniedMessage();
        goBackToMainMenu();
        return;
    }

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

void showAllUsersScreen(){

    vector<stUser> vUsers = loadUsersDataFromFile(usersFileName);

    cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") Users(s)";
    cout << "\n___________________________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(40) << "Permissions";
    cout << "\n___________________________________________________________\n" << endl;

    
    if(vUsers.size() == 0)
        cout << "\t\t\t\tNo Users Available in the system!";
    else{
        
        for(stUser user : vUsers){

            printUserRecord(user);
            cout << endl;
        }
    }
    
    
}

void showListUsersScreen(){
    showAllUsersScreen();
}

void addNewUsers(){

    char addMore = 'Y';

    do{
        cout << "Adding new User:\n\n";

        addNewUser();
        cout << "\nUser added successfully, do you wanna add more users?";
        cin >> addMore;
    }while(toupper(addMore) == 'Y');

}

void showAddNewUserScreen(){

    cout << "\n--------------------------------------\n";
    cout << "\tAdd new user Screen";
    cout << "\n--------------------------------------\n";

    addNewUsers();

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

void goBackToManageUsersMenu(){

    system("clear");
    showManageUsersMenu();
}

void showDeleteUserScreen(){
    
    cout << "\n-------------------------------\n";
    cout << "\tDelete User Screen";
    cout << "\n-------------------------------\n";

    vector<stUser> vUsers = loadUsersDataFromFile(usersFileName);
    string username = readUsername();
    deleteUserByUsername(username, vUsers);
}

void showUpdateUserScreen(){

    cout << "\n-------------------------------\n";
    cout << "\tUpdate User Screen";
    cout << "\n-------------------------------\n";

    vector<stUser> vUsers = loadUsersDataFromFile(usersFileName);
    string username = readUsername();
    updateUserByUsername(username, vUsers);
}

void showFindUserScreen(){

    cout << "\n-------------------------------\n";
    cout << "\tFind User Screen";
    cout << "\n-------------------------------\n";

    vector<stUser> vUsers = loadUsersDataFromFile(usersFileName);
    stUser user;
    string username = readUsername();
    if(findUserByUsername(username, vUsers, user))
        printUserCard(user);
    else
        cout << "\nUser with username [" << username << "] is not found!";
}

void performManageUsersMenuOption(enManageUsersMenuOptions manageUsersMenuOption){

    switch (manageUsersMenuOption){
        case enManageUsersMenuOptions::eListUsers:{
            showListUsersScreen();
            goBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eAddNewUser:{
            system("clear");
            showAddNewUserScreen();
            goBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eDeleteUser:{
            system("clear");
            showDeleteUserScreen();
            goBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eUpdateUser:{
            system("clear");
            showUpdateUserScreen();
            goBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eFindUser:{
            system("clear");
            showFindUserScreen();
            goBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eMainMenue:{
            system("clear");
            goBackToMainMenu();
            break;
        }
    }
}

void showTransactionsMenu(){

    if(!checkAccessPermission(enMainMenuPermissions::pTranactions)){
        showAccessDeniedMessage();
        goBackToMainMenu();
        return;
    }


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

void showManageUsersMenu(){

    if(!checkAccessPermission(enMainMenuPermissions::pManageUsers)){
        showAccessDeniedMessage();
        goBackToMainMenu();
        return;
    }

    system("clear");

    cout << "=====================================\n";
    cout << "\t\tManage Users Mneu Screen\n";
    cout << "=====================================\n";
    cout << "[1] list users.\n";
    cout << "[2] add new user.\n";
    cout << "[3] delete user.\n";
    cout << "[4] update user info.\n";
    cout << "[5] find user.\n";
    cout << "[6] main menu.\n";
    cout << "=====================================\n";

    performManageUsersMenuOption((enManageUsersMenuOptions)readManageUsersMenuOption());

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
        case enMainMenuOptions::eManageUsers:{
            system("clear");
            showManageUsersMenu();
            break;
        }
        case enMainMenuOptions::eExit:{
            system("clear");
            // showEndScreen();
            Login();
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
    cout << "[7] Manage users.\n";
    cout << "[8] Logout.\n";
    cout << "=====================================\n";

    performMainMenuOption((enMainMenuOptions)readMainMenuOption());
}

bool findUserByUsernameAndPassword(string username, string password, stUser& user){

    vector<stUser> vUsers = loadUsersDataFromFile(usersFileName);

    for(stUser u : vUsers){

        if(u.username == username && u.password == password){

            user = u;
            return true;
        }
    }
    return false;
}

bool loadUserInfo(string username, string password){

    if(findUserByUsernameAndPassword(username, password, currentUser))
        return true;
    else 
        return false;
}

void Login(){

    bool loginFaild = false;
    string username, password;
    do{
        
        system("clear");

        cout << "\n-------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n-------------------------------\n"; 
        
        if(loginFaild)
            cout << "invalid username/password!\n";

        cout << "Enter username? ";
        cin >> username;

        cout << "Enter password? ";
        cin >> password;
        loginFaild = !loadUserInfo(username, password);
    
    }while(loginFaild);

    showMainMenu();
}

int main(){

    Login();

    return 0;
}