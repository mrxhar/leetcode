/*
@Author: mrxhar
@Date:   2023-09-07 11:02:01
@Email:  1337904145@qq.com
@Blog:
*/
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <cmath>
using std::max;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // 记录的时候 使用 string类型记录还是使用别的
        unordered_map<vector<bool>, int> cnt;
        int n = matrix[0].size();
        int ans = 0;
        for (auto& row : matrix) {
            vector<bool> r(n);  // 记录bit位还不够
            for (int j = 0; j < n; j++) {
                r[j] = ((row[j] ^ row[0]));
            }
            ans = max(ans, ++cnt[r]);
        }
        return ans;
    }
};
int main() {
    return 0;
}
