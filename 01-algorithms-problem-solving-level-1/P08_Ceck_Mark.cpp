#include <iostream>
using namespace std;

enum enPassFail {pass, fail};

int ReadMark ()
{
    int mark;
    cout << "Type Your mark" << endl;
    cin >> mark;
    return mark;
}

enPassFail CheckMark (int mark)
{
    if (mark >= 50)
    return enPassFail :: pass;
    else
    return enPassFail :: fail;
}

// void PrintResult (enPassFail result)
// {
// if (result == enPassFail::pass)
// cout << "\nYou Passed" << endl;
// else
// cout << "\nYou Failed" << endl;
// }

void PrintResult (int mark)
{
    if (CheckMark(mark) == enPassFail :: pass)
    cout << "\nYou Passed" << endl;
    else
    cout << "\nYou Failed" << endl;
}


int main ()
{
    PrintResult(ReadMark());
    return 0;
}