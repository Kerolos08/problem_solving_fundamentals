#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;


void PrintArrayElements (int nums[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

bool IsPalindrome (int nums[100], int arrlength)
{
    for (int i = 0; i < arrlength; i++)
    {
        if (nums[i] != nums[arrlength - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main ()
{
    srand((unsigned)time(NULL));

    int nums[] = {10, 20, 30, 30, 20, 10};
    int length = size(nums);
    int nums2[100];
    int length2 = 0;

    cout << "Array elements : ";
    PrintArrayElements(nums, length);

    if (IsPalindrome(nums, length))
    cout << "Yes array is palindrome" << endl;
    else 
    cout << "No array is not palindrome" << endl;
    return 0;
}


