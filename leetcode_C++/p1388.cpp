#include <vector>
#include <cstring>
using namespace std;
class Solution {
public:
    int maxSizeSlices(vector<int> &slices) {
        // 抽象思维主要是需要选择不相邻的 n 个数字
        int n = slices.size() / 3;
        auto g = [&](vector<int> &nums) -> int {
            int m = nums.size();
            int f[m + 1][n + 1];
            memset(f, 0, sizeof(f));

            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    f[i][j] = max(f[i - 1][j], (i >= 2 ? f[i - 2][j - 1] : 0) + nums[i - 1]);
                }
            }
            return f[m][n];
        };

        vector<int> nums(slices.begin(), slices.end() - 1);
        int a = g(nums);
        nums = vector<int>(slices.begin() + 1, slices.end());
        return max(a, g(nums));
    }
};