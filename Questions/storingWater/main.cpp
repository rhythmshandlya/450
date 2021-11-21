#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long int lli;

long long findMinDiff(vector<long long> a, long long n, long long m)
{

    sort(a.begin(), a.end());
    int diff = INT_MAX;
    for (int i = 0, lastIndex = 0; lastIndex < n; i++, lastIndex++)
        diff = min(diff, a[lastIndex] - a[i]);

    return diff;
}

int trappingWater(int arr[], int n)
{
    vector<int> left(n);
    vector<int> right(n);
    left[0] = -1;
    right[n - 1] = -1;

    int maxSoFar = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxSoFar = max(maxSoFar, arr[i]);
        left[i] = maxSoFar;
    }

    maxSoFar = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxSoFar = max(maxSoFar, arr[i]);
        right[i] = maxSoFar;
    }

    int volume = 0;
    for (int i = 1; i < n - 1; i++)
        if (left[i] >= arr[i] && right[i] >= arr[i])
            volume += min(left[i], right[i]) - arr[i];
    return volume;
}

int main()
{
    int arr[] = {7, 4, 0, 9};
    int n = sizeof(arr) / sizeof(int);
    cout << trappingWater(arr, n);
    cout << endl;
    system("pause");
    return 0;
}