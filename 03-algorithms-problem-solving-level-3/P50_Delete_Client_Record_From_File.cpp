#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "StringFunctions.h"

using namespace std;
using namespace Read;
const string FileName = "ClientsData.txt";

struct stClient
{
    string AccNumber;
    string PinCode;
    string ClientName;
    string PhoneNumber;
    double Balance;
    bool MarkedForDelete = false;
};

vector<string> SplitString(string text) // ** function used to save each string between delimiters into vector
{
    vector<string> vString;
    string Delim = "#//#";
    short pos = 0;
    string Sword;
    while ((pos = text.find(Delim)) != std::string::npos)
    {
        Sword = text.substr(0, pos);
        if (Sword != " ")
        {
            vString.push_back(Sword);
        }
        text.erase(0, pos + Delim.length());
    }
    if (Sword != "")
    {
        vString.push_back(Sword);
    }
    return vString;
}

stClient ConvertLineIntoRec(string text) // ** converting the data in the vector into a structure of data
{
    stClient client;
    vector vString = SplitString(text);
    client.AccNumber = vString.at(0);
    client.PinCode = vString.at(1);
    client.ClientName = vString.at(2);
    client.PhoneNumber = vString.at(3);
    client.Balance = stod(vString.at(4));
    return client;
}

vector<stClient> LoadClientsDataToVector(string FileName)
{
    vector<stClient> Clients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        stClient client;
        while (getline(MyFile, Line))
        {
            client = ConvertLineIntoRec(Line);
            Clients.push_back(client);
        }
        MyFile.close();
    }
    return Clients;
}

bool FindClientInList(vector<stClient> vClients, stClient &client, string AccountNumber)
{
    for (stClient c : vClients)
    {
        if (c.AccNumber == AccountNumber)
        {
            client = c;
            return true;
        }
    }
    return false;
}

void MarkForDelete(vector<stClient> &vClients, string AccountNumber)
{
    for (stClient &c : vClients)
    {
        if (c.AccNumber == AccountNumber)
        {
            c.MarkedForDelete = true;
        }
    }
}

void PrintClientCard(stClient client)
{
    cout << "\nThe following are the client details:" << endl;
    cout << "Account Number: " << client.AccNumber << endl;
    cout << "Pin Code      : " << client.PinCode << endl;
    cout << "Client Name   : " << client.ClientName << endl;
    cout << "Phone Number  : " << client.PhoneNumber << endl;
    cout << "Account Balance: " << fixed << client.Balance << endl;
}

string ConvertRecordToLine(stClient newclient)
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

void OverWriteFileWithUpdatedData(vector<stClient> vClients, string FileName)
{
    string Line;
    fstream MyFile;
    MyFile.open(FileName, ios::out); // ** overwrite the file only
    if (MyFile.is_open())
    {
        for (stClient &c : vClients)
        {
            if (c.MarkedForDelete == false)
            {
                Line = ConvertRecordToLine(c);
                MyFile << Line << endl;
            }
        }
    }
    MyFile.close();
}

void DeleteClientFromList(string FileName, vector<stClient> &vClients)
{
    stClient client;
    string AccountNumber = ReadString("Please Enter Account Number? ");
    char Answer = 'N';
    if (FindClientInList(vClients, client, AccountNumber))
    {
        PrintClientCard(client);
        cout << "\nAre you sure you want to delete this client data? Y/N? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            MarkForDelete(vClients, AccountNumber);
            OverWriteFileWithUpdatedData(vClients, FileName);
            vClients = LoadClientsDataToVector(FileName); // ** update the vector
            cout << "\nClient data deleted successfully";
        }
    }
    else
    {
        cout << "\nCleint with Account Number (" << AccountNumber << ") Not Found!";
    }
}

int main ()
{
    vector <stClient> vClients = LoadClientsDataToVector(FileName);
    DeleteClientFromList(FileName, vClients);
    return 0;
}