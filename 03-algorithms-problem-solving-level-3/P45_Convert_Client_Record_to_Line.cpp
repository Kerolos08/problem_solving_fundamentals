#include <iostream>
#include <string>
#include "StringFunctions.h"
using namespace std;
using namespace Read;

double ReadNumber (string msg)
{
    double number;
    cout << msg;
    cin >> number;
    return number;
}

struct stClientData
{
    string AccNumber;
    string Pincode;
    string Name;
    string PhoneNum;
    double AccBalance;
};

stClientData ReadClientData ()
{
    stClientData ClientData;
    ClientData.AccNumber = ReadString("Enter Account Number? ");
    ClientData.Pincode = ReadString("Enter Pincode? ");
    ClientData.Name = ReadString("Enter Name? ");
    ClientData.PhoneNum = ReadString("Enter Phone Number? ");
    ClientData.AccBalance = ReadNumber("Enter Account Balance? ");
    return ClientData;
}

string ConvertClientDataToOnelineString (stClientData ClientData)
{
    string Delim = "#//#";
    string ClientRecord = "";
    ClientRecord += ClientData.AccNumber + Delim;
    ClientRecord += ClientData.Pincode + Delim;
    ClientRecord += ClientData.Name + Delim;
    ClientRecord += ClientData.PhoneNum + Delim;
    ClientRecord += to_string(ClientData.AccBalance); 
    return ClientRecord;
}

int main ()
{
    stClientData ClientData = ReadClientData();
    cout << "\n\n" << endl;
    cout << "Client Record for saving is:" << endl;
    cout << ConvertClientDataToOnelineString(ClientData);
    return 0;
}