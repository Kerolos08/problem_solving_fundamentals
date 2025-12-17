#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDate
{
    short Day;
    short Month;
    short Year;
};

string ReadString(string msg)
{
    string Date;
    cout << msg;
    getline(cin >> ws, Date);
    return Date;
};

vector<string> ConvertStringDateToVector(string Date)
{
    vector<string> vDate;
    string Delim = "/";
    short Pos = 0;
    string sword;
    while ((Pos = Date.find(Delim)) != std::string::npos)
    {
        sword = Date.substr(0, Pos);
        if (sword != " ")
        {
            vDate.push_back(sword);
        }
        Date.erase(0, Pos + Delim.length());
    }
    if (Date != "")
    {
        vDate.push_back(Date);
    }

    return vDate;
}

stDate ConvertStringDateToStruct(string SDate)
{
    vector<string> vDate = ConvertStringDateToVector(SDate);
    stDate Date;
    Date.Day = stoi(vDate.at(0));
    Date.Month = stoi(vDate.at(1));
    Date.Year = stoi(vDate.at(2));
    return Date;
}

string ConvertStructDateToSTring(stDate Date)
{
    return (to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year));
}

int main()
{
    string sDate = ReadString("\n\nPlease Enter Date dd/mm/yyyy? ");
    stDate STDate = ConvertStringDateToStruct(sDate);

    cout << "\nDay:" << STDate.Day << endl;
    cout << "Month:" << STDate.Month << endl;
    cout << "Year:" << STDate.Year << endl;

    cout << "\n\nYou Entered: " << ConvertStructDateToSTring(STDate) << endl;

    return 0;
}