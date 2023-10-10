/*
@Author: mrxhar
@Date:   2023-09-11 11:16:22
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/find-and-replace-in-string/?envType=daily-question&envId=2023-09-11
*/
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets) {
        // 替换和查找
        // 有索引
        int n = s.length();
        vector<pair<string, int>> replace(n, {"", 1}); // 记录 替换位置 的替换字符以及 下一个替换位置的长度
        for (int i = 0; i < indices.size(); i++) {
            // 比较
            if (s.compare(indices[i], sources[i].length(), sources[i]) == 0) {
                replace[indices[i]] = {targets[i], sources[i].length()}; // 替换位置匹配上了，保存替换的位置以及需要替换的源字符长度，second 是为了加速增加的存储字符，如果需要替换的字符 是一个段，这个字段不会进行访问所有的字符，直接跳到下一个需要检查的字符。
            }
        }
        string ans;
        for (int i = 0; i < n; i += replace[i].second) { // i 是源字符串的索引
            if (replace[i].first.empty()) {              // 不需要替换
                ans += s[i];                             // 直接相加
            } else {
                ans += replace[i].first; // 进行替换 变更的是replace 里面的字符，这个字符我们之前预处理过
            }
        }
        return ans;
    }
};