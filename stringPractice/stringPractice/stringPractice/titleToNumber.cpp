#include "titleToNumber.h"

int titleToNumber::solution(string columnTitle)
{
	string tmp(columnTitle.rbegin(),columnTitle.rend());
	int sum = 0;
	int count = 0;

	for (char c : tmp)
	{
		int p = c - 'A' + 1;
		sum = sum + p * pow(26, count);
		count++;
	}
	return sum;
}

void titleToNumber::verification()
{
	string s = "ZY";
	cout << solution(s);
}
