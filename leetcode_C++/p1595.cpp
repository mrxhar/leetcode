#include <functional>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int connectTwoGroups(vector<vector<int>> &cost) {
        // int n = cost.size(), m = cost[0].size();
        // vector<int> min_cost(m, INT_MAX);
        // // min_cost 最小代价，令第一分组到第二分组的最小代价
        // for (int j = 0; j < m; j++) {
        //     for (auto &c : cost) {
        //         min_cost[j] = min(min_cost[j], c[j]);
        //     }
        // }
        // // 记忆化搜索
        // vector<vector<int>> memo(n, vector<int>(1 << m, INT_MAX));

        // function<int(int, int)> dfs = [&](int i, int j) -> int {
        //     if (i < 0) {
        //         // i < 0 代表枚举结束
        //         int res = 0;
        //         for (int k = 0; k < m; k++) {
        //             if (j >> k & 1) { // 第二组的点 k 没有连接， 去第一组找一个最小的点进行连接
        //                 res += min_cost[k];
        //             }
        //         }
        //         return res;
        //     }
        //     // 记忆化维护
        //     int &res = memo[i][j];
        //     if (res != INT_MAX) return res;
        //     // 遍历所有的 第二组数据，找到代价最小的数使得 第一组的 i 节点能够和 第二组进行相连
        //     for (int k = 0; k < m; k++) {
        //         res = min(res, dfs(i - 1, j & ~(1 << k)) + cost[i][k]);
        //     }
        //     return res;
        // };
        // return dfs(n - 1, (1 << m) - 1);

        // int n = cost.size(), m = cost[0].size();
        // vector<int> minCost(m, INT_MAX);
        // // 维护一个最小的代价值，这个代价值使得第二组的节点与第一组节点连接的最小代价
        // for (int j = 0; j < m; j++) {
        //     for (auto &c : cost) {
        //         minCost[j] = min(minCost[j], c[j]);
        //     }
        // }
        // // 使用 f 数组保证记忆化过程，去除递推
        // vector<vector<int>> f(n + 1, vector<int>(1 << m));
        // // 初始化首要条件
        // for (int j = 0; j < 1 << m; j++) {
        //     for (int k = 0; k < m; k++) {
        //         if (j >> k & 1) {
        //             f[0][j] += minCost[k];
        //         }
        //     }
        // }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < 1 << m; j++) {
        //         int res = INT_MAX;
        //         for (int k = 0; k < m; k++) {
        //             res = min(res, f[i][j & ~(1 << k)] + cost[i][k]);
        //         }
        //         f[i + 1][j] = res;
        //     }
        // }
        // return f[n][(1 << m) - 1];

        // 继续优化

        int m = cost[0].size(), f[1 << m];
        f[0] = 0;
        // 遍历第二个组内的元素
        for (int j = 0; j < m; j++) {
            int mn = INT_MAX;
            for (auto &c : cost) {
                mn = min(mn, c[j]);
            }
            int bit = 1 << j; // j 这个位置的值被占用
            // 获取 mask ，这个 mask 可能是位置上面的
            for (int mask = 0; mask < bit; mask++) {
                f[bit | mask] = f[mask] + mn;
            }
        }

        for (auto &row : cost) {
            for (int j = (1 << m) - 1; j >= 0; j--) {
                int res = INT_MAX;
                for (int k = 0; k < m; k++) {
                    res = min(res, f[j & ~(1 << k)] + row[k]);
                }
                f[j] = res;
            }
        }
        return f[1 << m - 1];
    }
};