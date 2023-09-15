/*
@Author: mrxhar
@Date:   2023-08-31 08:04:05
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/minimum-degree-of-a-connected-trio-in-a-graph
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int minTrioDegree(int n, vector<vector<int>> &edges)
    {
        // 遍历可以吗
        // 由于节点之间相连，会有重复的，需要除以三
        vector<unordered_set<int>> g(n); // 有向图
        vector<int> degree(n);
        vector<vector<int>> h(n);

        for (auto &&edge : edges)
        {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            g[x].insert(y);
            g[y].insert(x);
            ++degree[x];
            ++degree[y];
        }

        for (auto &&edge : edges)
        {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            if (degree[x] < degree[y] || (degree[x] == degree[y] && x < y))
            {
                h[x].push_back(y);
            }
            else
            {
                h[y].push_back(x);
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            for (int j : h[i])
            {
                for (int k : h[j]) // 有向图
                {
                    if (g[i].count(k)) // 有向图
                    {
                        ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};