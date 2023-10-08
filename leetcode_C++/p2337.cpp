/*
@file:
@description:
@author: mrxhar
@date: 2023-10-08 11:00:11
@version: 1.0
@email: mrxhar@163.com
@copyright: Copyright (c) 2023 mrxhar
*/

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool canChange(string start, string target) {
        // 只需要判断次序即可
        // L 不可能在右边存在字符的情况下仍可以向左移动，相同的是 R也是如此
        // 还需要判断 同时匹配的 L 是否 target 的 L 在 源字符串的左侧，R是否在右侧即可
        if (start.size() != target.size()) {
            return false;
        }
        int n = start.size();

        int startIndex = 0, targetIndex = 0;
        // 寻找字符存在的位置
        while (startIndex < n && targetIndex < n) {
            // 找到第一个字符
            while (start[startIndex] == '_') {
                startIndex++;
            }
            while (target[targetIndex] == '_') {
                targetIndex++;
            }
            // 找到了 存在的字符
            // 判断字符是否相等
            if (start[startIndex] != target[targetIndex]) return false;
            // 相等情况下，我们需要进行分析
            if (start[startIndex] == 'L' && target[targetIndex] == 'L' && startIndex < targetIndex) return false;
            if (start[startIndex] == 'R' && target[targetIndex] == 'R' && startIndex > targetIndex) return false;
            startIndex++;
            targetIndex++;
        }

        // 还需要判断剩下的字符是否存在 L R
        while (startIndex < n) {
            if (start[startIndex] != '_') return false;
            startIndex++;
        }

        while (targetIndex < n) {
            if (target[targetIndex] != '_') return false;
            targetIndex++;
        }
        return true;
    }
};