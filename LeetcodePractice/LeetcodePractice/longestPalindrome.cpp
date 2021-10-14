#include "longestPalindrome.h"

string longestPalindrome::solutionDP(string s)
{
	/*״̬ת�Ʒ��̣�
		P(i, j) = P(i + 1, j - 1) ^ (Si == Sj)
	��̬�滮�ı߽�������
		P(i, i) = true
		P(i, i + 1) = (S_i == S_{ i + 1 }) */

	int n = s.size();
	if (n < 2) //�պ�һ���ַ����ַ���
	{
		return s;
	}

	int maxLen = 1;
	int begin = 0;
	vector<vector<int>> dp(n, vector<int>(n));//������ά����

	// �������巽����
	// (1) vector<int> a(5); //������5������Ԫ�ص�������<>��ΪԪ�������������������κκϷ����������ͣ�����û�и�����ֵ����ֵ�ǲ�ȷ���ġ�
	//��2��vector<int> a(5, 1); //������5������Ԫ�ص�����,�Ҹ���ÿ��Ԫ�صĳ�ֵΪ1
	//��3��vector<int> a(b); //��b����������a���������帴���Ը�ֵ
	//��4��vector<int> a(b.begin(), b.begin + 3); //������aֵΪb�е�0������2������3����Ԫ��
	//��5��int b[7] = { 1,2,3,4,5,9,8 };

	//vector< vector<int>> v(m, vector<int>(n)); 
	//������һ��vector������Ԫ������Ϊvector<int>����ʼ��Ϊ����m��vector<int>����ÿ��������һ���´�����vector<int>����Ŀ�����
	//������´�����vector<int>���󱻳�ʼ��Ϊ����n��0��

	for (int i = 0; i < n; i++) //�߽�����1������Ϊ1���Ӵ����ǻ��Ĵ�
	{
		dp[i][i] = true;
	}

	for (int L = 2; L <= n; L++)//ö���Ӵ�����
	{
		for (int i = 0; i < n; i++)//ö����߽�
		{
			int j = L + i - 1; // j - i + 1 = L

			if (j >= n)//��������
			{
				break;
			}

			if (s[i] != s[j])//״̬ˢ�·���
				dp[i][j] = false;
			else
			{
				if (j - i < 3)
					dp[i][j] = true;//�߽�����2
				else
					dp[i][j] = dp[i + 1][j - 1];//״̬ת�Ʒ��̣���������
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
