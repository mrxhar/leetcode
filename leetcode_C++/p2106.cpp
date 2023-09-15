#include <vector>
#include <unordered_map>
#include <climits>
#include <cmath>
using namespace std;

// class Solution {
// private:
//         int dfs(unordered_map<int, int> fs, int curpos, int k) {
//                 // 向左向右
//                 if (k < 0) {
//                         return 0;
//                 }
//                 int res = 0;
//                 if (!fs.count(curpos)) {
//                         res = 0;
//                 } else {
//                         res = fs[curpos];
//                 }
//                 fs.erase(curpos);

//                 return res + max(dfs(fs, curpos + 1, k - 1), dfs(fs, curpos - 1, k - 1));
//         };

// public:
//         int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
//                 // 水果状态不好修改，我们使用数组来进行管理
//                 unordered_map<int, int> fs;
//                 int pmx = INT_MIN, pmn = INT_MAX;
//                 for (auto f : fruits) {
//                         int p = f[0], c = f[1];
//                         fs[p] = c;
//                 }
//                 return dfs(fs, startPos, k);
//         }
// };

class Solution {
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
        int left = 0;
        int right = 0;
        int n = fruits.size();
        int sum = 0;
        int ans = 0;

        auto step = [&](int left, int right) -> int {
            // 获取这时候的操作数
            if (fruits[right][0] <= startPos) {
                // right 在左边
                // 一路向左
                return startPos - fruits[left][0];
            } else if (fruits[left][0] >= startPos) {
                // 一路向右边
                return fruits[right][0] - startPos;
            } else {
                // 摇摆
                return min(abs(startPos - fruits[right][0]), abs(startPos - fruits[left][0])) + fruits[right][0] - fruits[left][0];
            }
        };
        // 固定边界
        while (right < n) {
            sum += fruits[right][1];
            while (left <= right && step(left, right) > k) {
                sum -= fruits[left][1]; // left 右移动
                left++;
            }
            ans = max(ans, sum);
            right++;
        }
        return ans;
    }
};
