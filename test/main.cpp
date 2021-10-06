#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string getLetter(int n)
    {
        switch (n)
        {
        case 2:
            return "abc";
            break;
        case 3:
            return "def";
            break;
        case 4:
            return "ghi";
            break;
        case 5:
            return "jkl";
            break;
        case 6:
            return "mno";
            break;
        case 7:
            return "pqrs";
            break;
        case 8:
            return "tuv";
            break;
        case 9:
            return "wxyz";
            break;
        }
        return "";
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> ans{""};
        for (int i = 0; i < N; i++)
        {
            string str = getLetter(a[i]);
            int l = ans.size();
            for (int j = 0; j < l; j++)
            {
                for (int k = 0; k < str.size(); k++)
                    ans.push_back(ans[0] + str[k]);

                ans.erase(ans.begin());
            }
        }
        return ans;
    }
};

int main()
{

    int T;

    cin >> T; //testcases

    while (T--)
    { //while testcases exist
        int N;
        cin >> N; //input size of array

        int a[10000]; //declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; //input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends