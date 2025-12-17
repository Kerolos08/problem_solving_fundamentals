#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClientData
{
    string AccNumber;
    string Pincode;
    string Name;
    string PhoneNum;
    double AccBalance;
};

vector<string> SplitFunction(string text)
{
    vector<string> FinalString;
    string Delimiter = "#//#";
    string Sword;
    short Pos = 0;
    while ((Pos = text.find(Delimiter)) != std::string::npos)
    {
        Sword = text.substr(0, Pos);
        if (Sword != " ")
        {
            FinalString.push_back(Sword);
        }
        text.erase(0, Pos + Delimiter.length());
    }
    if (text != "")
    {
        FinalString.push_back(text);
    }
    return FinalString;
}

stClientData ConvertLineToRecord (string Line)
{
    vector <string> vClient = SplitFunction(Line);
    stClientData Client;
    Client.AccNumber = vClient.at(0);
    Client.Pincode = vClient.at(1);
    Client.Name = vClient.at(2);
    Client.PhoneNum = vClient.at(3);
    Client.AccBalance = stod(vClient.at(4));
    return Client;
}

void PrintClientStructure (stClientData Client)
{
    cout << "The following is the extracted client record: \n" << endl;
    cout << "Account Number: " << Client.AccNumber << endl;
    cout << "Pin Code      : " << Client.Pincode << endl;
    cout << "Name          : " << Client.Name << endl;
    cout << "Phone         : " << Client.PhoneNum << endl;
    cout << "Account Balance: " << fixed << Client.AccBalance << endl;
}

int main ()
{
    string Record = "A120#//#1235#//#KerolosHany#//#01555404182#//#4000000";
    stClientData Client = ConvertLineToRecord(Record);
    cout << "Line Record is:" << endl;
    cout << Record << endl;
    cout << "\n";
    PrintClientStructure(Client);
    return 0;
}