#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long merge(long long arr[], long long si, long long mid, long long ei)
{
    long long *temp = new long long[ei - si + 1];
    long long i = si, j = mid + 1, count = 0, k = 0;

    while (i <= mid && j <= ei)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            count += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= ei)
        temp[k++] = arr[j++];

    for (int i = si, k = 0; i <= ei; i++, k++)
        arr[i] = temp[k];
    return count;
}

long long mergeSort(long long arr[], long long si, long long ei)
{
    if (si >= ei)
        return 0;

    long long mid = (ei + si) / 2;

    return mergeSort(arr, si, mid) + mergeSort(arr, mid + 1, ei) + merge(arr, si, mid, ei);
}

long long inversionCount(long long arr[], long long N)
{
    return mergeSort(arr, 0, N - 1);
}

int main()
{
    long long arr[] = {1, 2, 3, 4, 5};
    long long n = sizeof(arr) / sizeof(long long);
    cout << inversionCount(arr, n);
    cout << endl;
    system("pause");
    return 0;
}