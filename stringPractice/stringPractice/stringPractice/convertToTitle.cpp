#include "convertToTitle.h"

string convertToTitle::solution(int columnNumber)
{
	string s;
	while (columnNumber != 0)
	{
		int tmp = (columnNumber-1) % 26;
		s += tmp + 'A';
		columnNumber = (columnNumber - 1) / 26;
	}
	string result(s.rbegin(), s.rend());
	return result;
}

void convertToTitle::verification()
{
	cout << solution(28);
}
