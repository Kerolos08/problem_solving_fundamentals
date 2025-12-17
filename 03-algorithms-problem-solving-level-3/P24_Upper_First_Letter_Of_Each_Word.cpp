#include <iostream>
#include <string>
using namespace std;

string ReadString (string msg)
{
    string text;
    cout << msg;
    getline (cin, text);
    return text;
}

string FormatName (string text)
{
    bool Is_FirstLetter = true;
    for (int i = 0; i <= text.size(); i++)
    {
        if (text[i] != ' ' && Is_FirstLetter)
        {
            text[i] = toupper(text[i]);
        }
        Is_FirstLetter = (text[i] == ' ' ? true : false);
    }
    return text;
}

int main ()
{
    string s1 = ReadString("Please Enter Your String\n");
    cout << "\nString After Conversion\n";
    s1 = FormatName(s1);
    cout << s1 << endl;
    return 0;
}