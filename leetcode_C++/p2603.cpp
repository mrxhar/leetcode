
#include <vector>
using namespace std;

class Solution {
public:
    int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
        // 排序
        int n = coins.size();
        vector<vector<int>> g(n);
        // 入度
        vector<int> deg(n, 0);

        for (auto edge : edges) {
            int i = edge[0];
            int j = edge[1];
            g[i].push_back(j);
            g[j].push_back(i);
            ++deg[i];
            ++deg[j];
        }

        int leftEdges = n - 1;
        // 拓扑排序
        vector<int> q;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1 && coins[i] == 0) {
                q.push_back(i);
            }
        }
        while (!q.empty()) {
            leftEdges--;
            int x = q.back();
            q.pop_back();
            for (int y : g[x]) {
                if (--deg[y] == 1 && coins[y] == 0) {
                    q.push_back(y);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1 && coins[i]) {
                q.push_back(i);
            }
        }
        // 遍历叶子节点
        leftEdges -= q.size();
        for (int x : q) {
            for (int y : g[x]) {
                if (--deg[y] == 1) {
                    leftEdges--;
                }
            }
        }
        return max(leftEdges * 2, 0);
    }
};