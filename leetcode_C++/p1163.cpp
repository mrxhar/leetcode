/*
@Author: mrxhar
@Date:   2023-09-04 09:56:52
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/last-substring-in-lexicographical-order/?envType=daily-question&envId=2023-09-04
*/
#include <string>
using std::string;

#include <cmath>
using std::max;

class Solution
{
public:
    string lastSubstring(string s)
    {
        // 左右指针
        // 最大字典序字串，一定以最大字典序字符开始，然后比较这些开始的字符
        int i = 0, j = 1, n = s.size();
        // i 记录后缀字符串位置
        // j 进行比较的字符开始位置
        while (j < n)
        {
            int k = 0;
            while (j + k < n && s[i + k] == s[j + k]) // 当等于比较，就k 后移动，移动到一个不能不等的位置，这个k 值很可能是 0
            {
                k++;
            }
            // 这时候替换 i 值，因为这时候 j 开始的字符串字典序更大
            if (j + k < n && s[i + k] < s[j + k])
            {
                int t = i;
                i = j;
                j = max(j + 1, t + k + 1);
            }
            else
            {
                j = j + k + 1;
            }
        }
        return s.substr(i, n - i); // 直到最后都是最大
    }
};