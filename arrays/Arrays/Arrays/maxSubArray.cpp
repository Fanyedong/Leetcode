#include "maxSubArray.h"

int maxSubArray::solution(vector<int>& nums)
{
	int maxSum = nums[0];
	for (int i = 0; i < nums.size(); i++)
	{
		int sum = 0;
		for (int j = i; j < nums.size(); j++)
		{
			sum += nums[j];
			maxSum = max(maxSum, sum);
		}
	}
	return maxSum;
}

void maxSubArray::verification()
{
	vector<int> a = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << fastSolution(a);
}

int maxSubArray::fastSolution(vector<int>& nums)
{
	// ��̬�滮

	
	int result = nums[0];
	int pre = 0;
	for (int i:nums)
	{
		pre = max(pre + i, i); // ��̬�滮ת�Ʒ���
		result = max(pre, result);
	}
	return result;
}
