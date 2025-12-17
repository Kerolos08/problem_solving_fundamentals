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

int main ()
{
    vector <string> Names = {"Kerolos", "Hany", "Gerges", "Soliman"};
    cout << "Vector after join\n";
    cout << JoinString(Names, " ") << endl;
    return 0;
}