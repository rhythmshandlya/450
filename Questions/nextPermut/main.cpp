#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int lli;

vector<int> countSort(vector<int> &vec, int si)
{
    //1, 5, 5, 3, 0, 3, 6, 8
    vector<int> count(10, 0), ans(vec.size());

    //1 1 0 2 0 2 1 0 1 0
    for (int i = si; i < vec.size(); i++)
    {
        count[vec[i]]++;
    }

    for (int i = 0; i < 10; i++)

        for (int n : count)
            cout << n << " ";
    cout << endl;

    return ans;
}

int smallestIndex(int n, vector<int> &v, int si)
{
    int ei = v.size() - 1;
    int ans = INT_MAX;
    int ansIndex = -1;
    for (int i = si; i <= ei; i++)
        if (v[i] > n)
            if (v[i] < ans)
            {
                ans = v[i];
                ansIndex = i;
            }
    return ansIndex;
}

void nextPermutation(vector<int> &nums)
{
    int i;
    for (i = nums.size() - 2; i >= 0; i--)
    {
        int ind = smallestIndex(nums[i], nums, i + 1);
        if (ind != -1)
        {
            swap(nums[i], nums[ind]);
            nums = countSort(nums, i + 1);
            break;
        }
    }
    if (i == -1)
        sort(nums.begin(), nums.end());
}

int main()
{
    vector<int> nums{1, 5, 5, 3, 0, 3, 6, 8}; //15503368
    nums = countSort(nums, 0);
    for (int i : nums)
    {
        cout << i << " ";
    }
    /* cout << "\n";
    nextPermutation(nums);
    for (int i : nums)
    {
        cout << i;
    } */
    cout << endl;
    system("pause");
    return 0;
}