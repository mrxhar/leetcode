#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
#include <climits>
#include <cmath>

class Solution {
public:
        int giveGem(vector<int> &gem, vector<vector<int>> &operations) {
                // 模拟
                int mn = INT_MAX, ma = INT_MIN;
                for (auto op : operations) {
                        int s = gem[op[0]] / 2;
                        gem[op[0]] = gem[op[0]] - s;
                        gem[op[1]] = gem[op[1]] + s;
                }
                // 最多和最少的差
                mn = *min_element(gem.begin(), gem.end());
                ma = *max_element(gem.begin(), gem.end());
                return ma - mn;
        }
};