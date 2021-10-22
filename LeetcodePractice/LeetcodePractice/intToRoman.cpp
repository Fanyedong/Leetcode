#include "intToRoman.h"

const pair<int, string> valueSymbols[] = {
    //罗马数字由 77 个不同的单字母符号组成，每个符号对应一个具体的数值。此外，减法规则（如问题描述中所述）给出了额外的 66 个复合符号。
    //这给了我们总共 1313 个独特的符号（每个符号由 11 个或 22 个字母组成）

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
    //期待输出： "LVIII"
}

const string thousands[] = { "", "M", "MM", "MMM" };
const string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
const string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

string intToRoman::solution2(int num) 
{
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
}



