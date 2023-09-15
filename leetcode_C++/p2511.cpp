/*
@Author: mrxhar
@Date:   2023-09-02 08:52:35
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured/?envType=daily-question&envId=2023-09-02
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int captureForts(vector<int> &forts)
    {
        // 从 -1 出发，到最近的 1,然后获取距离得到最大的值
        // 最长的连续字符
        int ans = 0, pre = -1;
        for (int i = 0; i < forts.size(); i++)
        {
            if (forts[i] == 1 || forts[i] == -1)
            {
                if (pre >= 0 && forts[i] != forts[pre])
                {
                    ans = max(ans, i - pre - 1);
                }
                pre = i;
            }
        }
    }
};