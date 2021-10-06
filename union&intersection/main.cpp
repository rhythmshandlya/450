#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long int lli;

int main()
{
    vector<int> a = {1, 3, 4, 5, 7, 78, 88, 100};
    vector<int> b = {1, 4, 8, 9, 10, 88, 100, 230};
    vector<int> U(a), I;

    //INTERSECTION
    for (int i = 0, j = 0; i < a.size() && j < b.size();)
    {
        if (a[i] == b[j])
        {
            I.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }

    //UNION
    for (int i = 0; i < b.size(); i++)
    {
        if (!binary_search(a.begin(), a.end(), b[i]))
            U.push_back(b[i]);
    }

    //OUTPUT
    cout << "A: ";
    for (int i : a)
        cout << i << " ";
    cout << endl
         << "B: ";
    for (int i : b)
        cout << i << " ";
    cout << endl
         << "U: ";

    for (int i : U)
        cout << i << " ";
    cout << endl
         << "I: ";
    for (int i : I)
        cout << i << " ";

    cout << endl;

    cout << endl;
    system("pause");
    return 0;
}