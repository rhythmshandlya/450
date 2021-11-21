#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int arr[] = {1, 4, 100, 0, -1, 34, 10001, 56, 2, 78};
    int n = sizeof(arr) / sizeof(int);
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    cout << "MAX " << max << " MIN " << min << endl;
    return 0;
}
