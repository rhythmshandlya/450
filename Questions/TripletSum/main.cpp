#include <iostream>
#include <unordered_set>
using namespace std;

bool find3Numbers(int A[], int n, int X)
{
    unordered_set<int> st1;
    unordered_set<int> st2;

    for (int i = 0; i < n; i++)
    {
        if (A[i] <= X)
        {
            st1.insert(A[i]);
            for (int j = i + 1; j < n; j++)
            {
                int tempSum = A[i] + A[j];
                if (tempSum <= X)
                    st2.insert(tempSum);
            }
        }
    }
    cout << endl;
    for (int i : st1)
    {
        if (st2.find(X - i) != st2.end())
        {
            cout << "(" << i << "," << X - i << ")";
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n, x, A[100];
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << boolalpha << find3Numbers(A, n, x);
    return 0;
}