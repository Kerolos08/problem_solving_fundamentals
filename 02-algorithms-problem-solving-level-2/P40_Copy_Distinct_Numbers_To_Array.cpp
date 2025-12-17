#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;


void AddArrayElements (int number, int arr[100], int& arrlength)
{
    arrlength ++;
    arr[arrlength - 1] = number;
}

int SearchForANumber (int arr[100], int arrLength, int numbertosearchfor)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == numbertosearchfor)
        {
            return i;
        }
    }
    return -1;
}

bool ExistedOrNot (int arr[100], int arrLength, int numbertosearchfor)
{
return SearchForANumber(arr, arrLength, numbertosearchfor) == -1;
}


void PrintArrayElements (int nums[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

// void CopyDistinctNumbersIntoNewArray (int nums[100], int nums2[100], int arrlength, int& arrlength2)
// {
//     int counter = 0;
//     for (int i = 0; i < arrlength; i++)
//     {
//         if (nums[i] == nums[i + 1])
//         {
//             continue;
//         }
//         else
//         {
//         AddArrayElements(nums[i], nums2, arrlength2);
//         }
//     }
// }

void CopyDistinctNumbersIntoNewArray (int nums[100], int nums2[100], int arrlength, int& arrlength2)
{
    for (int i = 0; i < arrlength; i++)
    {
    if (ExistedOrNot(nums2, arrlength2, nums[i]))
    {
        AddArrayElements(nums[i], nums2, arrlength2);
    }
    }
}

int main ()
{
    srand((unsigned)time(NULL));

    int nums[] = {10, 10, 10, 50, 50, 70, 70, 70, 70, 90, 40, 40 ,50 ,30 ,30};
    int length = size(nums);
    int nums2[100];
    int arrlength2 = 0;
    CopyDistinctNumbersIntoNewArray(nums, nums2, length, arrlength2);

    cout << "Array elements : ";
    PrintArrayElements(nums, length);

    cout << "Array 2 distinct numbers : ";
    PrintArrayElements(nums2, arrlength2);
    return 0;
}