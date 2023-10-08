/*
@file: name
@description:
@author: mrxhar
@date: 2023-10-08 11:15:54
@version: 1.0
@email: mrxhar@163.com
@copyright: Copyright (c) 2023 mrxhar
*/
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // 返回的最大利润，我们需要保持一个股票在手
        // 每一天我们都可以进行买入卖出，买入则是我们目前没有股票在
        // 动态规划
        // 贪心
        int ans = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};