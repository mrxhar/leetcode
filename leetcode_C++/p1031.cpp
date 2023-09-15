/*
@Author: mrxhar
@Date:   2023-09-13 09:40:45
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays/description/?envType=daily-question&envId=2023-09-13
*/
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        // 固定一个枚举第二个，优化第一个变量
        int n = nums.size();
        vector<int> sum;
        sum.push_back(0);
        for (auto& num : nums) {
            sum.push_back(sum.back() + num);
        }

        int ans = 0;
        int maxA = 0, maxB = 0;
        for (int i = firstLen + secondLen; i < sum.size(); i++) {
            maxA = max(maxA, sum[i - secondLen] - sum[i - secondLen - firstLen]);
            maxB = max(maxB, sum[i - firstLen] - sum[i - secondLen - firstLen]);
            ans = max(ans, max(maxA + sum[i] - sum[i - secondLen], maxB + sum[i] - sum[i - firstLen]));
        }
        return ans;
    }
};