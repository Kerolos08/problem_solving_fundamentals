#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

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

vector <string> SplitString (string text)       // ** function used to save each string between delimiters into vector
{
    vector <string> vString;
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
    if (text != "")
    {
        vString.push_back(text);
    }
    return vString;
}

stClient ConvertLineIntoRec (string text)         // ** converting the data in the vector into a structure of data
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

vector <stClient> LoadClientsFromFile (string FileName)
{
    vector <stClient> vClients;
    fstream MyFile;
    
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        stClient client;
        string Line;
        while (getline(MyFile, Line))
        {
            client = ConvertLineIntoRec(Line);
            vClients.push_back(client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientData (stClient client)
{
    cout << "| " << left << setw(14) << client.AccNumber;
    cout << "| " << left << setw(9) << client.PinCode;
    cout << "| " << left << setw(37) << client.ClientName;
    cout << "| " << left << setw(14) << client.PhoneNumber;
    cout << "| " << left << setw(12) << fixed << client.Balance;
    cout << "\n";
}

void PrintAllClientsRecord (vector <stClient> vClients)
{
    cout << "\n\t\t\t\t\t Client List (" << vClients.size() << ") Client(s).";
    cout << "\n________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(14) << "Account Number";
    cout << "| " << left << setw(9) << "Pin code";
    cout << "| " << left << setw(37) << "Client Name";
    cout << "| " << left << setw(14) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n________________________________________________________________________________________________\n\n";
    for (stClient c: vClients)
    {
        PrintClientData(c);
    }
}

int main ()
{
    vector <stClient> vClients = LoadClientsFromFile(FileName);
    PrintAllClientsRecord(vClients);
    return 0;
}
