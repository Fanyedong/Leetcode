#include "maxProfit.h"

int maxProfit::solution(vector<int>& prices)
{
	int maxIn = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		for (int j = i+1; j < prices.size(); j++)
		{
			if (prices[j] > prices[i] && (prices[j] - prices[i]) > maxIn)
				maxIn = prices[j] - prices[i];
		}
	}
	return maxIn;
}

void maxProfit::verification()
{
	vector<int> a = { 7, 1, 5, 3, 6, 4 };
	cout << fastSolution(a);
}

int maxProfit::fastSolution(vector<int>& prices)
{
	int minPrice = prices[0];
	int recv = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		minPrice = min(minPrice, prices[i]);
		recv = max(recv, prices[i] - minPrice);
	}
	return recv;
}