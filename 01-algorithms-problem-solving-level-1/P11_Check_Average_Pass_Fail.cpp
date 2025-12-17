#include <iostream>
using namespace std;
enum enPassFail {pass, fail};
void ReadMark (int& mark1, int& mark2, int& mark3)
{
cout << "Please Enter Mark 1" << endl;
cin >> mark1;

cout << "Please Enter Mark 2" << endl;
cin >> mark2;

cout << "Please Enter Mark 3" << endl;
cin >> mark3;
}

int SumOfThreeMarks (int mark1, int mark2, int mark3)
{
return mark1 + mark2 + mark3;
}

float GetAverage (int mark1, int mark2, int mark3)
{
    return (float) SumOfThreeMarks(mark1, mark2, mark3) / 3;
}

enPassFail CheckAverage (float Average)
{
    if (Average >= 50)
    return enPassFail::pass;
    else
    return enPassFail::fail;
}

void PrintTheResult (float Average)
{
    cout << "\nYour Average Is: " << Average << endl;

    if (CheckAverage(Average) == enPassFail::pass)
    cout << "\n You Passed" << endl;
    else
    cout << "\n You Failed" << endl;
}

int main ()
{
    int mark1;
    int mark2;
    int mark3;
    ReadMark(mark1, mark2, mark3);
    PrintTheResult(GetAverage(mark1, mark2, mark3));
    return 0;
}