/*
@Author: mrxhar
@Date:   2023-09-01 10:38:34
@Email:  1337904145@qq.com
@Blog:  https://leetcode.cn/problems/largest-number-after-digit-swaps-by-parity/description/?envType=daily-question&envId=2023-09-01
*/

#include <string>

using namespace std;
class Solution
{
public:
    int largestInteger(int num)
    {
        // 转成字符串
        string s = to_string(num);
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = i + 1; j < s.size(); ++j)
            {
                if ((s[i] - s[j]) & 1 == 0 && s[i] < s[j])
                {
                    swap(s[i], s[j]);
                }
            }
        }
        return stoi(s);
    }
};