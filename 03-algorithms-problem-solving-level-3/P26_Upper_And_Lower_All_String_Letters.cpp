#include <iostream>
#include <string>
using namespace std;

string ReadString(string msg)
{
    string text;
    cout << msg;
    getline(cin, text);
    return text;
}

string To_Upp(string text)
{
    for (int i = 0; i <= text.size(); i++)
    {
        if (islower(text[i]))
        {
            text[i] = toupper(text[i]);
        }
        else
        {
            continue;
        }
    }
    return text;
}

string To_Low(string text)
{
    for (int i = 0; i <= text.size(); i++)
    {
        if (isupper(text[i]))
        {
        text[i] = tolower(text[i]);
        }
        else
        {
            continue;
        }
    }
    return text;
}

int main()
{
    string s1 = ReadString("Please Enter Your String\n");
    cout << "\nString After Upper\n";
    cout << To_Upp(s1) << endl;
    cout << "\nStirng After Lower\n";
    cout << To_Low(s1) << endl;
    return 0;
}
