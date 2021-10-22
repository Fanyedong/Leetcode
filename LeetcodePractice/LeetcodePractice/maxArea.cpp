#include "maxArea.h"

int maxArea::solution(vector<int>& height) 
{
	//Ë«Ö¸Õë

	int l = 0;
	int r = height.size() - 1;
	int ans=0;

	while (l < r)
	{
		int area = min(height[l], height[r]) * (r - l);
		ans = max(area, ans);
		if (height[l] < height[r])
		{
			l++;
		}
		else
		{
			r--;
		}
	}
	return ans;
}

void maxArea::verification()
{
	vector<int> a = { 1,8,6,2,5,4,8,3,7 };
	cout<<solution(a);

	//ÆÚ´ýÊä³ö£º49
}