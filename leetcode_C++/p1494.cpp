
#include <vector>
#include <cstring>
#include <functional>
#include <climits>
using namespace std;

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k) {
        int pre1[n];
        memset(pre1, 0, sizeof(pre1));
        for (auto &r : relations) {
            pre1[r[1] - 1] |= 1 << (r[0] - 1); // 位记录前置课程，优化空间
        }

        int u = (1 << n) - 1; // 全集
        int memo[1 << n];     // 记忆

        memset(memo, -1, sizeof(memo));
        function<int(int)> dfs = [&](int i) -> int {
            if (i == 0) return 0; // 所有都已经学习过了
            int &res = memo[i];   // 需要返回的值
            if (res != -1) return res;
            int i1 = 0, ci = u ^ i; // li 代表可以学习的课程  ci 代表 u 与 当前 未学课程的差，0 就是 还没学习的课程
            for (int j = 0; j < n; j++) {
                // 遍历没有学习过的课程 判断 pre1[j] | ci 是否可以进行学习 pre1[j] 的前置课程 ci 都进行过学习。  只有 ci 包含 pre1[j] 才可以学习 j 这门课程
                if (i >> j & 1 && (pre1[j] | ci) == ci) {
                    i1 |= 1 << j; // 更新当前新学的课程
                }
            }
            if (__builtin_popcount(i1) <= k) // 符合条件 全部学习
                return res = dfs(i ^ i1) + 1;
            res = INT_MAX;
            // 因为 可学习的课程大于 k
            for (int j = i1; j; j = (j - 1) & i1) // 学习部分课程，不学习所有的 il 课程，我们只在其中学习 k 个
            {
                if (__builtin_popcount(j) == k)
                    res = min(res, dfs(i ^ j) + 1);
            }
            return res;
        };
        return dfs(u); // 遍历全集
    }
};