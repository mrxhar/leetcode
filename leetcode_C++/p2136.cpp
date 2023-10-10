#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
        // 排序，优先进入生长时间长的
        int n = plantTime.size();
        vector<int> index(n);
        for (int i = 0; i < n; i++) {
            index[i] = i;
        }
        sort(index.begin(), index.end(), [&](int i, int j) { return growTime[i] > growTime[j]; });
        int ans = 0;
        int work = 0;
        for (int i = 0; i < n; i++) {
            // 工作，向前，开花时间
            work += plantTime[index[i]];
            ans = max(ans, work + growTime[index[i]]);
        }
        return ans;
    }
};