#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumberFromTo (int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}


int main ()
{
    srand((unsigned)time(NULL));

    cout << RandomNumberFromTo(0,10) << endl;
    cout << RandomNumberFromTo(0,10) << endl;
    cout << RandomNumberFromTo(0,10) << endl;

    return 0;
}