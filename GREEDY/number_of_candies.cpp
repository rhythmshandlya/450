// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        sort(candies, candies + n);
        int number_of_candies;
        if (k != 0)
            number_of_candies = ( n / (k + 1)) + ( n % (k + 1) != 0 ? 1 : 0);
        else
            number_of_candies = n;

        cout << number_of_candies << endl;
        int mx_ans = 0, mn_ans = 0;
        for (int i = 0; i < number_of_candies; i++) {
            mx_ans += candies[i];
        }
        for (int i = n - number_of_candies; i < n; i++) {
            mn_ans += candies[i];
        }
        return {mx_ans, mn_ans};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends