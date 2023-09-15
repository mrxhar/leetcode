/*
@Author: mrxhar
@Date:   2023-09-14 11:13:15
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/power-of-heroes/?envType=daily-question&envId=2023-09-14
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        sort(nums.begin(), nums.end());

        int ans = 0, s = 0;
        for (long long x : nums) {
            ans = (ans + x * x % MOD * (x + s)) % MOD;
            s = (s * 2 + x) % MOD;
        }

        return ans;
    }
};