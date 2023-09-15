/*
@Author: mrxhar
@Date:   2023-09-03 09:37:30
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/reverse-subarray-to-maximize-array-value/?envType=daily-question&envId=2023-09-03
*/
#include <vector>
using std::vector;
#include <algorithm>
using std::for_each;
#include <cmath>
using std::abs;
using std::max;
using std::min;

class Solution
{
public:
    int maxValueAfterReverse(vector<int> &nums)
    {
        // 子数组内部不会进行数值改变，主要是在边缘
        // 提高最大值
        int value = 0, n = nums.size();
        for (int i = 0; i < n - 1 ; i++)
        {
            value += abs(nums[i] - nums[i + 1]);
        }
        int mx1 = 0;
        for (int i = 1; i < n - 1; i++)
        {
            // 遍历 k 的信息，只有一端是变化的
            mx1 = max(mx1, abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
            mx1 = max(mx1, abs(nums[n - 1] - nums[i - 1]) - abs(nums[i] - nums[i - 1]));
        }
        int mx2 = INT_MIN, mn2 = INT_MAX;
        // 这时候，主要涉及一些数值 j - 1,j ,k , k + 1;
        for (int i = 0; i < n - 1; i++)
        {
            int x = nums[i], y = nums[i + 1]; // 左端的点，我们进行分开来判断
            // 判断情况
            mx2 = max(mx2, min(x, y));
            mn2 = min(mn2, max(x, y));
        }
        return value + max(mx1, 2 * (mx2 - mn2));
    }
};