#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

const string FileName = "ClientsData.txt";

enum enActions
{
    ShowClientList = 1,
    AddNewClient = 2,
    DeleteClient = 3,
    UpdateClientInfo = 4,
    FindClient = 5,
    Exit = 6
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
    for (stClient c : vClients)
    {
        PrintCliet(c);
    }
    cout << "\n\n\n\n\n\n\n\n";
    cout << "________________________________________________________________________________________________\n";
}

bool DoesClientExist(string ReqAccNumber)
{
    vector<stClient> vClients = LoadClientsRecordFromFile(FileName);
    for (stClient &c : vClients)
    {
        if (c.AccountNumber == ReqAccNumber)
        {
            return true;
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

stClient ReadClient(string FileName)
{
    stClient client;
    string ReqAccNum = ReadClientAccountNumber();
    cout << "\n";
    while (DoesClientExist(ReqAccNum))
    {
        cout << "Client With Account Number (" << ReqAccNum;
        cout << ") Already Exists, Enter Another Account Number? ";
        getline(cin >> ws, ReqAccNum);
    }
    client.AccountNumber = ReqAccNum;
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
    stClient client = ReadClient(FileName);
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

enActions ReadWhatUserWantToDo()
{
    short Num = 0;
    do
    {
        cout << "Choose what do you want to do? [1 to 6]? ";
        cin >> Num;
    } while (Num < 1 || Num > 6);
    return (enActions)Num;
}

void PrintMainMenuScreen()
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
}

bool ShowClientsListFunction(string FileName)
{
    char Return;
    vector<stClient> vClients = LoadClientsRecordFromFile(FileName);
    system("cls");
    PrintClientsTable(vClients);
    cout << "Press any key to go back to Main Menu...";
    cin >> Return;
    return true;
}

bool AddClientsFunction(string FileName)
{
    char Return;
    string AccountNumber;
    char AddMore = 'Y';
    do
    {
        system("cls");
        cout << "-------------------------------------------------------------" << endl;
        cout << "\t\tAdd New Client Screen" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Adding New Client:" << endl;
        AddClientDataToFile(FileName);
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    } while (towupper(AddMore) == 'Y');
    cout << "Press any key to go back to Main Menu...";
    cin >> Return;
    return true;
}

bool DeleteClientFunction(string FileName)
{
    char Return;
    vector<stClient> vClients = LoadClientsRecordFromFile(FileName);
    stClient client;
    char AreYouSure = 'N';
    system("cls");
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tDelete Client Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;
    string AccountNumber = ReadClientAccountNumber();
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
    cout << "Press any key to go back to main menu...";
    cin >> Return;
    return true;
}

bool EditClientFunction(string FileName)
{
    vector<stClient> vClients = LoadClientsRecordFromFile(FileName);
    stClient client;
    char Return;
    char AreYouSure = 'N';
    system("cls");
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tUpdate Client Info Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;
    string AccountNumber = ReadClientAccountNumber();
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
    cout << "Press any key to go back to main menu...";
    cin >> Return;
    return true;
}

bool FindClientFunction (string FileName)
{
    char Return;
    vector <stClient> vClients = LoadClientsRecordFromFile(FileName);
    stClient client;
    system("cls");
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tFind Client Screen" << endl;
    cout << "-------------------------------------------------------------" << endl;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, client, vClients))
    {
        PrintClientCard(client);
    }
    else
    {
        cout << "Client with Account Number (" << AccountNumber << ") is Not Found!\n";
    }
    cout << "\n\nPress any key to go back to main menu...";
    cin >> Return;
    return true;
}

bool ExitProgram ()
{
    system("cls");
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\tProgram Ends :-)" << endl;
    cout << "-------------------------------------------------------------" << endl;
    return false;
}

void LunchBankApp(string FileName)
{
    bool ReturnToMainMenu = true;
    do
    {
        system("cls");
        PrintMainMenuScreen();
        enActions action = ReadWhatUserWantToDo(); // ** i can use the function as an expression
        switch (action)
        {

        case enActions::ShowClientList:
            ReturnToMainMenu = ShowClientsListFunction(FileName);
            break;

        case enActions::AddNewClient:
            ReturnToMainMenu = AddClientsFunction(FileName);
            break;

        case enActions::DeleteClient:
            ReturnToMainMenu = DeleteClientFunction(FileName);
            break;

        case enActions::UpdateClientInfo:
            ReturnToMainMenu = EditClientFunction(FileName);
            break;


        case enActions::FindClient:
            ReturnToMainMenu = FindClientFunction(FileName);
            break;

        default:
            ReturnToMainMenu = ExitProgram();
        }

    } while (ReturnToMainMenu);
}

int main()
{
    LunchBankApp(FileName);
    return 0;
}