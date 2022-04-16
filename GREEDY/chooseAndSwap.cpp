// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	void swap_char(string &s, char s1, char s2) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == s1)
				s[i] = s2;
			else if (s[i] == s2)
				s[i] = s1;
		}
	}
	string chooseandswap(string a) {
		vector<int> freq(26, 0);
		vector<bool> flag(26, false);
		for (int i = 0; i < a.length(); i++) {
			freq[a[i] - 'a']++;
		}
		for (int i = 0, j = 0; i < a.length() && j < 26; i++)
		{
			while (!freq[j]) j++;
			if (j >= 26)
				break;
			if (!flag[a[i] - 'a']) {
				if (a[i] != (j + 'a')) {
					swap_char(a, a[i], j + 'a');
					return a;
				}
				flag[j] = true;
				j++;
			}
		}
		return a;
	}
};



// { Driver Code Starts.

int main()
{
	Solution obj;
	int t;
	cin >> t;
	while (t--)
	{
		string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
// } Driver Code Ends