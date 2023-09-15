/*
@Author: mrxhar
@Date:   2023-09-03 10:58:11
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/can-make-palindrome-from-substring/description/?envType=daily-question&envId=2023-09-03
*/
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <array>
using std::array;

class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        // 前缀和数组
        int n = s.length(), q = queries.size();
        int sum[n + 1]; // 二维vector,固定array
        for (int i = 0; i < n; i++)
        {
            int bit = 1 << (s[i] - 'a');
            sum[i + 1] = sum[i] ^ bit; // 记录的奇偶 0 表示偶 1 表示 奇
        }
        vector<bool> ans(q);
        for (int i = 0; i < q; i++)
        {
            auto &query = queries[i];
            int left = query[0], right = query[1], k = query[2], m = 0;

            m = __builtin_popcount(sum[right + 1] ^ sum[left]); // 奇数个数

            ans[i] = m / 2 <= k;
        }
        return ans;
    }
};