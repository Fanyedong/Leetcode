#include "mergeTwoArrays.h"
#include <algorithm>

mergeTwoArrays::mergeTwoArrays()
{
}

mergeTwoArrays::~mergeTwoArrays()
{
}


void mergeTwoArrays::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{

	vector<int> sorted(m + n);
	int cur;

	int i = 0;
	int j = 0;
	while (i < m || j < n)
	{
		if (i == m)
		{
			cur = nums2[j];
			j++;
		}
		else if (j == n)
		{
			cur = nums1[i];
			i++;
		}
		else if (nums1[i] < nums2[j])
		{
			cur = nums1[i];
			i++;
		}
		else
		{
			cur = nums2[j];
			j++;
		}
		sorted[i + j - 1] = cur;
	}
	//showResult(sorted);
	nums1 = sorted;
}

void mergeTwoArrays::showResult(vector<int>& a)
{
	for (int k = 0; k < a.size(); k++)
	{
		cout << a[k];
	}
}

void mergeTwoArrays::merge2(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int> result(m + n);

	for (int i = 0; i < m; i++)
	{
		result[i] = nums1[i];
	}
	for (int j = 0; j < n; j++)
	{
		result[n + j] = nums2[j];
	}
	sort(result.begin(), result.end());
	showResult(result);
}
