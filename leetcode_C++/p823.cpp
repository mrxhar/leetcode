/*
@Author: mrxhar
@Date:   2023-09-02 09:18:44
@Email:  1337904145@qq.com
@Blog:
*/

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// class Solution
// {
// public:
//     int numFactoredBinaryTrees(vector<int> &arr)
//     {
//         sort(arr.begin(), arr.end());
//         int n = arr.size();
//         vector<long long> dp(n);
//         long long res = 0, mod = 1e9 + 7;
//         for (int i = 0; i < n; i++)
//         {
//             dp[i] = 1;
//             // 找寻叶子节点
//             for (int left = 0, right = i - 1; left <= right; left++)
//             {
//                 while (right >= left && (long long)arr[left] * arr[right] > arr[i])
//                 {
//                     right--;
//                 }
//                 if (right >= left && (long long)arr[left] * arr[right] == arr[i])
//                 {
//                     if (left != right)
//                     {
//                         dp[i] = (dp[i] + dp[left] * dp[right] * 2) % mod;
//                     }
//                     else
//                     {
//                         dp[i] = (dp[i] + dp[left] * dp[right]) % mod;
//                     }
//                 }
//             }
//             res = (res + dp[i]) % mod;
//         }
//         return res;
//     }
// };
class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<long long> dp(n);
        long long res = 0, mod = 1e9 + 7;
        unordered_map<int, int> vis;
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            // 找寻叶子节点
            // 损失内存使用哈希表
            for (int j = 0; (long long)arr[j] * arr[j] <= arr[i]; j++)
            {
                // j 就可以去寻找是否存在 另一个数在这个哈希表里面
                if (arr[j] * arr[j] == arr[i])
                {
                    dp[i] = (dp[i] + dp[j] * dp[j]) % mod;
                }
                else if (arr[i] % arr[j] == 0 && vis.count((int)arr[i] / arr[j]))
                {
                    int k = vis[(int)arr[i] / arr[j]];
                    dp[i] = (dp[i] + dp[j] * dp[k] * 2) % mod;
                }
            }
            vis[arr[i]] = i; // 添加进去、
            res = (res + dp[i]) % mod;
        }
        return res;
    }
};
