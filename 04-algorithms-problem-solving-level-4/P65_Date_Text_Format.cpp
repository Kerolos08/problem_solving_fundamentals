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

string ReplaceWordInStringUsingBilltInFunction(string text, string WordToReplace, string ReplaceTo)
{
    short Pos = text.find(WordToReplace);
    while (Pos != std::string::npos)
    {
        text.replace(Pos, WordToReplace.length(), ReplaceTo);
        Pos = text.find(WordToReplace);
    }
    return text;
}

string FormatDate (stDate Date, string Text = "dd/mm/yyyy")
{
    string FormatedDate = "";
    FormatedDate = ReplaceWordInStringUsingBilltInFunction(Text, "dd", to_string(Date.Day));
    FormatedDate = ReplaceWordInStringUsingBilltInFunction(FormatedDate, "mm", to_string(Date.Month));
    FormatedDate = ReplaceWordInStringUsingBilltInFunction(FormatedDate, "yyyy", to_string(Date.Year));
    return FormatedDate;
}

int main()
{
    string sDate = ReadString("\n\nPlease Enter Date dd/mm/yyyy? ");
    stDate STDate = ConvertStringDateToStruct(sDate);

    cout << FormatDate(STDate) << endl;
    cout << FormatDate(STDate, "yyyy/dd/mm") << endl;
    cout << FormatDate(STDate, "mm/yyyy/dd") << endl;
    cout << FormatDate(STDate, "mm-yyyy-dd") << endl;
    cout << FormatDate(STDate, "dd/mm/yyyy") << endl;
    cout << FormatDate(STDate, "Day:dd, Month:mm, Year:yyyy") << endl;
    return 0;
}