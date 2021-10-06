#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long int lli;

int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int, int> count;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int num = k - arr[i];
        ans += count[num];
        count[arr[i]]++;
    }
    return ans;
}

int main()
{
    int arr[] = {1, 1, 1, 1};
    cout << getPairsCount(arr, 4, 2);
    cout << endl;
    system("pause");
    return 0;
}