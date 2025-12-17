#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;
const string FileName = "ClientsData.txt";

enum enMainMenuOption
{
    eListClients = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClientInfo = 4,
    eFindClient = 5,
    eExit = 6
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

stClient ConvertLineRecord(string Line)
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
            client = ConvertLineRecord(Line);
            vClients.push_back(client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintCliet(stClient client)
{
    cout << "| " << setw(15) << client.AccountNumber;
    cout << "| " << setw(9) << client.PinCode;
    cout << "| " << setw(35) << client.ClientName;
    cout << "| " << setw(14) << client.PhoneNumber;
    cout << "| " << setw(12) << fixed << client.AccountBalance;
    cout << "\n";
}

void PrintClientsTable(vector<stClient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(14) << "Account Number";
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
    cout << "\n\n\n\n\n\n\n\n";
    cout << "________________________________________________________________________________________________\n";
    }
}

bool DoesClientExist(string AccountNumber, string FileName)
{
    vector<stClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        stClient client;
        while (getline(MyFile, Line))
        {
            client = ConvertLineRecord(Line);
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

string ConvertRecordToLine(stClient client)
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

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

stClient ReadNewClient()
{
    stClient client;
    cout << "Enter Account Number? ";
    getline(cin >> ws, client.AccountNumber);
    while (DoesClientExist(client.AccountNumber, FileName))
    {
        cout << "Client With Account Number (" << client.AccountNumber;
        cout << ") Already Exists, Enter Another Account Number? ";
        getline(cin >> ws, client.AccountNumber);
    }
    cout << "Enter PinCode? ";
    getline(cin >> ws, client.PinCode);
    cout << "Enter Name? ";
    getline(cin, client.ClientName);
    cout << "Enter Phone Number? ";
    getline(cin, client.PhoneNumber);
    cout << "Enter Account Balance? ";
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

void MarkForDelete(vector<stClient> &vClients, string AccountNumber)
{
    for (stClient &c : vClients)
    {
        if (c.AccountNumber == AccountNumber)
        {
            c.MarkForDelete = true;
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

void AddClientDataToFile(string FileName)
{
    stClient client = ReadNewClient();
    string LineRec = ConvertRecordToLine(client);
    fstream Myfile;
    Myfile.open(FileName, ios::out | ios::app);
    if (Myfile.is_open())
    {
        Myfile << LineRec << endl;
        Myfile.close();
    }
}

void OverWriteFileWithNewClientsList(vector<stClient> vClients)
{
    string Line;
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (stClient &c : vClients)
        {
            if (!c.MarkForDelete)
            {
                Line = ConvertRecordToLine(c);
                MyFile << Line << endl;
            }
        }
        MyFile.close();
    }
}

void ViewMainMenuScreen();

short ChooseWhatToDoFromMainMenu()
{
    short Num = 0;
    do
    {
        cout << "Choose what do you want to do? [1 to 6]? ";
        cin >> Num;
    } while (Num < 1 || Num > 6);
    return Num;
}

void ShowClientsListFunction()
{
    vector<stClient> vClients = LoadClientsRecordFromFile(FileName);
    system("cls");
    PrintClientsTable(vClients);
}

void AddClients()
{
    string AccountNumber;
    char AddMore = 'Y';
    do
    {
        cout << "Adding New Client:\n" << endl;
        AddClientDataToFile(FileName);
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    } while (towupper(AddMore) == 'Y');
}

void ShowAddClientsScreen()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tAdd New Client Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;
    AddClients();
}

void DeleteClient (string AccountNumber, vector <stClient> &vClients)
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
            MarkForDelete(vClients, AccountNumber);
            OverWriteFileWithNewClientsList(vClients);
            cout << "\nClient Deleted Successfully.\n" << endl;
        }
    }
    else
    {
        cout << "Client with Account Number (" << AccountNumber << ") is Not Found!\n";
    }
}

void ShowDeleteClientScreen()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tDelete Client Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;

    vector<stClient> vClients = LoadClientsRecordFromFile(FileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClient(AccountNumber, vClients);
}

void UpdateClient (string AccountNumber, vector <stClient> &vClients)
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
            OverWriteFileWithNewClientsList(vClients);
            cout << "\n\nSelected client data updated successfully.\n" << endl;
        }
    }
    else
    {
        cout << "Client with Account Number (" << AccountNumber << ") is Not Found!\n";
    }
}

void ShowEditClientScreen()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tUpdate Client Info Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;

    vector<stClient> vClients = LoadClientsRecordFromFile(FileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClient(AccountNumber, vClients);
}

void ShowFindClientScreen ()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tFind Client Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;

    vector <stClient> vClients = LoadClientsRecordFromFile(FileName);
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

void ShowExitProgramScreen ()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tProgram Ends :-)" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void GoBackToMainMenuScreen ()
{
    cout << "\n\nPress any key to go back to main menu...";
    system ("pause>0");
    system("cls");
    ViewMainMenuScreen();
}

void PerformMainMenuOption (enMainMenuOption MainMenuOption)
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

        default:
            system("cls");
            ShowExitProgramScreen();
        }
}

void ViewMainMenuScreen()
{
    cout << "=====================================================================\n";
    cout << right << setw(40) << "Main Menu Screen" << endl;
    cout << "=====================================================================\n";
    cout << "\t" << "[1] Show Client List." << endl;
    cout << "\t" << "[2] Add New Client." << endl;
    cout << "\t" << "[3] Delete Client." << endl;
    cout << "\t" << "[4] Update Client Info." << endl;
    cout << "\t" << "[5] Find Client." << endl;
    cout << "\t" << "[6] Exit." << endl;
    cout << "=====================================================================\n";
    PerformMainMenuOption((enMainMenuOption)ChooseWhatToDoFromMainMenu());
}

int main()
{
    ViewMainMenuScreen();
    return 0;
}