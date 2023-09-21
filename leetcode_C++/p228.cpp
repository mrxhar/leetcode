

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        int pre = 0;
        vector<string> ans;
        if (nums.size() == 0) {
            return ans;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] != 1) {
                // 不连续，需要进行添加
                if (pre == i - 1) {
                    // 单独的一个数字
                    ans.push_back(to_string(nums[pre]));
                } else {
                    ans.push_back(to_string(nums[pre]) + "->" + to_string(nums[i - 1]));
                }
                pre = i;
            }
        }
        // 最后一个数字还需要再进行判断
        if (pre < nums.size() - 1) {
            ans.push_back(to_string(nums[pre]) + "->" + to_string(nums.back()));
        } else if (pre < nums.size()) {
            ans.push_back(to_string(nums[pre]));
        }

        return ans;
    }
};