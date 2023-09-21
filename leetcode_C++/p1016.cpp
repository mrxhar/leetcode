#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        if (n == 1) return s.find('1') != string::npos; // 能够找到 1

        int m = s.length();
        int k = 31 - __builtin_clz(n); // 最低位 0 长度
        // 区间长度进行判断，如果
        if (m < max(n - (1 << k) + k + 1, 1 << (k - 1) + k - 1)) {
            return false;
        }

        // 检查长度 为 k 的子树组是否全有
        auto check = [&](int k, int lower, int upper) -> bool {
            if (lower > upper) {
                return true;
            }

            unordered_set<int> seen;

            int mask = (1 << (k - 1)) - 1;                // 全 1
            int x = stoi(s.substr(0, k - 1), nullptr, 2); // 子数组的数 滑动窗口初始值
            // 滑动
            for (int i = k - 1; i < m; i++) {
                x = ((x & mask) << 1) | (s[i] - '0'); // 出进
                if (lower <= x && x <= upper) {
                    seen.insert(x); // 符合条件，添加进入
                }
            }
            return seen.size() == upper - lower + 1;
        };

        return check(k, n / 2 + 1, (1 << k) - 1) && check(k + 1, 1 << k, n);
    }
};