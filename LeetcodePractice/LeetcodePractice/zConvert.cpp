#include "zConvert.h"

string zConvert::solution(string s, int numRows)
{
    //方法一：按行排序
    //通过从左向右迭代字符串，我们可以轻松地确定字符位于 Z 字形图案中的哪一行。
    //我们可以使用rows(min(numRows, int(s.size())))个列表来表示 Z 字形图案中的非空行。
    //从左到右迭代 ss，将每个字符添加到合适的行。可以使用当前行和当前方向这两个变量对合适的行进行跟踪。
    //只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变

    if (numRows == 1)
    {
        return s;
    }

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s)
    {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1)
        {
            goingDown = !goingDown;
        }
        curRow += goingDown ? 1 : -1;
    }

    string ret;
    for (string row : rows)
    {
        ret += row;
    }
    return ret;
}

void zConvert::verification()
{
    string s = "PAYPALISHIRING";
    //cout<<solution(s, 4);
    cout << practice(s, 4);

    //期待输出："PINALSIGYAHRPI"
}

string zConvert::practice(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown=false;

    for (char c : s)
    {
        rows[curRow] += c;

        if(curRow == 0 || curRow == numRows - 1)
        {
            goingDown = !goingDown;
        }
        curRow += goingDown ? 1 : -1;
    }

    string ret;
    for (string row : rows)
    {
        ret += row;
    }
    return ret;
}


