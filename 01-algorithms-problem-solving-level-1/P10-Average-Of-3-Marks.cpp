#include <iostream>
using namespace std;

void ReadMarks (int& mark1, int& mark2, int& mark3)
{
    cout << "Type First Mark" << endl;
    cin >> mark1;
    cout << "Type Second Mark" << endl;
    cin >> mark2;
    cout << "Type Third Mark" << endl;
    cin >> mark3;
}

float AverageOfThreeMarks (int mark1, int mark2, int mark3)
{
    return (float) (mark1 + mark2 + mark3) / 3;
}

void PrintResult (int result)
{
    cout << "\nThe Average Of Your Marks Is: " << result << endl;
}

int main ()
{
    int mark1, mark2, mark3;
    ReadMarks(mark1, mark2, mark3);
    PrintResult(AverageOfThreeMarks(mark1, mark2, mark3));
    return 0;
}