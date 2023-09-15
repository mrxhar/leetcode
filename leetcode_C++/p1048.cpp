/*
@Author: mrxhar
@Date:   2023-09-02 11:10:38
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/longest-string-chain/solutions/?envType=daily-question&envId=2023-09-02
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <ssp>
using namespace std;

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        int ret = 0;
        unordered_map<string, int> cnt;
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });
        for (string word : words)
        {
            cnt[word] = 1;
            for (int i = 0; i < words.size(); i++)
            {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (cnt.count(prev))
                {
                    cnt[word] = max(cnt[word], cnt[prev] + 1);
                }
            }

            ret = max(ret, cnt[word]);
        }
        return ret;
    }
};

const int N = 1001;
int din[N], dp[N];

class Solution2
{
public:
    unordered_map<int, vector<int>> graph;
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), [&](string &a, string &b)
             { return a.size() < b.size(); });
        function<bool(int, int)> check = [&](int i, int j)
        {
            int leni = words[i].size(), lenj = words[j].size();
            int i1 = 0, i2 = 0;
            for (; i2 < lenj; i2++)
            {
                if (words[i][i1] == words[j][i2])
                    i1++;
            }
            return i1 == leni;
        };
        memset(din, 0, sizeof(din));
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int l1 = words[i].size(), l2 = words[j].size();
                if (l2 - l1 != 1)
                    continue;
                if (check(i, j))
                {
                    graph[i].push_back(j);
                    din[j]++;
                }
            }
        }
        memset(dp, 0, sizeof(dp));
        int ans = 1;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (!din[i])
            {
                q.push(i);
                dp[i] = 1;
            }
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int nxt : graph[cur])
            {
                dp[nxt] = max(dp[nxt], dp[cur] + 1);
                ans = max(ans, dp[nxt]);
                if (--din[nxt] == 0)
                    q.push(nxt);
            }
        }
        return ans;
    }
};