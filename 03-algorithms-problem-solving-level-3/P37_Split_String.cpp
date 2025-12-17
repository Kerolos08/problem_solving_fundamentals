#include <iostream>
#include <string>
#include <vector>
#include "StringFunctions.h"
using namespace std;
using namespace Read;

vector<string> SplitString(string Text, string Delimiter)
{
    vector<string> Results;
    short Pos = 0;
    string Sword;
    while ((Pos = Text.find(Delimiter)) != std ::string ::npos)
    {
        Sword = Text.substr(0, Pos);
        if (Sword != " ")
        {
            Results.push_back(Sword);
        }
        Text.erase(0, Pos + Delimiter.length()); /* // ! Delimiter.length() making the function generic
                                                       * as we can change the delimiter to ant thing with any length */
    }
    if (Text != "")
    {
        Results.push_back(Text);
    }
    return Results;
}

void PrintVector(vector<string> &vText)
{
    cout << "Tokens = " << vText.size() << endl;
    for (string &s : vText)
    {
        cout << s << endl;
    }
}

int main()
{
    string Text = ReadString("Please Enter Your String\n");
    cout << endl;
    string Delimiter = " ";
    vector<string> vResults = SplitString(Text, Delimiter);
    PrintVector(vResults);
    return 0;
}