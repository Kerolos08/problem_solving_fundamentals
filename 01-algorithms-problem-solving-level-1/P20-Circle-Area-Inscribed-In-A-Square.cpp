#include <iostream>
#include <cmath>
#include <string>
using namespace std;

float ReadSideLengh ()
{
    int A;
    cout << "Enter The Diameter" << endl;
    cin >> A;
    return A;
}

float CalculateAreaInSquere (int A)
{
    const float PI = 3.14;
    float Area = (PI * pow(A , 2)) / 4;
    return Area;
}

void PrintResult (float Area)
{
    cout << "\nThe Area Of Circle Is: " << Area << endl;
}

int main()
{
    PrintResult(CalculateAreaInSquere(ReadSideLengh()));
    return 0;
}