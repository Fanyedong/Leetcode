#include "YangTriangle.h"

vector<vector<int>> YangTriangle::generate(int numRows)
{
	vector<vector<int>> res(numRows);
	for (int i = 0; i < numRows; i++)
	{
		res[i].resize(i+1);
		res[i][0] = res[i][i] = 1;
		for (int j=1; j<i; j++)
		{
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}
	return res;
}

void YangTriangle::verification()
{
	vector<vector<int>> a = generate(5);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			cout << a[i][j];
		}
	}
}

vector<int> YangTriangle::getRow(int rowIndex)
{
	vector<vector<int>> res(rowIndex+1);
	for (int i = 0; i <= rowIndex; i++)
	{
		res[i].resize(i + 1);
		res[i][0] = res[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}
	return res[rowIndex];
}

void YangTriangle::verificationRow()
{
	vector<int> a = getRow(3);
	for (int i = 0; i < a.size(); i++)
	{
	    cout << a[i];
	}
}
