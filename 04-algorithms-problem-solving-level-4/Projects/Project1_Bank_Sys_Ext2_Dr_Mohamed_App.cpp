#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

enum eMainMenuPermissions
{
    pAll = -1,
    pListClients = 1,
    pAddNewClient = 2,
    pDeleteClient = 4,
    pUpdateClientInfo = 8,
    pFindClient = 16,
    pTransactions = 32,
    pManageUsers = 64,
};

enum enMainMenuOption
{
    eListClients = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClientInfo = 4,
    eFindClient = 5,
    eTransactions = 6,
    eManageUsers = 7,
    eLogout = 8
};

enum enTransactionMenuOption
{
    eDeposite = 1,
    eWithdraw = 2,
    eTotalBalances = 3,
    eMainMenu = 4
};

enum enManageUsersMenuOptions
{
    eListUsers = 1,
    eAddNewUser = 2,
    eDeleteUser = 3,
    eUpdateUser = 4,
    eFindUser = 5,
    emainmenu = 6
};

struct stUser
{
    string UserName;
    string Password;
    short Permissions;
    bool MarkForDelete;
};

struct stClient
{
    string AccountNumber;
    string PinCode;
    string ClientName;
    string PhoneNumber;
    double AccountBalance;
    bool MarkForDelete;
};

const string ClientsFileName = "ClientsData.txt";
const string UsersFileName = "UsersData.txt";
stUser ActiveUser;

vector<string> SplitFunction(string Text)
{
    vector<string> vString;
    string Delim = "#//#";
    string Sword;
    short pos = 0;
    while ((pos = Text.find(Delim)) != std::string::npos)
    {
        Sword = Text.substr(0, pos);
        if (Sword != " ")
        {
            vString.push_back(Sword);
            Text.erase(0, pos + Delim.length());
        }
    }
    if (Text != "")
    {
        vString.push_back(Text);
    }
    return vString;
}

stClient ConvertClientLineRecord(string Line)
{
    stClient client;
    vector<string> vString = SplitFunction(Line);
    client.AccountNumber = vString.at(0);
    client.PinCode = vString.at(1);
    client.ClientName = vString.at(2);
    client.PhoneNumber = vString.at(3);
    client.AccountBalance = stod(vString.at(4));
    return client;
}

stUser ConvertUserLineRecord(string Line)
{
    stUser user;
    vector<string> vString = SplitFunction(Line);
    user.UserName = vString.at(0);
    user.Password = vString.at(1);
    user.Permissions = stoi(vString.at(2));
    return user;
}

vector<stClient> LoadClientsRecordFromFile(string FileName)
{
    vector<stClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        stClient client;
        string Line;
        while (getline(MyFile, Line))
        {
            client = ConvertClientLineRecord(Line);
            vClients.push_back(client);
        }
        MyFile.close();
    }
    return vClients;
}

vector<stUser> LoadUsersRecordFromFile(string FileName)
{
    vector<stUser> vUsers;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        stUser User;
        string Line;
        while (getline(MyFile, Line))
        {
            User = ConvertUserLineRecord(Line);
            vUsers.push_back(User);
        }
        MyFile.close();
    }
    return vUsers;
}

void PrintCliet(stClient client)
{
    cout << "| " << setw(15) << client.AccountNumber;
    cout << "| " << setw(9) << client.PinCode;
    cout << "| " << setw(37) << client.ClientName;
    cout << "| " << setw(14) << client.PhoneNumber;
    cout << "| " << setw(12) << fixed << client.AccountBalance;
    cout << "\n";
}

void PrintUser(stUser user)
{
    cout << "| " << setw(15) << user.UserName;
    cout << "| " << setw(12) << user.Password;
    cout << "| " << setw(12) << fixed << user.Permissions;
    cout << "\n";
}

void PrintClientsTable(vector<stClient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(9) << "Pin Code";
    cout << "| " << left << setw(37) << "Client Name";
    cout << "| " << left << setw(14) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n________________________________________________________________________________________________\n\n";
    if (vClients.size() == 0)
    {
        cout << "\n\nNo Clients Avaliable in this File!\n";
    }
    else
    {
        for (stClient c : vClients)
        {
            PrintCliet(c);
        }
        cout << "\n\n\n\n";
        cout << "________________________________________________________________________________________________\n";
    }
}

void PrintUsersTable(vector<stUser> vUsers)
{
    cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s).";
    cout << "\n________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(12) << "Password";
    cout << "| " << left << setw(12) << "Permissions";
    cout << "\n________________________________________________________________________________________________\n\n";
    if (vUsers.size() == 0)
    {
        cout << "\n\nNo Users Avaliable in this File!\n";
    }
    else
    {
        for (stUser U : vUsers)
        {
            PrintUser(U);
        }
        cout << "\n\n\n\n";
        cout << "________________________________________________________________________________________________\n";
    }
}

void PrintClietBalance(stClient client)
{
    cout << "| " << setw(15) << client.AccountNumber;
    cout << "| " << setw(37) << client.ClientName;
    cout << "| " << setw(37) << fixed << client.AccountBalance;
    cout << "\n";
}

void PrintClientsBalancesTable(vector<stClient> vClients)
{
    int TotalBalances = 0;
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(37) << "Client Name";
    cout << "| " << left << setw(37) << "Balance";
    cout << "\n________________________________________________________________________________________________\n\n";
    if (vClients.size() == 0)
    {
        cout << "\n\nNo Clients Avaliable in this File!\n";
        cout << "\n\t\t\t\t\tTotal Balances = 0" << endl;
    }
    else
    {
        for (stClient c : vClients)
        {
            PrintClietBalance(c);
            TotalBalances += c.AccountBalance;
        }
        cout << "\n\n\n";
        cout << "________________________________________________________________________________________________\n";
        cout << "\n\t\t\t\t\tTotal Balances = " << TotalBalances << endl;
    }
}

bool DoesClientExist(string AccountNumber, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        stClient client;
        while (getline(MyFile, Line))
        {
            client = ConvertClientLineRecord(Line);
            if (client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
        }
        MyFile.close();
    }
    return false;
}

bool CheckAccessPermissions(eMainMenuPermissions Permission)
{
    if (ActiveUser.Permissions == eMainMenuPermissions::pAll)
    {
        return true;
    }

    if ((ActiveUser.Permissions & Permission) == Permission)
        return true;
    else
        return false;
}

bool DoesUserExists(string UserName, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        stUser user;
        while (getline(MyFile, Line))
        {
            user = ConvertUserLineRecord(Line);
            if (user.UserName == UserName)
            {
                MyFile.close();
                return true;
            }
            MyFile.close();
        }
    }
    return false;
}

bool FindClientByAccountNumber(string ReqAccountNumber, stClient &client, vector<stClient> vClients)
{
    for (stClient &C : vClients)
    {
        if (C.AccountNumber == ReqAccountNumber)
        {
            client = C;
            return true;
        }
    }
    return false;
}

bool FindUserbyUserName(string InputUserName, stUser &User, string FileName)
{
    vector<stUser> vUsers = LoadUsersRecordFromFile(UsersFileName);
    for (stUser &U : vUsers)
    {
        if (U.UserName == InputUserName)
        {
            User = U;
            return true;
        }
    }
    return false;
}

string ConvertClientRecordToLine(stClient client)
{
    string Delim = "#//#";
    string Line = "";
    Line += client.AccountNumber + Delim;
    Line += client.PinCode + Delim;
    Line += client.ClientName + Delim;
    Line += client.PhoneNumber + Delim;
    Line += to_string(client.AccountBalance);
    return Line;
}

string ConvertUserRecordToLine(stUser User)
{
    string Delim = "#//#";
    string Line = "";
    Line += User.UserName + Delim;
    Line += User.Password + Delim;
    Line += to_string(User.Permissions);
    return Line;
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

string ReadUsername()
{
    string UserName = "";
    cout << "\nPlease enter UserName? ";
    cin >> UserName;
    return UserName;
}

short ReadUserPermissions()
{
    short Permissions = 0;
    char Answer = 'n';

    cout << "\n\nDo you want to give full access? y/n? ";
    cin >> Answer;
    if (Answer == 'Y' || Answer == 'y')
    {
        return -1;
    }

    cout << "\nDo you want to give access to: ";

    cout << "\n\nShow Client List? y/n? ";
    cin >> Answer;
    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += eMainMenuPermissions::pListClients;
    }

    cout << "\nAdd New Client? y/n? ";
    cin >> Answer;
    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += eMainMenuPermissions::pAddNewClient;
    }

    cout << "\nDelete Client? y/n? ";
    cin >> Answer;
    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += eMainMenuPermissions::pDeleteClient;
    }

    cout << "\nUpdate Client? y/n? ";
    cin >> Answer;
    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += eMainMenuPermissions::pUpdateClientInfo;
    }

    cout << "\nFind Client? y/n? ";
    cin >> Answer;
    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += eMainMenuPermissions::pFindClient;
    }

    cout << "\nTransactions? y/n? ";
    cin >> Answer;
    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += eMainMenuPermissions::pTransactions;
    }

    cout << "\nManage Users? y/n? ";
    cin >> Answer;
    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += eMainMenuPermissions::pManageUsers;
    }

    return Permissions;
}

stUser ReadNewUser()
{
    stUser NewUser;
    cout << "\nEnter Username? ";
    getline(cin >> ws, NewUser.UserName);
    while (DoesUserExists(NewUser.UserName, UsersFileName))
    {
        cout << "\nUser with [" << NewUser.UserName << "] is already exists, Enter another Username? ";
        getline(cin >> ws, NewUser.UserName);
    }
    cout << "\nEnter Password? ";
    getline(cin >> ws, NewUser.Password);
    NewUser.Permissions = ReadUserPermissions();
    return NewUser;
}

stClient ReadNewClient()
{
    stClient client;
    cout << "Enter Account Number? ";
    getline(cin >> ws, client.AccountNumber);
    while (DoesClientExist(client.AccountNumber, ClientsFileName))
    {
        cout << "Client With Account Number (" << client.AccountNumber;
        cout << ") Already Exists, Enter Another Account Number? ";
        getline(cin >> ws, client.AccountNumber);
    }
    cout << "\nEnter PinCode? ";
    getline(cin >> ws, client.PinCode);
    cout << "\nEnter Name? ";
    getline(cin, client.ClientName);
    cout << "\nEnter Phone Number? ";
    getline(cin, client.PhoneNumber);
    cout << "\nEnter Account Balance? ";
    cin >> client.AccountBalance;
    return client;
}

stClient EditClientInVector(string AccountNumber)
{
    stClient client;
    client.AccountNumber = AccountNumber;
    cout << "\nEnter Pin Code? ";
    getline(cin >> ws, client.PinCode);
    cout << "\nEnter Name? ";
    getline(cin, client.ClientName);
    cout << "\nEnter Phone? ";
    getline(cin, client.PhoneNumber);
    cout << "\nEnter Account Balance? ";
    cin >> client.AccountBalance;
    return client;
}

void MarkClientForDelete(vector<stClient> &vClients, string AccountNumber)
{
    for (stClient &c : vClients)
    {
        if (c.AccountNumber == AccountNumber)
        {
            c.MarkForDelete = true;
        }
    }
}

void MarkUserForDelete(vector<stUser> &vUsers, string Username)
{
    for (stUser &u : vUsers)
    {
        if (u.UserName == Username)
        {
            u.MarkForDelete = true;
        }
    }
}

void PrintClientCard(stClient client)
{
    cout << "\nThe following are the client details: " << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Account Number: " << client.AccountNumber << endl;
    cout << "Pin code      : " << client.PinCode << endl;
    cout << "Client Name   : " << client.ClientName << endl;
    cout << "Phone Number  : " << client.PhoneNumber << endl;
    cout << "Account Balance: " << fixed << client.AccountBalance << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void PrintUserCard(stUser User)
{
    cout << "\nThe following are the user details: " << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Username:    " << User.UserName << endl;
    cout << "Password   : " << User.Password << endl;
    cout << "Permissions: " << fixed << User.Permissions << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void AddClientDataToFile(string FileName)
{
    stClient client = ReadNewClient();
    string LineRec = ConvertClientRecordToLine(client);
    fstream Myfile;
    Myfile.open(FileName, ios::out | ios::app);
    if (Myfile.is_open())
    {
        Myfile << LineRec << endl;
        Myfile.close();
    }
}

void AddUserDataToFile(string FileName, stUser User)
{
    string LineRec = ConvertUserRecordToLine(User);
    fstream Myfile;
    Myfile.open(FileName, ios::out | ios::app);
    if (Myfile.is_open())
    {
        Myfile << LineRec << endl;
        Myfile.close();
    }
}

void OverWriteClientsFileWithNewClientsList(vector<stClient> vClients)
{
    string Line;
    fstream MyFile;
    MyFile.open(ClientsFileName, ios::out);
    if (MyFile.is_open())
    {
        for (stClient &c : vClients)
        {
            if (!c.MarkForDelete)
            {
                Line = ConvertClientRecordToLine(c);
                MyFile << Line << endl;
            }
        }
        MyFile.close();
    }
}

void OverWriteUsersFileWithNewClientsList(vector<stUser> vUsers)
{
    string Line;
    fstream MyFile;
    MyFile.open(UsersFileName, ios::out);
    if (MyFile.is_open())
    {
        for (stUser &u : vUsers)
        {
            if (!u.MarkForDelete)
            {
                Line = ConvertUserRecordToLine(u);
                MyFile << Line << endl;
            }
        }
        MyFile.close();
    }
}

void ViewMainMenuScreen();

void ViewTransacionsMenu();

void ViewManageUsersMenu();

void ShowAccessDeniedScreen();

short ChooseWhatToDoFromMainMenu()
{
    short Num = 0;
    do
    {
        cout << "Choose what do you want to do? [1 to 8]? ";
        cin >> Num;
    } while (Num < 1 || Num > 8);
    return Num;
}

short ChooseWhatToDoFromTransactionsMenu()
{
    short Num = 0;
    do
    {
        cout << "Choose what do you want to do? [1 to 4]? ";
        cin >> Num;
    } while (Num < 1 || Num > 4);
    return Num;
}

short ChooseWhatToDoFromManageUsersMenu()
{
    short Num = 0;
    do
    {
        cout << "Choose What do you want to do? [1 to 6]? ";
        cin >> Num;
    } while (Num < 1 || Num > 6);
    return Num;
}

void ShowClientsListFunction()
{
    if (!CheckAccessPermissions(eMainMenuPermissions::pListClients))
    {
        ShowAccessDeniedScreen();
        return;
    }

    vector<stClient> vClients = LoadClientsRecordFromFile(ClientsFileName);
    system("cls");
    PrintClientsTable(vClients);
}

void ShowUsersListFunction()
{
    vector<stUser> vUsers = LoadUsersRecordFromFile(UsersFileName);
    system("cls");
    PrintUsersTable(vUsers);
}

void AddClients()
{
    char AddMore = 'Y';
    do
    {
        cout << "Adding New Client:\n\n";
        AddClientDataToFile(ClientsFileName);
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    } while (towupper(AddMore) == 'Y');
}

void AddNewUser()
{
    stUser User;
    User = ReadNewUser();
    AddUserDataToFile(UsersFileName, User);
}

void AddUsers()
{
    char AddMore = 'Y';
    do
    {
        cout << "Adding New User: \n";
        AddNewUser();
        cout << "\nUser Added Successfully, do you want to add more Users? Y/N? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

void ShowAddUserScreen()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tAdd New User Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;
    AddUsers();
    cout << "\n";
}

void ShowAddClientsScreen()
{
    if (!CheckAccessPermissions(eMainMenuPermissions::pAddNewClient))
    {
        ShowAccessDeniedScreen();
        return;
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tAdd New Client Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;
    AddClients();
    cout << "\n\n";
}

void DeleteClient(string AccountNumber, vector<stClient> &vClients)
{
    stClient client;
    char AreYouSure = 'N';

    if (FindClientByAccountNumber(AccountNumber, client, vClients))
    {
        PrintClientCard(client);
        cout << "\n\nAre you sure you want to delete this client? y/n ? ";
        cin >> AreYouSure;
        if (AreYouSure == 'Y' || AreYouSure == 'y')
        {
            MarkClientForDelete(vClients, AccountNumber);
            OverWriteClientsFileWithNewClientsList(vClients);
            cout << "\nClient Deleted Successfully.\n\n";
        }
    }
    else
    {
        cout << "Client with Account Number (" << AccountNumber << ") is Not Found!\n";
    }
}

void DeleteUser(string Username, vector<stUser> &vUsers)
{
    stUser user;
    if (Username == "Admin")
    {
        cout << "\n\nYou Cannot Delete This User." << endl;
    }
    else
    {
        char AreYouSure = 'N';
        if (FindUserbyUserName(Username, user, UsersFileName))
        {
            PrintUserCard(user);
            cout << "\n\nAre you sure you want to delete this user? y/n? ";
            cin >> AreYouSure;
            if (AreYouSure == 'Y' || AreYouSure == 'y')
            {
                MarkUserForDelete(vUsers, Username);
                OverWriteUsersFileWithNewClientsList(vUsers);
                cout << "\nUser Deleted Successfully.\n\n";
            }
        }
        else
        {
            cout << "User with Username (" << Username << ") is Not Found!\n";
        }
    }
}

void ShowDeleteClientScreen()
{
    if (!CheckAccessPermissions(eMainMenuPermissions::pDeleteClient))
    {
        ShowAccessDeniedScreen();
        return;
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tDelete Client Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;
    vector<stClient> vClients = LoadClientsRecordFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClient(AccountNumber, vClients);
}

void ShowDeleteUsersScreen()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tDelete User Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;

    vector<stUser> vUsers = LoadUsersRecordFromFile(UsersFileName);
    string Username = ReadUsername();
    DeleteUser(Username, vUsers);
}

void UpdateClient(string AccountNumber, vector<stClient> &vClients)
{
    stClient client;
    char AreYouSure = 'N';
    if (FindClientByAccountNumber(AccountNumber, client, vClients))
    {
        PrintClientCard(client);
        cout << "Are You sure you want to update this client? y/n ? ";
        cin >> AreYouSure;
        if (AreYouSure == 'y' || AreYouSure == 'Y')
        {
            for (stClient &c : vClients)
            {
                if (c.AccountNumber == AccountNumber)
                {
                    c = EditClientInVector(AccountNumber);
                    break;
                }
            }
            OverWriteClientsFileWithNewClientsList(vClients);
            cout << "\n\nSelected client data updated successfully.\n\n";
        }
    }
    else
    {
        cout << "Client with Account Number (" << AccountNumber << ") is Not Found!\n";
    }
}

void UpdateUser(string Username, vector<stUser> &vUsers)
{
    stUser user;
    char AreYouSure;
    if (FindUserbyUserName(Username, user, UsersFileName))
    {
        PrintUserCard(user);
        cout << "Are you sure you want to update this user? y/n? ";
        cin >> AreYouSure;
        if (AreYouSure == 'y' || AreYouSure == 'y')
        {
            for (stUser &U : vUsers)
            {
                if (U.UserName == Username)
                {
                    cout << "\nEnter password? ";
                    getline(cin >> ws, U.Password);
                    U.Permissions = ReadUserPermissions();
                    break;
                }
            }
            OverWriteUsersFileWithNewClientsList(vUsers);
            cout << "\n\nSelected User data updated successfully.\n\n";
        }
    }
    else
    {
        cout << "User with Username (" << Username << ") is Not Found!\n";
    }
}

void ShowEditClientScreen()
{
    if (!CheckAccessPermissions(eMainMenuPermissions::pUpdateClientInfo))
    {
        ShowAccessDeniedScreen();
        return;
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tUpdate Client Info Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;

    vector<stClient> vClients = LoadClientsRecordFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClient(AccountNumber, vClients);
}

void ShowEditUserScreen()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tUpdate User Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;

    vector<stUser> vUsers = LoadUsersRecordFromFile(UsersFileName);
    string Username = ReadUsername();
    UpdateUser(Username, vUsers);
}

void ShowFindClientScreen()
{
    if (!CheckAccessPermissions(eMainMenuPermissions::pFindClient))
    {
        ShowAccessDeniedScreen();
        return;
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tFind Client Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;

    vector<stClient> vClients = LoadClientsRecordFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    stClient client;
    if (FindClientByAccountNumber(AccountNumber, client, vClients))
    {
        PrintClientCard(client);
    }
    else
    {
        cout << "Client with Account Number (" << AccountNumber << ") is Not Found!\n";
    }
}

void ShowFindUserScreen()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tFind User Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;

    vector<stUser> vUsers = LoadUsersRecordFromFile(UsersFileName);
    string Username = ReadUsername();
    stUser user;
    if (FindUserbyUserName(Username, user, UsersFileName))
    {
        PrintUserCard(user);
    }
    else
    {
        cout << "User with Username (" << Username << ") is Not Found!\n";
    }
}

bool FindUserByUsernameAndPassword(string Username, string Password, stUser &User)
{
    vector<stUser> vUsers = LoadUsersRecordFromFile(UsersFileName);
    for (stUser &U : vUsers)
    {
        if (U.UserName == Username && U.Password == Password)
        {
            User = U;
            return true;
        }
    }
    return false;
}

bool LoadUserInfo(string Username, string Password)
{
    if (FindUserByUsernameAndPassword(Username, Password, ActiveUser))
        return true;
    else
        return false;
}

void LoginScreen()
{
    bool LoginFailed = false;
    string Username, Password;
    do
    {
        system("cls");

        cout << "-------------------------------------------------------------" << endl;
        cout << "\t\tLogin Screen" << endl;
        cout << "-------------------------------------------------------------" << endl;
        if (LoginFailed)
        {
            cout << "\nInvalid Username/Password!\n";
        }

        cout << "Enter Username? ";
        cin >> Username;

        cout << "Enter Password? ";
        cin >> Password;

        LoginFailed = !(LoadUserInfo(Username, Password));
    } while (LoginFailed);

    ViewMainMenuScreen();
}

void ShowAccessDeniedScreen()
{
    cout << "-------------------------------------" << endl;
    cout << "Access Denied," << endl;
    cout << "You don't Have Permission to Do this," << endl;
    cout << "Please Contact Your Admin." << endl;
    cout << "-------------------------------------" << endl;
}

void GoBackToMainMenuScreen()
{
    cout << "\n\nPress any key to go back to main menu...";
    system("pause>0");
    system("cls");
    ViewMainMenuScreen();
}

void GoBackToTransactionMenuScreen()
{
    cout << "\n\nPress any key to go back to Transaction menu...";
    system("pause>0");
    system("cls");
    ViewTransacionsMenu();
}

void GOBackToManageUsersScreen()
{
    cout << "\n\nPress any key to go back to Manage Users menu....";
    system("pause>0");
    system("cls");
    ViewManageUsersMenu();
}

void DepositFunction(string AccountNumber, vector<stClient> &vClients, double Amount)
{
    char AreYouSure = 'N';
    cout << "\n\nAre you sure you want to perform this transaction? y/n ? ";
    cin >> AreYouSure;
    if (AreYouSure == 'Y' || AreYouSure == 'y')
    {
        for (stClient &c : vClients)
        {
            if (c.AccountNumber == AccountNumber)
            {
                c.AccountBalance += Amount;
                OverWriteClientsFileWithNewClientsList(vClients);
                cout << "\n\nTransaction has been done successfully to account number (";
                cout << AccountNumber << "), Accont new balance is " << c.AccountBalance << endl;
                break;
            }
        }
    }
}

void ShowDepositScreen()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tDeposit Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;
    stClient client;
    vector<stClient> vClietns = LoadClientsRecordFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();
    while (!FindClientByAccountNumber(AccountNumber, client, vClietns))
    {
        cout << "Client with Account Number (" << AccountNumber << ") is Not Found!\n";
        AccountNumber = ReadClientAccountNumber();
    }
    PrintClientCard(client);
    double Amount = 0;
    cout << "\nPlease enter diposit amount? ";
    cin >> Amount;
    DepositFunction(AccountNumber, vClietns, Amount);
}

void ShowClientsBalancesScreen()
{
    vector<stClient> vClients = LoadClientsRecordFromFile(ClientsFileName);
    system("cls");
    PrintClientsBalancesTable(vClients);
}

void ShowWithdrawScreen()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tWithdraw Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;

    stClient client;
    vector<stClient> vCleints = LoadClientsRecordFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    while (!FindClientByAccountNumber(AccountNumber, client, vCleints))
    {
        cout << "Client with Account Number (" << AccountNumber << ") is Not Found!\n";
        AccountNumber = ReadClientAccountNumber();
    }
    PrintClientCard(client);
    double Amount = 0;
    cout << "\nPleaseEnterWithdrawAmount? ";
    cin >> Amount;
    while (Amount > client.AccountBalance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : ";
        cout << client.AccountBalance << endl;
        cout << "\nPlease Enter Withdraw Amount? ";
        cin >> Amount;
    }
    DepositFunction(AccountNumber, vCleints, Amount * -1);
}

void PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersOptions)
{
    switch (ManageUsersOptions)
    {
    case enManageUsersMenuOptions::eListUsers:
        system("cls");
        ShowUsersListFunction();
        GOBackToManageUsersScreen();
        break;

    case enManageUsersMenuOptions::eAddNewUser:
        system("cls");
        ShowAddUserScreen();
        GOBackToManageUsersScreen();
        break;

    case enManageUsersMenuOptions::eDeleteUser:
        system("cls");
        ShowDeleteUsersScreen();
        GOBackToManageUsersScreen();
        break;

    case enManageUsersMenuOptions::eUpdateUser:
        system("cls");
        ShowEditUserScreen();
        GOBackToManageUsersScreen();
        break;

    case enManageUsersMenuOptions::eFindUser:
        system("cls");
        ShowFindUserScreen();
        GOBackToManageUsersScreen();
        break;

    default:
        system("cls");
        ViewMainMenuScreen();
        break;
    }
}

void PerformTransactionsMenuOption(enTransactionMenuOption TransactionOption)
{
    switch (TransactionOption)
    {
    case enTransactionMenuOption::eDeposite:
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionMenuScreen();
        break;

    case enTransactionMenuOption::eTotalBalances:
        system("cls");
        ShowClientsBalancesScreen();
        GoBackToTransactionMenuScreen();
        break;

    case enTransactionMenuOption::eWithdraw:
        system("cls");
        ShowWithdrawScreen();
        GoBackToTransactionMenuScreen();
        break;

    default:
        system("cls");
        ViewMainMenuScreen();
        break;
    }
}

void PerformMainMenuOption(enMainMenuOption MainMenuOption)
{
    switch (MainMenuOption)
    {
    case enMainMenuOption::eListClients:
        system("cls");
        ShowClientsListFunction();
        GoBackToMainMenuScreen();
        break;

    case enMainMenuOption::eAddNewClient:
        system("cls");
        ShowAddClientsScreen();
        GoBackToMainMenuScreen();
        break;

    case enMainMenuOption::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenuScreen();
        break;

    case enMainMenuOption::eUpdateClientInfo:
        system("cls");
        ShowEditClientScreen();
        GoBackToMainMenuScreen();
        break;

    case enMainMenuOption::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenuScreen();
        break;

    case enMainMenuOption::eTransactions:
        system("cls");
        ViewTransacionsMenu();
        GoBackToMainMenuScreen();
        break;

    case enMainMenuOption::eManageUsers:
        system("cls");
        ViewManageUsersMenu();
        GoBackToMainMenuScreen();
        break;

    default:
        system("cls");
        LoginScreen();
    }
}

void ViewMainMenuScreen()
{
    system("cls");
    cout << "=====================================================================\n";
    cout << right << setw(40) << "Main Menu Screen" << endl;
    cout << "=====================================================================\n";
    cout << "\t" << "[1] Show Client List." << endl;
    cout << "\t" << "[2] Add New Client." << endl;
    cout << "\t" << "[3] Delete Client." << endl;
    cout << "\t" << "[4] Update Client Info." << endl;
    cout << "\t" << "[5] Find Client." << endl;
    cout << "\t" << "[6] Transactions." << endl;
    cout << "\t" << "[7] Manage Users." << endl;
    cout << "\t" << "[8] Logout." << endl;
    cout << "=====================================================================\n";
    PerformMainMenuOption((enMainMenuOption)ChooseWhatToDoFromMainMenu());
}

void ViewTransacionsMenu()
{
    if (!CheckAccessPermissions(eMainMenuPermissions::pTransactions))
    {
        ShowAccessDeniedScreen();
        GoBackToMainMenuScreen();
        return;
    }

    cout << "=====================================================================\n";
    cout << right << setw(40) << "Transactions Menu Screen" << endl;
    cout << "=====================================================================\n";
    cout << "\t" << "[1] Deposit." << endl;
    cout << "\t" << "[2] Withdraw." << endl;
    cout << "\t" << "[3] Total Balances." << endl;
    cout << "\t" << "[4] Main Menu." << endl;
    cout << "=====================================================================\n";
    PerformTransactionsMenuOption((enTransactionMenuOption)ChooseWhatToDoFromTransactionsMenu());
}

void ViewManageUsersMenu()
{
    if (!CheckAccessPermissions(eMainMenuPermissions::pManageUsers))
    {
        ShowAccessDeniedScreen();
        return;
    }

    cout << "=====================================================================\n";
    cout << right << setw(40) << "Manage Users Menu Screen" << endl;
    cout << "=====================================================================\n";
    cout << "\t" << "[1] User's List." << endl;
    cout << "\t" << "[2] Add New User." << endl;
    cout << "\t" << "[3] Delete User." << endl;
    cout << "\t" << "[4] Update User." << endl;
    cout << "\t" << "[5] Find User." << endl;
    cout << "\t" << "[6] Main Menu." << endl;
    cout << "=====================================================================\n";
    PerformManageUsersMenuOption((enManageUsersMenuOptions)ChooseWhatToDoFromManageUsersMenu());
}

int main()
{
    LoginScreen();
    return 0;
}