#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // 使用单调栈，这个栈需要单调减
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }

        vector<vector<int>> dp(d, vector<int>(n, INT_MAX));
        // 需要第一天的值
        int s = INT_MIN;
        for (int j = 0; j < n; j++) {
            s = max(s, jobDifficulty[j]);
            dp[0][j] = s;
        }
        // 这时候我们开始一天天弄
        for (int i = 1; i < d; i++) {
            // 第 i 天
            // 使用一个单调栈维护之前最大的那个代价，这个代价是 i-1 天的，这样我们就只需要判断转移即可，是否这个代价可以包含后面知道第 j 的任务
            vector<pair<int, int>> st;
            for (int j = i; j < n; j++) {
                // 从 i 任务开始，这样之前的天数，每天一个任务
                int mnj = dp[i - 1][j - 1];  // 获取前面的任务最小值，知道代价大于j 天的位置，因为这样，j个任务才能包括前面的任务，不修改总代价
                while (!st.empty() && jobDifficulty[st.back().first] <= jobDifficulty[j]) {
                    // 这个时候 j 个任务可以包含之前所有小于 j 个任务的值
                    mnj = min(mnj, st.back().second);
                    st.pop_back();
                }
                dp[i][j] = mnj + jobDifficulty[j];
                if (!st.empty()) {
                    // 里面还有值，这时候就代表前面有一个比当前任务代价大的，这时候尝试一下，这个任务是否可以把当前任务 j 包含进去，看看任务的代价是否更低了
                    dp[i][j] = min(dp[i][j], dp[i][st.back().first]);
                }
                // 将当前的任务压入栈，因为这时候栈顶元素一定大于 当前任务的代价，
                st.push_back({j, mnj});  // 栈里面的元素登记的是昨天的任务代价，并不是今天的代价，因为我们栈是求取最小的昨天代价，将其归并到今天任务j中
            }
        }
        return dp.back().back();
    }
};