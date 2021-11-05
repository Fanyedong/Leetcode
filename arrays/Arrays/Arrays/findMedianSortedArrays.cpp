#include "findMedianSortedArrays.h"

double findMedianSortedArrays::solution(vector<int>& nums1, vector<int>& nums2)
{
	int n1 = nums1.size();
	int n2 = nums2.size();

	vector<int> combineVec(n1 + n2);

	for (int i = 0; i < n1; i++)
	{
		combineVec[i] = nums1[i];
	}
	
	for (int j = 0; j < n2; j++)
	{
		combineVec[j + n1] = nums2[j];
	}

	sort(combineVec.begin(), combineVec.end());

	double result = 0;
    
	if ((n1 + n2) % 2 == 1)
	{
		result = combineVec[(n1 + n2 - 1) / 2];
	}
	else
		result = (combineVec[(n1 + n2) / 2] + combineVec[(n1 + n2) / 2 - 1]) / 2.0;

	return result;
}

void findMedianSortedArrays::verification()
{
	vector<int> nums1 = { 1, 2};
	vector<int> nums2 = { 3 ,4}; 
	//cout<<solution(nums1, nums2);
	cout << solution2(nums1, nums2);
}

double findMedianSortedArrays::solution2(vector<int>& nums1, vector<int>& nums2)
{
	int n1 = nums1.size();
	int n2 = nums2.size();
	int n = n1 + n2;

	int p1 = 0;
	int p2 = 0;

	int mid = 0;
	int indicator = 0;
	if (n % 2 == 1)
	{
		mid = (n - 1) / 2;
		indicator = 1;
	}
	else
		mid = n / 2;

	vector<int> sortedArray;

	for (int i = 0; i <= mid; i++)
	{
		if (p1 >= n1)
		{
			sortedArray.push_back(nums2[p2]);
			p2++;
		}
		else if (p2 >= n2)
		{
			sortedArray.push_back(nums1[p1]);
			p1++;
		}
        else if (nums1[p1] < nums2[p2])
		{
			sortedArray.push_back(nums1[p1]);
			p1++;
		}
		else
		{
			sortedArray.push_back(nums2[p2]);
			p2++;
		}
	}

	float result = 0;
	if (indicator == 1)
	{
		result = sortedArray[mid];
	}
	else
		result = (sortedArray[mid] + sortedArray[mid - 1]) / 2.0;

	return result;

}
