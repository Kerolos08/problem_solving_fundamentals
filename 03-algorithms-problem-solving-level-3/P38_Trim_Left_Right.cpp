#include <iostream>
#include <string>
#include "StringFunctions.h"
using namespace std;
using namespace Read;

string Trim_Left (string Text)
{
    for (int i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ')
        {
            Text = Text.substr(i, Text.length() - 1);
            return Text;
        }
    }
    return "";
}

string Trim_Right (string Text)
{
    for (int i = Text.length() - 1; i >= 0; i--)
    {
        if (Text[i] != ' ')
        {
            Text = Text.substr(0, i + 1);
            return Text;
        }
    }
    return "";
}

string Trim (string Text)
{
    return Trim_Left(Trim_Right(Text));
}

int main ()
{
    string S1 = "       This Is A Test For The Function          ";
    cout << "String    = " << S1 << endl;
    cout << "\nTrim Left  = " << Trim_Left(S1) << endl;
    cout << "Trim Right = " << Trim_Right(S1) << endl;
    cout << "Trim       = " << Trim(S1) << endl;
    return 0;
}

