/*
@Author: mrxhar
@Date:   2023-09-07 10:14:30
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/maximum-alternating-subsequence-sum/description/?envType=daily-question&envId=2023-09-07
*/
#include <vector>
using std::vector;
#include <cmath>
using std::max;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long f = 0, g = 0;
        for (auto num : nums) {
            long long pref = f;

            f = max(f, g - num);
            g = max(g, pref + num);
        }
        return max(f, g);
    }
};