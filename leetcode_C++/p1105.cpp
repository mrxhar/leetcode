/*
@Author: mrxhar
@Date:   2023-09-07 11:17:28
@Email:  1337904145@qq.com
@Blog:
*/

#include <vector>
using std::vector;
#include <functional>
using std::function;
#include <cmath>
using std::max;
using std::min;
#include <string.h>

class Solution {
public:
    int minHeightShelves(vector<vector<int>> &books, int shelf_width) {
        int n = books.size(), f[n + 1];
        f[0] = 0;  // 翻译自 dfs(-1)=0
        for (int i = 0; i < n; ++i) {
            f[i + 1] = INT_MAX;
            int max_h = 0, left_w = shelf_width;
            for (int j = i; j >= 0; --j) {
                left_w -= books[j][0];
                if (left_w < 0)
                    break;                        // 空间不足，无法放书
                max_h = max(max_h, books[j][1]);  // 从 j 到 i 的最大高度
                f[i + 1] = min(f[i + 1], f[j] + max_h);
            }
        };
        return f[n];  // 翻译自 dfs(n-1)
    }
};

