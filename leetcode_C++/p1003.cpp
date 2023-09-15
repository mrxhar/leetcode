/*
@Author: mrxhar
@Date:   2023-09-13 11:10:57
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions/description/?envType=daily-question&envId=2023-09-13
*/
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        for (char c : s) {
            if (c > 'a' && (i == 0 || c - s[--i] != 1)) {
                // 逻辑合在一起，如果为 b c 但是栈为空， 或者 c 和栈顶的元素不是差一位
                // 这里还进行了一个弹出栈的操作
                return false;
            }
            // 入栈
            if (c < 'c') {
                s[i++] = c;
            }
        }
        return i = 0;
    }
};