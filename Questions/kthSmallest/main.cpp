#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef long long int lli;

/*
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
Input:
N = 5
arr[] = 7 10 4 20 15
K = 4
Output : 15
*/

int kthSmallest(int arr[], int l, int r, int k)
{
    int n = r - l + 1;
    priority_queue<int> pq;
    for (int i = l; i <= r; i++)
        pq.push(arr[i]);
    k = n - k;
    while (k--)
        pq.pop();
    return pq.top();
}

int main()
{
    int arr[] = {1, 2, 4, 3, 6, 5, 7, 8, 9, 10};
    cout << kthSmallest(arr, 0, 9, 6);
    cout << endl;
    system("pause");
    return 0;
}
