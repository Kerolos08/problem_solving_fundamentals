#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

enum enMainMenuOption
{
    eQuickWithdraw = 1,
    eNormalWithdraw = 2,
    eDeposite = 3,
    eCheckBalance = 4,
    eLogout = 5
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
stClient ActiveClient;

vector<string> SplitFunction(string Text);

stClient ConvertClientLineRecord(string Line);

string ConvertClientRecordToLine(stClient client);

vector<stClient> LoadClientsRecordFromFile(string FileName);

short ReadWhatToDoFromMainMenu();

short ReadWhatToDoFromQuickWithdrawMenu();

short GetQuickWithdrawAmount(short Option);

void DepositeFunction(double Amount, vector<stClient> &vClients);

void OverWriteClientsFileWithNewClientsList(vector<stClient> vClients);

bool DoesClientExist(string AccountNumber, string FileName);

void PerformMainMenuOption(enMainMenuOption Option);

void PerformQuickWithdrawMenuOption(short Option);

void PerformNormalWithdrawFunction();

void PerformDepositeFunction ();

void ShowMainMenuScreen();

void ShowGoBackToMainMenuScreen();

void ShowQuickWithdrawScreen();

void ShowNormalWithdrawScreen();

void ShowDepositeScreen();

void ShowCheckBalanceScreen();

void LoginScreen();

void ShowGoBackToMainMenuScreen();

int main()
{
    LoginScreen();
    return 0;
}

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

bool FindClientByAccountNumberAndPincode(string AccountNumber, string Pin, stClient &Client)
{
    vector<stClient> vClients = LoadClientsRecordFromFile(ClientsFileName);
    for (stClient &c : vClients)
    {
        if (c.AccountNumber == AccountNumber && c.PinCode == Pin)
        {
            Client = c;
            return true;
        }
    }
    return false;
}

bool LoadClientData(string AccountNumber, string Pin)
{
    if (FindClientByAccountNumberAndPincode(AccountNumber, Pin, ActiveClient))
        return true;
    else
        return false;
}

short ReadWhatToDoFromMainMenu()
{
    short Number = 0;
    do
    {
        cout << "Choose what do you want to do? [1 to 5]? ";
        cin >> Number;
    } while (Number < 1 || Number > 5);
    return Number;
}

short ReadWhatToDoFromQuickWithdrawMenu()
{
    short Number = 0;
    do
    {
        cout << "Choose what to withdraw from [1] to [8] ? ";
        cin >> Number;
    } while (Number < 1 || Number > 9);
    return Number;
}

int ReadWithdrawBalance()
{
    int Amount;
    cout << "\nEnter an amount multiple of 5's? ";

    cin >> Amount;

    while (Amount % 5 != 0)
    {
        "\nEnter an amount multiple of 5's? ";
        cin >> Amount;
    }

    return Amount;
}

double ReadDepositeAmount ()
{
    double Amount;
    cout << "\nEnter a positive Deposit Amount? ";

    cin >> Amount;

    while (Amount <= 0)
    {
        "\nEnter a positive Deposit Amount? ";
        cin >> Amount;
    }

    return Amount;
}

short GetQuickWithdrawAmount(short Option)
{
    switch (Option)
    {
    case 1:
        return 20;

    case 2:
        return 50;

    case 3:
        return 100;

    case 4:
        return 200;

    case 5:
        return 400;

    case 6:
        return 600;

    case 7:
        return 800;

    case 8:
        return 1000;

    default:
        return 0;
    }
}

void DepositeFunction(double Amount, vector<stClient> &vClients)
{
    char AreYouSure = 'N';
    cout << "\nAre you want to perform this transaction? y/n? ";
    cin >> AreYouSure;
    if (AreYouSure == 'y' || AreYouSure == 'Y')
    {
        for (stClient &c : vClients)
        {
            if (ActiveClient.AccountNumber == c.AccountNumber)
            {
                c.AccountBalance += Amount;
                OverWriteClientsFileWithNewClientsList(vClients);
                ActiveClient = c;
                cout << "\nDone successfully. New balance is " << ActiveClient.AccountBalance;
                break;
            }
        }
    }
}

void PerformQuickWithdrawMenuOption(short Option)
{
    if (Option == 9)
        return;

    short WithdrawBalance = GetQuickWithdrawAmount(Option);

    if (WithdrawBalance > ActiveClient.AccountBalance)
    {
        cout << "\nThe amount exceeds your balance, make another choice.\n";
        cout << "Press any key to continue...";
        system("pause>0");
        ShowQuickWithdrawScreen();
        return;
    }

    vector<stClient> vClients = LoadClientsRecordFromFile(ClientsFileName);
    DepositeFunction(WithdrawBalance * -1, vClients);
}

void PerformNormalWithdrawFunction()
{
    int WithdrawBalance = ReadWithdrawBalance();

    if (WithdrawBalance > ActiveClient.AccountBalance)
    {
        cout << "\nThe amount exceeds your balance, make another choice.\n";
        cout << "Press any key to continue...";
        system("pause>0");
        ShowMainMenuScreen();
        return;
    }

    vector<stClient> vClients = LoadClientsRecordFromFile(ClientsFileName);
    DepositeFunction(WithdrawBalance * -1, vClients);
}

void ShowNormalWithdrawScreen()
{
    cout << "======================================================================\n";
    cout << right << setw(40) << "Normal Withdraw Screen" << endl;
    cout << "======================================================================\n";

    PerformNormalWithdrawFunction();
}

void PerformDepositeFunction ()
{
    vector<stClient> vClients = LoadClientsRecordFromFile(ClientsFileName);
    double Amount = ReadDepositeAmount();
    DepositeFunction(Amount, vClients);
}

void ShowDepositeScreen()
{
    cout << "======================================================================\n";
    cout << right << setw(40) << "Deposite Screen" << endl;
    cout << "======================================================================\n";
    PerformDepositeFunction ();
}

void ShowCheckBalanceScreen()
{
    cout << "======================================================================\n";
    cout << right << setw(40) << "Check Balance Screen" << endl;
    cout << "======================================================================\n";

    cout << "\nYour Balance is " << ActiveClient.AccountBalance << endl;
}

void PerformMainMenuOption(enMainMenuOption Option)
{
    switch (Option)
    {
    case enMainMenuOption::eQuickWithdraw:
        system("cls");
        ShowQuickWithdrawScreen();
        ShowGoBackToMainMenuScreen();
        break;

    case enMainMenuOption::eNormalWithdraw:
        system("cls");
        ShowNormalWithdrawScreen();
        ShowGoBackToMainMenuScreen();
        break;

    case enMainMenuOption::eDeposite:
        system("cls");
        ShowDepositeScreen();
        ShowGoBackToMainMenuScreen();
        break;

    case enMainMenuOption::eCheckBalance:
        system("cls");
        ShowCheckBalanceScreen();
        ShowGoBackToMainMenuScreen();
        break;

    default:
        system("cls");
        LoginScreen();
        break;
    }
}

void LoginScreen()
{
    bool LoginFailed = false;
    string AccountNumber, Pincode;
    do
    {
        system("cls");
        cout << "-------------------------------------------------------------" << endl;
        cout << "\t\tLogin Screen" << endl;
        cout << "-------------------------------------------------------------" << endl;
        if (LoginFailed)
        {
            cout << "\nInvalid Account Number / PinCode\n";
        }

        cout << "Enter Account Number? ";
        cin >> AccountNumber;

        cout << "Enter Pin? ";
        cin >> Pincode;

        LoginFailed = !(LoadClientData(AccountNumber, Pincode));
    } while (LoginFailed);

    ShowMainMenuScreen();
}

void ShowGoBackToMainMenuScreen()
{
    cout << "\n\nPress any key to go back main menu...";
    system("pause>0");
    system("cls");
    ShowMainMenuScreen();
}

void ShowQuickWithdrawScreen()
{
    system("cls");
    cout << "======================================================================\n";
    cout << right << setw(40) << "Quick Withdraw Screen" << endl;
    cout << "======================================================================\n";
    cout << "\t" << "[1] 20";
    cout << "\t\t" << "[2] 50" << endl;
    cout << "\t" << "[3] 100";
    cout << "\t\t" << "[4] 200" << endl;
    cout << "\t" << "[5] 400";
    cout << "\t\t" << "[6] 600" << endl;
    cout << "\t" << "[7] 800";
    cout << "\t\t" << "[8] 1000" << endl;
    cout << "\t" << "[9] Exit" << endl;
    cout << "======================================================================\n";
    cout << "Your Balance is " << ActiveClient.AccountBalance << endl;
    PerformQuickWithdrawMenuOption(ReadWhatToDoFromQuickWithdrawMenu());
}

void ShowMainMenuScreen()
{
    system("cls");
    cout << "======================================================================\n";
    cout << right << setw(40) << "ATM Main Menu Screen" << endl;
    cout << "======================================================================\n";
    cout << "\t" << "[1] Quick Withdraw." << endl;
    cout << "\t" << "[2] Normal Withdraw." << endl;
    cout << "\t" << "[3] Deposit." << endl;
    cout << "\t" << "[4] Check Balance." << endl;
    cout << "\t" << "[5] Login." << endl;
    cout << "======================================================================\n";
    PerformMainMenuOption((enMainMenuOption)ReadWhatToDoFromMainMenu());
}