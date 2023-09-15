/*
@Author: mrxhar
@Date:   2023-09-13 08:41:50
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/check-knight-tour-configuration/?envType=daily-question&envId=2023-09-13
*/
#include <unordered_set>
#include <vector>
using std::vector;
using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0)
        {
            return false;
        }
        
        int n = grid.size();
        vector<pair<int, int>> p(n * n, pair<int, int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                p[grid[i][j]] = {i, j};
            }
        }
        for (int i = 1; i < n * n; i++) {
            int x = abs(p[i].first - p[i - 1].first), y = abs(p[i].second - p[i - 1].second);
            if (x * y != 2) {
                return false;
            }
        }
        return true;
    }
};