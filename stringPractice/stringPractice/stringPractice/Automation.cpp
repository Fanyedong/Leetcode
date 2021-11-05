#include "Automation.h"

void Automation::get(char c) {
    state = table[state][get_col(c)];
    if (state == "in_number") {
        ans = ans * 10 + c - '0';
        ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
    }
    else if (state == "signed")
        sign = c == '+' ? 1 : -1;
}
