#include <bits/stdc++.h>
using namespace std;

void mergeArray(int a[], int b[], int n, int m)
{
    int mx = 0;

    mx = max(a[n - 1], b[m - 1]);
    mx++;
    int i = 0, j = 0, k = 0;
    while (i < n && j < m && k < (n + m))
    {
        int e1 = a[i] % mx;
        int e2 = b[j] % mx;

        if (e1 <= e2)
        {
            if (k < n)
                a[k] += (e1 * mx);
            else
                b[k - n] += (e1 * mx);
            i++;
            k++;
        }
        else
        {
            if (k < n)
                a[k] += (e2 * mx);
            else
                b[k - n] += (e2 * mx);
            j++;
            k++;
        }
    }
    while (i < n)
    {
        int el = a[i] % mx;
        if (k < n)
            a[k] += (el * mx);
        else
            b[k - n] += (el * mx);
        i++;
        k++;
    }
    while (j < m)
    {
        int el = b[j] % mx;
        if (k < n)
            b[k] += (el * mx);
        else
            b[k - n] += (el * mx);
        j++;
        k++;
    }
    for (int i = 0; i < n; i++)
        a[i] = a[i] / mx;
    for (int i = 0; i < m; i++)
        b[i] = b[i] / mx;

    return;
}

int main()
{
    int a[] = {3, 5, 6, 8, 12, 55, 67};
    int b[] = {1, 4, 9, 13, 100};
    int n = sizeof(a) / sizeof(int);
    int m = sizeof(b) / sizeof(int);

    mergeArray(a, b, n, m);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    for (int i = 0; i < m; i++)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}