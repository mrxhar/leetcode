/*
@file:
@description:
@author: mrxhar
@date: 2023-09-18 10:05:28
@version: 1.0
@email: mrxhar@163.com
@copyright: Copyright (c) 2023 mrxhar
*/

#include <vector>
using std::vector;

class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        // 位置进行搜索
        // 最大的相邻距离就是最大的间隔距离，我们需要搜索间隔距离
        int mx = 0;
        auto pre = seats.begin();
        for (auto it = seats.begin(); it != seats.end(); it++) {
            // 这时候我们可以判断是否有位置并且得到最大值
            if (*it == 1) {
                // 有人，判断上个人的位置
                if (*pre == 0) {
                    mx = it - pre;
                }
                mx = std::max(mx, (int)(it - pre) / 2);
                pre = it;
            }
        }
        // 判断最后一个位置
        if (seats.back() == 0) {
            mx = std::max(mx, (int)(seats.end() - pre - 1));
        }
        return mx;
    }
};