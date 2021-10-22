#include "isPalindrome.h"

bool isPalindrome::solution(string s)
{
	string tmp;
	for (char c : s)
	{
		if (isalnum(c))
		{
			tmp += tolower(c);
		}
	}

	string tmp_rev(tmp.rbegin(), tmp.rend());
	return (tmp == tmp_rev);
}

void isPalindrome::verification()
{
	string s = "A man, a plan, a canal: Panama";
	cout << solution(s);
}
