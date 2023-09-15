/*
@Author: mrxhar
@Date:   2023-09-03 08:58:46
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/eliminate-maximum-number-of-monsters/?envType=daily-question&envId=2023-09-03
*/
#include <vector>
using std::vector;
#include <algorithm>

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<int> arrivalTimes(n);
        for (int i = 0; i < n; i++)
        {
            arrivalTimes[i] = (dist[i] - 1) / speed[i] + 1;
        }
        sort(arrivalTimes.begin(), arrivalTimes.end());
        for (int i = 0; i < n; i++)
        {
            if (arrivalTimes[i] <= i)
            {
                return i;
            }
        }
        return n;
    }
};