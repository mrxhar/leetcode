/*
@Author: mrxhar
@Date:   2023-09-06 08:45:12
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/maximum-value-of-a-string-in-an-array/description/?envType=daily-question&envId=2023-09-06
*/
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <cmath>
using std::max;

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res = 0;
        for (auto str : strs) {
            bool isDigits = true;
            for (auto c : str) {
                if (!isdigit(c)) {
                    isDigits = false;
                    break;
                }
            }
            res = max(res, (int)(isDigits ? stoi(str) : str.length()));
        }
        return res;
    }
};

int main() {
    return 0;
}
