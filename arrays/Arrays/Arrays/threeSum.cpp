#include "threeSum.h"

vector<vector<int>> threeSum::solution(vector<int>& nums)
{
	vector<vector<int>> result;
	int n = nums.size();
	vector<int> tmp;
	sort(nums.begin(), nums.end());

	if (n <= 3)
	{
		result = { };
		return result;
	}

	int p1 = 0;
	int p2 = 0;
	int p3 = 0;

	while (p1 < n - 2)
	{
		if (nums[p1] == nums[p2])
		{
			p2++;
			continue;
		}	
		while(p2  < n - 1 )
		{
			if (nums[p2] == nums[p3])
			{
				p3++;
				continue;
			}
			while (p3 < n)
			{
				if (nums[p1] + nums[p2] + nums[p3] == 0)
				{
					tmp = { nums[p1],nums[p2],nums[p3] };
					result.push_back(tmp);
				}
				p3++;
			}
			p2++;
		}
		p1++;
	}
	return result;
}

void threeSum::verification()
{
	vector<int> a = { -1,-1,0,1 };
	vector<vector<int>> b;
	b = solution(a);

}
