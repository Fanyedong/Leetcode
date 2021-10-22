#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class longestPalindrome
{
public:
	string solutionDP(string s);

	void verification();

	string practiceDP(string s);

	string solutionCenterExpand(string s);

	pair<int, int> expandAroundCenter(const string& s, int left, int right);

};
