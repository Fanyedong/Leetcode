#include "intToRoman.h"

const pair<int, string> valueSymbols[] = {
    //���������� 77 ����ͬ�ĵ���ĸ������ɣ�ÿ�����Ŷ�Ӧһ���������ֵ�����⣬�������������������������������˶���� 66 �����Ϸ��š�
    //����������ܹ� 1313 �����صķ��ţ�ÿ�������� 11 ���� 22 ����ĸ��ɣ�

    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

string intToRoman::solution(int num) {
    string roman;
    for (pair<int, string> a: valueSymbols) {
        while (num >= a.first) {
            num -= a.first;
            roman += a.second;
        }
        if (num == 0) {
            break;
        }
    }
    return roman;
}

void intToRoman::verification()
{
    cout << solution(58);
    //�ڴ������ "LVIII"
}

const string thousands[] = { "", "M", "MM", "MMM" };
const string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
const string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

string intToRoman::solution2(int num) 
{
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
}



