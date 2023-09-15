/*
@Author: mrxhar
@Date:   2023-09-10 10:20:39
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/greatest-sum-divisible-by-three/description/?envType=daily-question&envId=2023-09-10
*/
#include <vector>
using std::vector;
#include <numeric>
using std::accumulate;
#include <algorithm>
using std::max;
#include <string.h>

#include <functional>
using std::function;

// class Solution {
// public:
//     int maxSumDivThree(vector<int>& nums) {
//         // 贪心，选择合适的值并且排序
//         int s = accumulate(nums.begin(), nums.end(), 0);
//         if (s % 3 == 0) {
//             return s;
//         }
//         vector<int> a[3];
//         for (int x : nums) {
//             a[x % 3].push_back(x);
//         }
//         sort(a[1].begin(), a[1].end());
//         sort(a[2].begin(), a[2].end());

//         // 确保 a[1] 是 a[1] 是主要剩余的那个集中的部分
//         if (s % 3 == 2) {
//             swap(a[1], a[2]);
//         }
//         // 含有则剔除最小的一个既可以
//         int ans = a[1].size() ? s - a[1][0] : 0;
//         // 如果上面的已经剔除了最小的一个 i这时候应该已经是 3 的倍数了
//         if (a[2].size() > 1) {
//             ans = max(ans, s - a[2][0] - a[2][1]); // 这一步只是确保是 3 的倍数，如果上面那个并没有剩余值，则这时候 ans 还是 0 我们可以 进一步获取
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int maxSumDivThree(vector<int>& nums) {
//         // 递归洗发
//         int n = nums.size(), memo[n][3];  // 记忆化搜索
//         memset(memo, -1, sizeof(memo));   // 都填入 -1
//         function<int(int, int)> dfs = [&](int i, int j) -> int {
//             if (i < 0) {
//                 return j ? INT_MIN : 0;
//             }
//             int& res = memo[i][j];  // 使用引用，这样可以更改缓存里面的数据
//             if (res != -1)
//                 return res;
//             return res = max(dfs(i - 1, j), dfs(i - 1, (j + nums[i]) % 3) + nums[i]);
//         };
//         return dfs(n - 1, 0);
//     }
// };

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // 动态规划
        int f[2][3];
        f[0][1] = INT_MIN;
        f[0][2] = INT_MIN;
        f[0][0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 3; j++) {
                // 状态更新
                f[(i + 1) % 2][j] = max(f[i % 2][j], f[i % 2][(j + nums[i]) % 3] + nums[i]);
            }
        }
        return f[(nums.size()) % 2][0];
    }
};