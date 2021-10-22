#include "majorityElement.h"

int majorityElement::solution(vector<int>& nums)
{
	int count = 0;
	int result = 0;
	if (nums.size() == 1)
	{
		return nums[0];
	}

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[j] == nums[i])
			{
				count++;
			}
		}
		if (count > (nums.size() / 2))
		{
			result = nums[i];
			break;
		}

		else
			count = 0;
	}
	return result;
}

void majorityElement::verification()
{
	vector<int> a = { 3,3,4,6,6,77,5,5,5,5,5,5,5,5,5 };
	cout << solution(a);
}

int majorityElement::easySolution(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	return nums[nums.size() / 2];
}

