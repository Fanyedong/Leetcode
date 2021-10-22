#pragma once
#include <iostream>
#include <vector>
using namespace std;


class twoSum
{
public:
	
	vector<int> solution(vector<int>& numbers, int target);

	void verification();

	vector<int> solutionPointer(vector<int>& numbers, int target);
};

