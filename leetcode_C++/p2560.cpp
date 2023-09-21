/*
@file: name
@description:
@author: mrxhar
@date: 2023-09-19 07:55:29
@version: 1.0
@email: mrxhar@163.com
@copyright: Copyright (c) 2023 mrxhar
*/

#include <vector>
#include <algorithm>
using std::vector;

class Solution {
    /// @brief 判断这时候窃贼的能力为 mx 的时候能否偷窃到对应的房间数
    /// @param nums
    /// @param k
    /// @param mx
    /// @return
    bool check(vector<int> &nums, int k, int mx) {
        // int f0 = 0, f1 = 0;
        // for (int x : nums) {
        //     if (x > mx) { // 偷
        //         f0 = f1;
        //     } else {
        //         int tmp = f1;
        //         f1 = std::max(f1, f0 + 1);
        //         f0 = tmp;
        //     }
        // }
        // return f1 >= k;
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mx) {
                cnt++;
                i++; // 跳位置
            }
        }
        return cnt >= k;
    }

public:
    int minCapability(vector<int> &nums, int k) {
        // 二分，我们需要知道能力，然后判断是否可以偷盗对应的数目
        int left = 0, right = *max_element(nums.begin(), nums.end());

        while (left + 1 < right) {
            int mid = (left) + (right - left) / 2; // 直接加容易超限
            (check(nums, k, mid) ? right : left) = mid;
        }
        return right;
    }
};