/*
@Author: mrxhar
@Date:   2023-08-29 10:25:25
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/partition-equal-subset-sum/
*/
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        // 和如果不是偶数肯定是不行的，我们也可也使用双指针
        if (n < 2)
        {
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        if (target < maxNum)
        {
            return false;
        }

        vector<int> dp(target + 1, 0);
        dp[0] = true;

        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            for (int j = target; j >= num; j--)
            {
                dp[j] |= dp[j - num];
            }
        }
        return dp[target];
    }
};