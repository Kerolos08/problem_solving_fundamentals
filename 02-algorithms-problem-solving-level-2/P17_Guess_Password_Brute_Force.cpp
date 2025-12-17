#include <iostream>
#include <string>
using namespace std;

string ReadPassword ()
{
    string number;
    cout << "Please Enter The Password" << endl;
    cin >> number;
    return number;
}

bool FoundPassword (string password)
{
    int counter = 0;
    string word = ""; 
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int x = 65; x <= 90; x++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(x);
                counter ++;
                cout << "Trail [ " << counter << " ] : " << word << endl;
                if (word == password)
                {
                    cout << "\nPassword is " << password << endl;
                    cout << "Found after " << counter << " Trail(s)" << endl;
                    return true;
                }
                word = "";
            }
        }
    }

    return false;
}

int main ()
{
    FoundPassword(ReadPassword());
    return 0;
}