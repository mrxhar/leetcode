#include <vector>
using namespace std;

class Solution {
public:
    int minCount(vector<int> &coins) {
        auto f = [&](int i) -> int {
            return i / 2 + i % 2;
        };
        int ans = 0;
        for (auto c : coins) {
            ans += f(c);
        }
        return ans;
    }
};