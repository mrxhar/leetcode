#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    static constexpr int mod = 1e9 + 7;
    int sumDistance(vector<int> &nums, string s, int d) {
        // 如碰
        int n = nums.size();
        vector<long long> pos(n); // 记录结束后的位置
        for (int i = 0; i < n; i++) {
            pos[i] = (long long)nums[i] + (s[i] == 'L' ? -d : d);
        }
        sort(pos.begin(), pos.end());
        long long res = 0;
        for (int i = 1; i < n; i++) {
            res += 1ll * (pos[i] - pos[i - 1]) * i % mod * (n - i) % mod;
            res %= mod;
        }
        return res;
    }
};