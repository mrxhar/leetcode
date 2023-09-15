/*
@Author: mrxhar
@Date:   2023-09-05 10:20:41
@Email:  1337904145@qq.com
@Blog:
https://leetcode.cn/problems/unique-paths-iii/?envType=daily-question&envId=2023-09-05
*/
#include <vector>
using std::vector;
#include <functional>
using std::function;
#include <array>
using std::array;
#include <unordered_map>
using std::unordered_map;
// class Solution {
// public:
//     int uniquePathsIII(vector<vector<int>> &grid) {
//         // 遍历
//         // 这些值
//         // 每一个无障碍方格都要通过一次
//         // 回溯

//         int r = grid.size(), c = grid[0].size();
//         int si = 0, sj = 0, n = 0;  // 标记可以通过的节点数目
//         for (int i = 0; i < r; i++) {
//             for (int j = 0; j < c; j++) {
//                 if (grid[i][j] == 0) {
//                     // 可以通过
//                     n++;
//                 } else if (grid[i][j] == 1) {
//                     n++;
//                     si = i;  // 起点
//                     sj = j;
//                 }
//             }
//         }

//         // 回溯，递归
//         function<int(int, int, int)> dfs = [&](int i, int j, int n) -> int {
//             // 递归结束点
//             if (grid[i][j] == 2) {
//                 if (n == 0) {  // 到达并且刚好走完所有的
//                     return 1;
//                 }
//                 return 0;
//             }

//             int t = grid[i][j], res = 0;  // t 记录方便回溯
//             grid[i][j] = -1;
//             vector<array<int, 2>> dir({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
//             // 递归点
//             for (auto &[di, dj] : dir) {
//                 int ni = i + di;
//                 int nj = j + dj;
//                 if (ni >= 0 && ni < r && nj >= 0 && nj < c &&
//                     (grid[ni][nj] == 0 || grid[ni][nj] == 2)) {
//                     res += dfs(ni, nj, n - 1);
//                 }
//             }
//             grid[i][j] = t;  // 回溯
//             return res;
//         };
//         return dfs(si, sj, n);
//     }
// };

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int vis = 0;
        int sx, sy;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] < 0) {
                    vis |= 1 << (i * n + j);  // 这个方法绝好,标记不能到达的点，标记为已访问过
                } else if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }

        int all = (1 << m * n) - 1;  // 多少位 全集合
        unordered_map<int, int> memo;
        function<int(int, int, int)> dfs = [&](int x, int y, int vis) -> int {
            int p = x * n + y; // 如果 p 位 如果是 1 代表已经标记过
            if (x < 0 || x >= m || y < 0 || y >= n || vis >> p & 1)  // 不符合条件，退出
                return 0;
            vis |= 1 << p;  // p 位置 进行标记
            if (grid[x][y] == 2) {
                return vis == all;
            }
            int key = (p << m * n) | vis; // 最前端一位 是否遍历过
            if (memo.count(key))
                return memo[key];
            return memo[key] = dfs(x - 1, y, vis) + dfs(x + 1, y, vis) + dfs(x, y - 1, vis) + dfs(x, y + 1, vis);
        };
        return dfs(sx, sy, vis);
    }
};

int main() { return 0; }
