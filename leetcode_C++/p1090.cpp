
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit) {
        // 贪心，其实相当于每组里面选择最大的数
        // 需要有一个存储值，存储选择的组的个数和一个和
        // 当然需要先排序
        int n = values.size();
        vector<int>
            id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) {
            return values[i] > values[j];
        });

        int ans = 0, choose = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n && choose < numWanted; ++i) {
            // 再选一个
            int label = labels[id[i]];
            // 能不能进行选择
            if (cnt[label] == useLimit) {
                continue;
            }
            // 进行选择
            ans += values[i];
            ++choose;
            ++cnt[label];
        }
        return ans;
    }
};