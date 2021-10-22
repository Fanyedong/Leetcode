#pragma once
#include <vector>
#include <iostream>
using namespace std;

class YangTriangle
{
public:
	vector<vector<int>> generate(int numRows);
	void verification();
	vector<int> getRow(int rowIndex);
	void verificationRow();
};

