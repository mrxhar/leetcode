/*
@Author: mrxhar
@Date:   2023-09-04 10:27:31
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/make-array-strictly-increasing/?envType=daily-question&envId=2023-09-04
*/
#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

#include <unordered_map>
using std::unordered_map;

#include <functional>
using std::function;

#include <cmath>
using std::min;

// class Solution
// {
// public:
//     int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
//     {
//         // 这个时候
//         // 最小的操作数
//         sort(arr2.begin(), arr2.end()); // 递增
//         int n = arr1.size();
//         unordered_map<int, int> memo[n]; // 记忆化 数组，数组元素是一个字典
//         function<int(int, int)> dfs = [&](int i, int pre) -> int
//         {
//             // 如果i小于0，则返回0
//             if (i < 0) // 终止条件
//             {
//                 return 0;
//             }
//             // 如果pre在memo中，则返回memo中的值 这个时候 pre 是 key 如果之前处理过，这时候就可以直接返回值，second 之前记录好的最小操作数
//             if (auto it = memo[i].find(pre); it != memo[i].end())
//             {
//                 return it->second;
//             }
//             // 如果pre大于arr1中的值，则从arr1中找到这个值，并返回dfs(i-1,arr1[i])
//             // 选择不替换，向下遍历
//             int res = arr1[i] < pre ? dfs(i - 1, arr1[i]) : INT_MAX / 2;
//             // 找到这个值，并且 k 在 arr2 中
//             // 替换，这个小于pre的最大值，替换
//             auto k = lower_bound(arr2.begin(), arr2.end(), pre); // 找到这个值
//             // 如果k不为arr2的开头，则从arr2中找到这个值，并返回dfs(i-1,*--k) + 1
//             if (k != arr2.begin()) // 如果k 存在
//             {
//                 // 这时候向下遍历，res要更新，替换与不替换相比。
//                 res = min(res, dfs(i - 1, *--k) + 1);
//             }
//             // 将pre和res存入memo中
//             return memo[i][pre] = res; // 存入 memo 结果
//         };
//         int ans = dfs(n - 1, INT_MAX);
//         return ans < INT_MAX / 2 ? ans : -1;
//     }
// };

constexpr int INF = 0x3f3f3f3f;

class Solution
{
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        // 不使用 字典
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        arr1.push_back(INF);
        arr1.insert(arr1.begin(), -1);
        int n = arr1.size();
        int m = arr2.size();

        vector<int> dp(n, INF);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr1[i - 1] < arr1[i])
            {
                dp[i] = min(dp[i], dp[i - 1]);
            }
            for (int j = 1; j < i; j++)
            {
                int k = upper_bound(arr2.begin(), arr2.end(), arr1[i - j - 1]) - arr2.begin();
                if (k + j - 1 < m && arr2[k + j - 1] < arr1[i])
                {
                    dp[i] = min(dp[i], dp[i - j - 1] + j);
                }
            }
        }
        return dp[n - 1] == INF ? -1 : dp[n - 1];
    }
};
