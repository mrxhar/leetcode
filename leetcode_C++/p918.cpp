/*
@Author: mrxhar
@Date:   2023-09-10 10:44:17
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/maximum-sum-circular-subarray/?envType=daily-question&envId=2023-09-10
*/
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
        for (int& num : nums) {
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
            total += num;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};
