/*
@Author: mrxhar
@Date:   2023-08-29 10:20:50
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/check-if-it-is-possible-to-split-array/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    bool canSplitArray(vector<int> &nums, int m)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return true;
        }

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] + nums[i - 1] >= m)
            {
                return true;
            }
        }
        return false;
    }
};
