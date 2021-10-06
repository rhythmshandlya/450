
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long int lli;

int minJumps(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; count++)
    {
        int nextIndex = i + 1;
        if (arr[i] == 0)
            return -1;
        if (arr[i] + i >= n - 1)
        {
            count++;
            break;
        }
        for (int j = i + 1; j <= i + arr[i]; j++)
        {
            if (j + arr[j] > nextIndex + arr[nextIndex])
            {
                nextIndex = j;
            }
        }
        i = nextIndex;
    }
    return count;
}

int main()
{

    cout << endl;
    system("pause");
    return 0;
}