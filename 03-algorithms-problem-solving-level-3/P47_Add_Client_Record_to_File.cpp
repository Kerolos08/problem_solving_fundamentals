#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
const string FileName = "ClientsData.txt";

struct stClient 
{
    string AccNumber;
    string PinCode;
    string ClientName;
    string PhoneNumber;
    double Balance;
};

stClient ReadClient ()
{
    stClient NewClient;
    cout << "Enter Account Number? ";
    getline (cin >> ws, NewClient.AccNumber);
    cout << "Enter PinCode? ";
    getline (cin, NewClient.PinCode);
    cout << "Enter Name? ";
    getline (cin, NewClient.ClientName);
    cout << "Enter Phone Number? ";
    getline (cin, NewClient.PhoneNumber);
    cout << "Enter Account Balance? ";
    cin >> NewClient.Balance;
    return NewClient;
}

string ConvertRecordToLine (stClient newclient)
{
    string Delim = "#//#";
    string LineRec = "";
    LineRec += newclient.AccNumber + Delim;
    LineRec += newclient.PinCode + Delim;
    LineRec += newclient.ClientName + Delim;
    LineRec += newclient.PhoneNumber + Delim;
    LineRec += to_string(newclient.Balance);
    return LineRec;
}

void AddClientToFile (string LineRec, string FileName)
{
    fstream Myfile;
    Myfile.open(FileName, ios::out | ios::app);
    if (Myfile.is_open())
    {
        Myfile << LineRec << endl;
        Myfile.close();
    }
}

void AddNewClient ()
{
    stClient newClient;
    newClient = ReadClient();
    AddClientToFile(ConvertRecordToLine(newClient), FileName);
}

void AddClients ()
{
    char AddMore = 'y';
    do{
        system ("cls");
        cout << "\nAdding New Client: \n" << endl;
        AddNewClient();
        cout << "\n";
        cout << "Client Added Successfully, do you want to add more? y/n" << endl;
        cin >> AddMore;
    }while (tolower(AddMore) == 'y');
}

int main ()
{
    AddClients();
    return 0;
}

