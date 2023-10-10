#include <cmath>

class Solution {
public:
    int pivotInteger(int n) {
        // 数学解法
        int x = std::sqrt((n + 1) * n / 2);
        return x * 2 == n * (n + 1) ? x : -1;
    }
};