/*
@Author: mrxhar
@Date:   2023-09-13 10:28:42
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/minimum-falling-path-sum-ii/description/?envType=daily-question&envId=2023-09-13
*/
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int mn = 0, mn2 = 0, mnj = -1;
        for (int i = 0; i < n; i++) {
            int cmn = INT_MAX, cmn2 = INT_MAX, cmnj = -1;
            for (int j = 0; j < n; j++) {
                int cur = grid[i][j] + ((j == mnj) ? mn2 : mn);

                if (cur < cmn) {
                    cmn2 = cmn;
                    cmn = cur;
                    cmnj = j;
                } else if (cur < cmn2) {
                    cmn2 = cur;
                }
            }
            mn = cmn, mn2 = cmn2, mnj = cmnj;
        }
        return mn;
    }
};