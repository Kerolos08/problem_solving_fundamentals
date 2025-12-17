#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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

bool FindClientByAccountNumber(stClient &client, string ReqAccNumber)
{
    vector<stClient> vClients = LoadClientsDataToVector(FileName);
    for (stClient &c : vClients)
    {
        if (c.AccNumber == ReqAccNumber)
        {
            client = c;
            return true;
        }
    }
    return false;
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

int main()
{
    stClient client;
    string AccountNumber = ReadString("Please Enter Account Number? ");
    if (FindClientByAccountNumber(client, AccountNumber))
    {
        PrintClientCard(client);
    }
    else
    {
        cout << "\nCleint with Account Number (" << AccountNumber << ") Not Found!";
    }
    return 0;
}