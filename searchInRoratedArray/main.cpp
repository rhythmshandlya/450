#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int lli;

int findPvt(int arr[], int first, int last)
{
    if (arr[first] <= arr[last])
        return -1;

    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid] >= arr[first])
            first = mid + 1;
        else
            last = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {6, 7, 8, 9, 1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(int);
    int n = findPvt(arr, 0, size - 1);
    cout << boolalpha << (binary_search(arr, arr + n + 1, 3) || binary_search(arr + n + 1, arr + size, 3));
    cout << endl;
    system("pause");
    return 0;
}