#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution {
public:
    int flipgame(vector<int> &fronts, vector<int> &backs) {
        // 我们需要知道有哪些数并且知道最小的数，这时候我们还需要排除不可能的数，正反面一样
        int n = fronts.size();
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                s.insert(fronts[i]);
            }
            // 添加进一个数
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!s.count(fronts[i])) {
                res = min(res, fronts[i]);
            }
            if (!s.count(backs[i])) {
                res = min(res, backs[i]);
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};