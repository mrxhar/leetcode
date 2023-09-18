/*
@file:
@description:
@author: mrxhar
@date: 2023-09-18 11:19:56
@version: 1.0
@email: mrxhar@163.com
@copyright: Copyright (c) 2023 mrxhar
*/

#include <vector>
using std::vector;
#include <queue>
using std::queue;
#include <algorithm>

class Solution {
public:
    vector<int> pondSizes(vector<vector<int>> &land) {
        // 广度优先遍历，然后将其中的数值 替换
        // 我们只需要知道 0 的位置哦
        int n = land.size(), m = land[0].size();
        auto bfs = [&](int i, int j) -> int {
            queue<int> q;
            int pos = i * m + j;
            q.push(pos);
            land[i][j] = -1;
            int ares = 0;
            while (!q.empty()) {
                int prespos = q.front();
                int prex = prespos / m, prey = prespos % m;
                q.pop();
                ares++;
                // 开始便利
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) {
                            continue;
                        }

                        int x = prex + dx;
                        int y = prey + dy;

                        if (x < 0 || x >= n || y < 0 || y >= m) {
                            continue;
                        }
                        if (land[x][y] == 0) {
                            pos = x * m + y;
                            land[x][y] = -1;
                            q.push(pos);
                        }
                    }
                }
            }
            return ares;
        };
        vector<int> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 判断水域大小并且更新，使用广度优先便利
                // 需要记录水域的大小
                if (land[i][j] == 0) {
                    res.push_back(bfs(i, j));
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};