#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString (vector <string> vWords, string Delimiter)
{
    string S1 = "";
    for (string &s : vWords)
    {
        S1 = S1 + s + Delimiter;
    }
    return (S1.substr(0, S1.length() - Delimiter.length()));
}

string JoinString (string Names [], int length, string Delimiter)
{
    string S1 = "";
    for (int i = 0; i < length; i++)
    {
        S1 = S1 + Names[i] + Delimiter;
    }
    return (S1.substr(0, S1.length() - Delimiter.length()));
}

int main ()
{
    vector <string> vNames = {"Kerolos", "Hany", "Gerges", "Soliman"};
    string Names[] = {"Kerolos", "Hany", "Gerges", "Soliman"};

    cout << "Vector after join\n";
    cout << JoinString(vNames, " ") << endl;
    cout << "\n";
    cout << "Array after join\n";
    cout << JoinString(Names, 4, " ") << endl;
    return 0;
}