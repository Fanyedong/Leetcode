#include "longestPalindrome.h"

string longestPalindrome::solutionDP(string s)
{
	/*状态转移方程：
		P(i, j) = P(i + 1, j - 1) ^ (Si == Sj)
	动态规划的边界条件：
		P(i, i) = true
		P(i, i + 1) = (S_i == S_{ i + 1 }) */

	int n = s.size();
	if (n < 2) //空和一个字符的字符串
	{
		return s;
	}

	int maxLen = 1;
	int begin = 0;
	vector<vector<int>> dp(n, vector<int>(n));//构建二维数组

	// 常见定义方法：
	// (1) vector<int> a(5); //定义了5个整型元素的向量（<>中为元素类型名，它可以是任何合法的数据类型），但没有给出初值，其值是不确定的。
	//（2）vector<int> a(5, 1); //定义了5个整型元素的向量,且给出每个元素的初值为1
	//（3）vector<int> a(b); //用b向量来创建a向量，整体复制性赋值
	//（4）vector<int> a(b.begin(), b.begin + 3); //定义了a值为b中第0个到第2个（共3个）元素
	//（5）int b[7] = { 1,2,3,4,5,9,8 };

	//vector< vector<int>> v(m, vector<int>(n)); 
	//定义了一个vector容器，元素类型为vector<int>，初始化为包含m个vector<int>对象，每个对象都是一个新创立的vector<int>对象的拷贝，
	//而这个新创立的vector<int>对象被初始化为包含n个0。

	for (int i = 0; i < n; i++) //边界条件1，长度为1的子串都是回文串
	{
		dp[i][i] = true;
	}

	for (int L = 2; L <= n; L++)//枚举子串长度
	{
		for (int i = 0; i < n; i++)//枚举左边界
		{
			int j = L + i - 1; // j - i + 1 = L

			if (j >= n)//结束条件
			{
				break;
			}

			if (s[i] != s[j])//状态刷新方程
				dp[i][j] = false;
			else
			{
				if (j - i < 3)
					dp[i][j] = true;//边界条件2
				else
					dp[i][j] = dp[i + 1][j - 1];//状态转移方程，向内收缩
			}

			if (dp[i][j] && j - i + 1 > maxLen)
			{
				maxLen = j - i + 1;
				begin = i;
			}
		}

	}
	return s.substr(begin, maxLen);
}

void longestPalindrome::verification()
{
	string s = "abdbaccc";
	//cout << solutionDP(s);
	cout << practiceDP(s);
}

string longestPalindrome::practiceDP(string s)
{
	int n = s.size();
	if (n < 2)
	{
		return s;
	}

	int maxLen = 1;
	int begin = 0;
	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		dp[i][i] = true;
	}

	for (int L = 2; L <= n; L++)
	{
		for (int i = 0; i < n; i++)
		{
			int j = L + i - 1;//j-i+1=L

			if (j >= n)
			{
				break;
			}

			if (s[i] != s[j])
				dp[i][j] = false;
			else
			{
				if (j - i < 3)
				{
					dp[i][j] = true;
				}
				else
				{
					dp[i][j] = dp[i + 1][j - 1];
				}
			}

			if (dp[i][j] && j - i + 1 > maxLen)
			{
				maxLen = j - i + 1;
				begin = i;
			}
		}
	}
	return s.substr(begin, maxLen);
}
