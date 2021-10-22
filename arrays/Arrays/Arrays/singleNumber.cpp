#include "singleNumber.h"

int singleNumber::solution(vector<int>& nums)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[i] == nums[j])
			{
				count++;
			}	
		}
		if (count == 1)
			break;
		else
			count = 0;
	}
	return nums[i];
}

void singleNumber::verification()
{
	vector<int> a = {3,2,2,1,6,6,3};
	cout<<easySolution(a);
}

int singleNumber::easySolution(vector<int>& nums)
{
	int ret = 0;
	for (int i : nums)
	{
		ret ^= i;
	}
	return ret;
}