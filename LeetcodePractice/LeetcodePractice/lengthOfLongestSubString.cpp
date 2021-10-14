#include "lengthOfLongestSubString.h"
#include <unordered_set>

int lengthOfLongestSubString::Solution(string s)
{
	unordered_set<char> a;
	int n = s.size();

	int rk = -1;
	int ans = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (i != 0)
		{
			a.erase(s[i - 1]);
		}
		while (rk + 1 < n && !a.count(s[rk + 1]))
		{
			a.insert(s[rk + 1]);
			rk++;
		}
		ans = max(ans, rk - i + 1);
	}
	return ans;
}

void lengthOfLongestSubString::verification()
{
	//cout<<Solution("abcdddd");
	cout << practice(" ");
}

int lengthOfLongestSubString::practice(string s)
{
	unordered_set<char> occ;
	int n = s.size();
	int rk = -1;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
		{
			occ.erase(s[i - 1]);
		}
		while (rk + 1 < n && !occ.count(s[rk + 1]))
		{
			occ.insert(s[rk + 1]);
			++rk;
		}
		ans = max(ans, rk - i + 1);
	}
	return ans;
}
