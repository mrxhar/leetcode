/*
@Author: mrxhar
@Date:   2023-08-31 10:04:32
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/check-if-the-sentence-is-pangram/?envType=daily-question&envId=2023-08-31
*/
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
    bool checkIfPangram(string sentence)
    {

        int state = 0;
        for (auto ch : sentence)
        {
            state |= 1 << (ch - 'a');
        }

        return state == (1 << 26) - 1;
    }
};
