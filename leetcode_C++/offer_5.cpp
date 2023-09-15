/*
@Author: mrxhar
@Date:   2023-08-31 11:15:00
@Email:  1337904145@qq.com
@Blog:
*/
#include <string>

using namespace std;
class Solution
{
public:
    string replaceSpace(string s)
    {
        // 原地修改
        int count = 0, len = s.size();

        for (auto ch : s)
        {
            if (ch == ' ')
            {
                count++;
            }
        }

        s.resize(len + 2 * count);
        for (int i = len - 1, j = s.size() - 1; i < j; i--, j--)
        {
            if (s[i] != ' ')
            {
                s[j] = s[i];
            }
            else
            {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }

        return s;
    }
};
