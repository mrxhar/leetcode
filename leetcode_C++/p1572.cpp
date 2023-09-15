/*
@Author: mrxhar
@Date:   2023-09-13 10:44:23
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/matrix-diagonal-sum/?envType=daily-question&envId=2023-09-13
*/
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += (mat[i][i] + mat[i][n - i - 1]);
        }
        return res - (n % 2) ? mat[n / 2][n / 2] : 0;
    }
};