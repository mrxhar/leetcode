/*
@file: name
@description:
@author: mrxhar
@date: 2023-10-08 10:38:59
@version: 1.0
@email: mrxhar@163.com
@copyright: Copyright (c) 2023 mrxhar
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>> &nums) {
        int ans = 0;
        int n = nums.size(), m = nums[0].size();
        // 需要遍历多少次
        for (auto &row : nums) {
            sort(row.begin(), row.end());
        }
        for (int i = 0; i < m; i++) {
            int mx = 0;
            for (auto &row : nums) {
                mx = max(mx, row[i]);
            }
            ans += mx;
        }
        return ans;
    }
};