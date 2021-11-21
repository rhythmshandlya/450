#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long int lli;

void alt(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    int i = 0;
    while (arr[i] < 0)
        i++;
    int j = 1, k;
    if (i % 2 == 0)
        k = i;
    else
        k = i + 1;

    while (j < i)
    {
        swap(arr[j], arr[k]);
        j += 2;
        k += 2;
    }
}

int main()
{
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    for (int i : arr)
        cout << i << " ";
    cout << endl;
    alt(arr, sizeof(arr) / sizeof(int));
    for (int i : arr)
        cout << i << " ";
    cout << endl;
    system("pause");
    return 0;
}