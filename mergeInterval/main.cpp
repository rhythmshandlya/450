#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long int lli;

vector<vector<int>> merge(vector<vector<int>> in)
{
    sort(in.begin(), in.end());
    vector<vector<int>> merged;

    for (auto ele : in)
    {
        if (merged.empty() || merged.back()[1] < ele[0])
            merged.push_back(ele);
        else
            merged.back()[1] = max(merged.back()[1], ele[1]);
    }
    return merged;
}

void print(vector<vector<int>> in)
{
    cout << "[ ";
    for (int i = 0; i < in.size(); i++)
        cout << "[" << in[i].at(0) << "," << in[i].at(1) << "] ";
    cout << "]\n";
}
int main()
{
    //[[5,5],[1,3],[3,5],[4,6],[1,1],[3,3],[5,6],[3,3],[2,4],[0,0]]
    vector<vector<int>> mergeMe{{1, 2}, {1, 2}};
    print(mergeMe);
    print(merge(mergeMe));
    cout << endl;
    system("pause");
    return 0;
}