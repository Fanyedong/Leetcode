#include "twoSum.h"

vector<int> twoSum::solution(vector<int>& numbers, int target)
{
	int a = -1;
	int b = -1;
	vector<int> result;

	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = i+1; j < numbers.size(); j++)
		{
			if (numbers[i] + numbers[j] == target)
			{
				a = i;
				b = j;
				result = { a+1,b+1 };
			}
		}
	}
	return result;
}

void twoSum::verification()
{
	vector<int> a = { 2,7,11,15 };
	vector<int> b = solutionPointer(a, 9);
	cout << b[0] << " " << b[1];
}

vector<int> twoSum::solutionPointer(vector<int>& numbers, int target)
{
	int low = 0;
	int high = numbers.size() - 1;
	int sum = 0;
	vector<int> result;

	while (low < high)
	{
		sum = numbers[low] + numbers[high];
		if (sum == target)
		{
			result = { low+1,high+1 };
			break;
		}
		else 
		{
			if (sum > target)
				high--;
			else
				low++;
		}
	}
	return result;
}
