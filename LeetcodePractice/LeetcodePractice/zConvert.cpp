#include "zConvert.h"

string zConvert::solution(string s, int numRows)
{
    //����һ����������
    //ͨ���������ҵ����ַ��������ǿ������ɵ�ȷ���ַ�λ�� Z ����ͼ���е���һ�С�
    //���ǿ���ʹ��rows(min(numRows, int(s.size())))���б�����ʾ Z ����ͼ���еķǿ��С�
    //�����ҵ��� ss����ÿ���ַ���ӵ����ʵ��С�����ʹ�õ�ǰ�к͵�ǰ���������������Ժ��ʵ��н��и��١�
    //ֻ�е����������ƶ�����������л������ƶ������������ʱ����ǰ����Żᷢ���ı�

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

    //�ڴ������"PINALSIGYAHRPI"
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


