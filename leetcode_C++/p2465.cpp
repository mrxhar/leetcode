/*
@file: name
@description:
@author: mrxhar
@date: 2023-09-18 11:06:42
@version: 1.0
@email: mrxhar@163.com
@copyright: Copyright (c) 2023 mrxhar
*/

#include <vector>
using std::vector;
#include <algorithm>
#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    int distinctAverages(vector<int> &nums) {
        // 一个一个删除，排序即可
        sort(nums.begin(), nums.end());
        // 判断数值是否出现过
        unordered_set<int> app;
        // 排序后需要办理 计算的是删除两树的数值
        for (int i = 0; i < nums.size() / 2; i++) {
            // 不需要记录平均值了，记录和也可以
            int tmp = nums[i] + nums[nums.size() - i - 1];
            if (!app.count(tmp)) {
                app.insert(tmp);
            }
        }

        return app.size();
    }
};