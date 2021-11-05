#include "myAtoi.h"

int myAtoi::solution(string str)
{
    // https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/
    // 自动机，需要Automation的map
    Automation automaton;
    for (char c : str)
        automaton.get(c);
    return automaton.sign * automaton.ans;
}

void myAtoi::verification()
{
    cout <<solution("    87  with");
}


