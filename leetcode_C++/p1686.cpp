/*
@Author: mrxhar
@Date:   2023-08-30 10:07:52
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/stone-game-vi/
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {
        // 每个人都会优先拿对自己有利的石头，这个石头是 两个人有利之间的差值，只要拿这个石头对自己的利用处越高
        vector<pair<int, int>> mp; // 价值及下标
        int n = aliceValues.size();
        for (int i = 0; i < n; i++)
        {
            int dis = aliceValues[i] + bobValues[i];
            mp.emplace_back(dis, i);
        }
        sort(mp.rbegin(), mp.rend()); 
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                sum1 += aliceValues[mp[i].second];
            }
            else
            {
                sum2 += bobValues[mp[i].second];
            }
        }
        if (sum1 == sum2)
        {
            return 0;
        }
        else if (sum1 > sum2)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
};