#include <iostream>
#include <string>
using namespace std;

string RemovePuctuationsFormString (string Text)
{
    string NewText = "";
    for (int i = 0; i < Text.length(); i++)
    {
        if (!ispunct(Text[i]))
        {
            NewText += Text[i];
        }
    }
    return NewText;
}

int main ()
{
    string Text = "Hello, this is a test, for this function'' LLL";
    cout << "Original String\n";
    cout <<  Text << endl;
    cout << "\n";
    cout << "String after all puctuation removal\n";
    cout << RemovePuctuationsFormString(Text) << endl;
    return 0;
}
