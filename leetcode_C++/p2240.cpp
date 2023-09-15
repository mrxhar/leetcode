/*
@Author: mrxhar
@Date:   2023-09-01 09:54:40
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/number-of-ways-to-buy-pens-and-pencils/?envType=daily-question&envId=2023-09-01
*/
#include <iostream>

using namespace std;

class Solution
{
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2)
    {
        if (cost1 < cost2)
        {
            return waysToBuyPensPencils(total, cost2, cost1);
        }
        long res = 0, cnt = 0;
        while (total - cnt * cost1 >= 0)
        {
            res += (total - cnt * cost1) / cost2 + 1;
            cnt++;
        }
        return res;
    }
};