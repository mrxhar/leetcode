/*
@file: name
@description:
@author: mrxhar
@date: 2023-09-19 08:58:41
@version: 1.0
@email: mrxhar@163.com
@copyright: Copyright (c) 2023 mrxhar
*/

#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    int unequalTriplets(vector<int> &nums) {
        unordered_map<int, int> cnt;
        for (int &v : nums) {
            ++cnt[v];
        }
        int ans = 0, a = 0;
        int n = nums.size();
        for (auto &[_, b] : cnt) {
            int c = n - a - b; // a
            ans += a * b * c;
            a += b;
        }
        return ans;
    }
};