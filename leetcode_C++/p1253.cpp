/*
@Author: mrxhar
@Date:   2023-09-08 10:42:18
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix/description/?envType=daily-question&envId=2023-09-08
*/
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans(2, vector<int>(colsum.size(), 0));
        int n = colsum.size();
        for (int i = 0; i < n; i++) {
            if (upper < 0 || lower < 0) {
                return vector<vector<int>>();
            }
            if (colsum[i] == 2) {
                ans[0][i] = 1;
                ans[1][i] = 1;
                upper--;
                lower--;
            } else if (colsum[i] == 1) {
                if (upper > lower) {
                    ans[0][i] = 1;
                    upper--;
                } else {
                    ans[1][i] = 1;
                    lower--;
                }
            }
        }
        return (lower == 0 && upper == 0) ? ans : vector<vector<int>>();
    }
};

int main() {
    return 0;
}
