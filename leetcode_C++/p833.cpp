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
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        // 替换和查找
        // 有索引
        int n = s.length();
        vector<pair<string, int>> replace(n, {"", 1}); // 这个记录了需要替换的字符和长度
        // 对应位置是否替换，以及替换的字符
        for (int i = 0; i < indices.size(); i++) {
            // 比较
            if (s.compare(indices[i], sources[i].length(), sources[i]) == 0) {
                replace[indices[i]] = {targets[i], sources[i].length()}; // 长度为源字符的长度，决定我们下次替换时候的位置
            }
        }
        string ans; // 返回的值
        for (int i = 0; i < n; i += replace[i].second) {
            if (replace[i].first.empty()) { // 为空时候，不需要替换，直接加上 原字符
                ans += s[i];
            } else {
                ans += replace[i].first; // 不为空进行替换
            }
        }
        return ans;
    }
};